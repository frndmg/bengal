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

    // Every type has all its dependencies in order
    std::set<std::string> well_defined_types;
    checkTypeDepend( well_defined_types, scope, report );

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

void TypeDeclarationScope::checkUniqueName(
        Node::Scope& scope,
        Node::Report& report )
{
    typedef map::size_type size_type;

    for ( size_type i = 0; i < bucket_count(); ++i )
    {
        // The size of the bucket ``i``
        size_type bucket_size_i = bucket_size( i );

        // Iterator to the beginning of bucket ``i``
        auto it = begin( i );

        if ( bucket_size_i > 1 )
        {
            auto type_name = begin( i )->first.c_str();
            // Multiple definitions of type ``type_name``
            report.error( *this,
                          TYPEDECL_TYPE_ALREADY_DEFINED,
                          type_name );
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

void TypeDeclarationScope::checkTypeDepend(
        std::set<std::string>& well_defined_types,
        Node::Scope& scope,
        Node::Report& report )
{
    for ( auto& value : *this )
    {
        // Name of the current type
        const auto& type_name = value.first;

        // Value of the current type
        const auto& type = value.second;

        // Is a well defined type
        bool well_defined_type = true;

        // Get all types that `type` depends on.
        std::vector< Id > type_depends;
        type->typeDepends( std::back_inserter( type_depends ) );

        for ( auto& type_depend : type_depends )
            if ( find( type_depend ) == end()
                 and scope.getTypeDefOf( type_depend ) == nullptr )
            {
                well_defined_type = false;
                report.error( *this,
                              "Type `%s` does not exist.",
                              type_depend.c_str() );
            }
        if ( well_defined_type )
            well_defined_types.insert( type_name );
    }
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
    std::string s;

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
