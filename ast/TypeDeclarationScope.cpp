#include "TypeDeclarationScope.hpp"

using namespace ast;
namespace sem = semantic;

// Create a type from TypeDeclaration
template <typename Type>
std::shared_ptr<Type> createType( const std::shared_ptr<TypeDeclaration>& type )
{
    return std::make_shared<Type>( *type->id(), nullptr );
}

// Specification for StructType
template <>
std::shared_ptr<sem::StructType>
createType( const std::shared_ptr<TypeDeclaration>& type )
{
    return std::make_shared<sem::StructType>( *type->id() );
}

template <typename Type>
std::shared_ptr<Type> createType( const std::shared_ptr<TypeDeclaration>& type,
                                  sem::Scope& scope )
{
    const auto id = *type->id();
    // The actual type from the scope.
    // Can be null if never created
    auto from_scope = scope.getTypeDef( id );
    auto type_def   = std::dynamic_pointer_cast<Type>( from_scope );
    if ( type_def == nullptr ) {
        type_def            = createType<Type>( type );
        scope.typeDef()[id] = type_def;
    }
    return type_def;
}

bool TypeDeclarationScope::checkSemantic( Node::Scope&  scope,
                                          Node::Report& report )
{
    std::set<std::string> well_defined_types;

    for ( auto& type : *this ) // For every types in this scope
    {
        auto& type_name = type.first;
        // If this type is already defined in the global scope
        if ( scope.getTypeDef( type_name ) != nullptr ) {
            // TODO: Report error
            // Type `type_name` already defined

            continue;
        }
        bool well_defined_type = true;
        for ( auto& type_depend :
              *type.second
                   ->typeDepends() ) // For every types that this `type` depends
        {
            // If `type_depend` isn't in the current scope and the global scope
            if ( find( type_depend ) == end()
                 and scope.getTypeDef( type_depend ) == nullptr )
            {
                well_defined_type = false;
                // TODO: Report error
                // Type `type_depend` doesn't exist
            }
        }
        if ( well_defined_type ) well_defined_types.insert( type_name );
    }

    // Check cyclic definitions

    // TODO: Improve the implementation
    for ( auto& type : *this ) {
        auto&                 type_name = type.first;
        std::set<std::string> marked;

        if ( hasCycle( marked, type_name ) ) {
            well_defined_types.erase( type_name );
            // TODO: Report error
            // Cyclic definition
        }
    }

    // Create all well defined types in the `scope.typeDef`
    for ( auto& x : well_defined_types ) {
        auto& type = ( *this )[x];
        if ( type->isAliasDeclaration() ) {
            auto x               = createType<sem::AliasType>( type, scope );
            auto find_alias_type = unordered_map::find( *type->type() );
            if ( find_alias_type != unordered_map::end() ) {
                auto& alias_type = find_alias_type->second;
                if ( alias_type->isAliasDeclaration() )
                    x->setTypeAlias(
                        createType<sem::AliasType>( alias_type, scope ) );
                else if ( alias_type->isArrayDeclaration() )
                    x->setTypeAlias(
                        createType<sem::ArrayType>( alias_type, scope ) );
                else if ( alias_type->isTypeDeclaration() )
                    x->setTypeAlias(
                        createType<sem::StructType>( alias_type, scope ) );
            }
        }
        else if ( type->isArrayDeclaration() )
        {
            auto x               = createType<sem::ArrayType>( type, scope );
            auto find_array_type = unordered_map::find( *type->type() );
            if ( find_array_type != unordered_map::end() ) {
                auto& array_type = find_array_type->second;
                if ( array_type->isAliasDeclaration() )
                    x->setType(
                        createType<sem::AliasType>( array_type, scope ) );
                else if ( array_type->isArrayDeclaration() )
                    x->setType(
                        createType<sem::ArrayType>( array_type, scope ) );
                else if ( array_type->isTypeDeclaration() )
                    x->setType(
                        createType<sem::StructType>( array_type, scope ) );
            }
        }
        else if ( type->isTypeDeclaration() )
        {
            auto x = createType<sem::StructType>( type, scope );
            for ( auto& x_member : *type->fields() ) {
                auto find_member_type
                    = unordered_map::find( *x_member->type() );
                if ( find_member_type != unordered_map::end() ) {
                    auto& member_type = find_member_type->second;
                    if ( member_type->isAliasDeclaration() )
                        x->push_back( {*member_type->id(),
                                       createType<sem::AliasType>( member_type,
                                                                   scope )} );
                    else if ( member_type->isArrayDeclaration() )
                        x->push_back( {*member_type->id(),
                                       createType<sem::ArrayType>( member_type,
                                                                   scope )} );
                    else if ( member_type->isTypeDeclaration() )
                        x->push_back( {*member_type->id(),
                                       createType<sem::StructType>( member_type,
                                                                    scope )} );
                }
            }
        }
    }

    return well_defined_types.size() == size();
}

bool TypeDeclarationScope::hasCycle( std::set<std::string>& touched,
                                     const std::string&     x )
{
    if ( not std::get<1>( touched.insert( x ) ) ) return true;
    auto& type = ( *this )[x];
    if ( type->isArrayDeclaration() or type->isAliasDeclaration() )
        return hasCycle( touched, *type->id() );
    return false;
}

TypeDeclarationScope::operator std::string() const
{
    static std::string s;

    // Only compute it once
    if ( s.empty() ) {
        s += "DeclarationScope( ";
        for ( const auto& x : *this )
            s += static_cast<std::string>( *x.second ) + ", ";
        s += " )";
    }

    return s;
}
