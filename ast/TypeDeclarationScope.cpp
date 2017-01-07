#include "TypeDeclarationScope.hpp"


using namespace ast;


bool TypeDeclarationScope::checkSemantic(Node::Scope& scope, Node::Report& report)
{
    for ( auto& type : *this ) // For every types in this scope
    {
        auto& type_name = type.first;
        // If this type is already defined in the global scope
        if ( scope.getType( type_name ) != nullptr )
        {
            // TODO: Report error
            // Type `type_name` already defined

            continue;
        }
        bool well_defined_type = true;
        for ( auto& type_depend : *type.second->typeDepends() ) // For every types that this `type` depends
        {
            // If `type_depend` isn't in the current scope and the global scope
            if ( find( type_depend ) == end() and
                 scope.getType( type_depend ) == nullptr )
            {
                well_defined_type = false;
                // TODO: Report error
                // Type `type_depend` doesn't exist
            }
        }
    }

    // Check cyclic definitions

    // TODO: Improve the implementation
    for ( auto& type : *this )
    {
        auto& type_name = type.first;
        std::unordered_set<std::string> marked;

        if ( hasCycle( marked, type_name ) )
        {
            // TODO: Report error
            // Cyclic definition
        }
    }

    // Create every types in the scope
}

bool TypeDeclarationScope::hasCycle(std::unordered_set<std::string>& touched, const std::string& x)
{
    if ( touched.find( x ) != touched.end() )
        return true;
    auto& type = ( *this )[x];
    if ( type->isArrayDeclaration() or type->isAliasDeclaration() )
        return touched.insert( x ), hasCycle( touched, type->typeName() );
    return false;
}
