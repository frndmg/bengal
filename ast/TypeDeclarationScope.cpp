#include "TypeDeclarationScope.hpp"

#include "type_declaration_utils/type_declaration_utility.hpp"

using namespace ast;

// Create a type from TypeDeclaration
template < typename Type >
std::shared_ptr<Type> createType( const std::shared_ptr<TypeDeclaration>& type )
{
    return std::make_shared<Type>( *type->id(), nullptr );
}

// Specification for StructType
template <>
std::shared_ptr<semantic::StructType>
createType( const std::shared_ptr<TypeDeclaration>& type )
{
    return std::make_shared<semantic::StructType>( *type->id() );
}

template < typename Type >
std::shared_ptr<Type> createType(
        const std::shared_ptr<TypeDeclaration>& type,
        semantic::Scope& scope )
{
    const auto id = *type->id();
    // The actual type from the scope.
    // Can be null if never created
    auto from_scope = scope.getTypeDefOf( id );
    auto type_def = std::dynamic_pointer_cast<Type>( from_scope );
    if ( type_def == nullptr )
    {
        type_def = createType<Type>( type );
        scope.typeDef()[id] = type_def;
    }
    return type_def;
}

bool TypeDeclarationScope::checkSemantic(
        Node::Scope& scope,
        Node::Report& report )
{
    // No more than one type with the same name
    checkUniqueName( scope, report );

    std::set<std::string> well_defined_types;

    for ( auto& type : *this ) // For every types in this scope
    {
        auto& type_name = type.first;

        // If this type is already defined in the global scope
        if ( scope.getTypeDefOf( type_name ) != nullptr )
        {
            // Report the error and go with the next one.
            report.error( *this, TYPEDECL_TYPE_ALREADY_DEFINED, type_name );

            continue;
        }

        bool well_defined_type = true;
        for ( auto& type_depend : *type.second->typeDepends() )
        {
            // If `type_depend` isn't in the current scope and the global scope
            if ( find( type_depend ) == end()
                 and scope.getTypeDefOf( type_depend ) == nullptr )
            {
                well_defined_type = false;
                // TODO: Report error
                // Type `type_depend` doesn't exist
            }
        }
        if ( well_defined_type )
            well_defined_types.insert( type_name );
    }

    // Check cyclic definitions

    // TODO: Improve the implementation
    for ( auto& type : *this )
    {
        auto& type_name = type.first;
        std::set<std::string> marked;

        if ( hasCycle( marked, type_name ) )
        {
            well_defined_types.erase( type_name );
            // TODO: Report error
            // Cyclic definition
        }
    }

    // Create all well defined types in the `scope.typeDef`
    for ( auto& x : well_defined_types )
    {
        auto& type = find( x )->second;
        if ( type->isAliasDeclaration() )
        {
            auto x = createType<semantic::AliasType>( type, scope );
            auto find_alias_type = map::find( *type->type() );
            if ( find_alias_type != map::end() )
            {
                auto& alias_type = find_alias_type->second;
                if ( alias_type->isAliasDeclaration() )
                    x->setTypeAlias(
                            createType<semantic::AliasType>( alias_type,
                                                             scope ) );
                else if ( alias_type->isArrayDeclaration() )
                    x->setTypeAlias(
                            createType<semantic::ArrayType>( alias_type,
                                                             scope ) );
                else if ( alias_type->isTypeDeclaration() )
                    x->setTypeAlias(
                            createType<semantic::StructType>( alias_type,
                                                              scope ) );
            }
        } else if ( type->isArrayDeclaration() )
        {
            auto x = createType<semantic::ArrayType>( type, scope );
            auto find_array_type = map::find( *type->type() );
            if ( find_array_type != map::end() )
            {
                auto& array_type = find_array_type->second;
                if ( array_type->isAliasDeclaration() )
                    x->setType(
                            createType<semantic::AliasType>( array_type,
                                                             scope ) );
                else if ( array_type->isArrayDeclaration() )
                    x->setType(
                            createType<semantic::ArrayType>( array_type,
                                                             scope ) );
                else if ( array_type->isTypeDeclaration() )
                    x->setType(
                            createType<semantic::StructType>( array_type,
                                                              scope ) );
            }
        } else if ( type->isTypeDeclaration() )
        {
            auto x = createType<semantic::StructType>( type, scope );
            for ( auto& x_member : *type->fields() )
            {
                auto find_member_type
                        = map::find( *x_member->type() );
                if ( find_member_type != map::end() )
                {
                    auto& member_type = find_member_type->second;
                    if ( member_type->isAliasDeclaration() )
                        x->push_back( { *member_type->id(),
                                        createType<semantic::AliasType>(
                                                member_type, scope ) } );
                    else if ( member_type->isArrayDeclaration() )
                        x->push_back( { *member_type->id(),
                                        createType<semantic::ArrayType>(
                                                member_type, scope ) } );
                    else if ( member_type->isTypeDeclaration() )
                        x->push_back( { *member_type->id(),
                                        createType<semantic::StructType>(
                                                member_type, scope ) } );
                }
            }
        }
    }

    return well_defined_types.size() == size();
}

bool TypeDeclarationScope::hasCycle(
        std::set<std::string>& touched,
        const std::string& x )
{
    if ( not std::get<1>( touched.insert( x ) ) )
        return true;
    auto& type = find( x )->second;
    if ( type->isArrayDeclaration() or type->isAliasDeclaration() )
        return hasCycle( touched, *type->id() );
    return false;
}

TypeDeclarationScope::operator std::string() const
{
    static std::string s;

    s += "TypeDeclarationScope( ";
    auto i = this->begin();
    if ( i != this->end() )
    {
        s += static_cast<std::string>( *( ( *( i++ ) ).second ) );
        for ( ; i != this->end(); i++ )
            s += ", " + static_cast<std::string>( *( *i ).second );
    }
    s += " )";

    return s;
}

TypeDeclarationScope::TypeDeclarationScope( const Position& pos )
        : DeclarationScope( pos )
        , map()
{ }

void TypeDeclarationScope::checkUniqueName(
        Node::Scope& scope,
        Node::Report& report )
{
    typedef map::size_type size_type;

    for ( size_type i = 0; i < bucket_count(); ++i )
    {
        auto bucket_size_i = bucket_size( i );
        auto it = begin( i );

        if ( bucket_size_i > 1 )
        {
            // Check in the current TypeDeclarationScope
            report.error( *this,
                          TYPEDECL_TYPE_ALREADY_DEFINED,
                          begin( i )->first.c_str() );
        }
        else if ( bucket_size_i == 1 )
        {
            // Check in outer scope
            const auto& type_name = it->first;
            if ( scope.getTypeDefOf( type_name ) != nullptr )
                report.error( *this,
                              TYPEDECL_TYPE_ALREADY_DEFINED,
                              type_name.c_str() );
        }
    }
}
