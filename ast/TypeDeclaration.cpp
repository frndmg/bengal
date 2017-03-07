#include "TypeDeclaration.hpp"

using namespace ast;

TypeDeclaration::TypeDeclaration(
        const std::shared_ptr<Id>& id,
        const std::shared_ptr<TypeFields>& fields )
        : m_id( id ), m_type( nullptr ), m_fields( fields ), m_isArray( false )
{
}

TypeDeclaration::TypeDeclaration(
        const std::shared_ptr<Id>& id,
        const std::shared_ptr<Id>& type,
        bool isArray )
        : m_id( id ), m_type( type ), m_fields( nullptr ), m_isArray( isArray )
{
}

bool TypeDeclaration::checkSemantic( Scope& scope, Report& report )
{
    // Empty. All the semantic check is done in TypeDeclarationScope
}

std::shared_ptr<std::vector<std::string> > TypeDeclaration::typeDepends() const
{
    static auto vector = std::make_shared<std::vector<std::string> >();
    if ( vector->empty() )
        if ( isArrayDeclaration() or isAliasDeclaration() )
            vector->push_back( *m_type );
        else
            for ( auto& x : *m_fields )
                vector->push_back( *x->type() );
    return vector;
}

const std::shared_ptr<Id>& TypeDeclaration::id() const
{ return m_id; }

const std::shared_ptr<Id>& TypeDeclaration::type() const
{ return m_type; }

const std::shared_ptr<TypeFields>& TypeDeclaration::fields() const
{
    return m_fields;
}

TypeDeclaration::operator std::string() const
{
    std::string s;

    s += "TypeDeclaration( ";
    s += "id: " + *id();
    if ( isTypeDeclaration() )
        s += ", fields: " + static_cast<std::string>( *fields() );
    else
    {
        s += ", type: " + *type();
        if ( isArrayDeclaration() )
            s += ", array";
        else
            s += ", alias";
    }
    s += " )";

    return s;
}
