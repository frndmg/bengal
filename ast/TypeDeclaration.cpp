#include "TypeDeclaration.hpp"


using namespace ast;

TypeDeclaration::TypeDeclaration(const std::shared_ptr<Id>& id,
                                 const std::shared_ptr<TypeFields>& fields) :
        m_id( id ),
        m_fields( fields )
{
}

TypeDeclaration::TypeDeclaration(const std::shared_ptr<Id>& id,
                                 const std::shared_ptr<Id>& type,
                                 bool isArray) :
        m_id( id ),
        m_type( type ),
        m_isArray( isArray )
{
}

const std::string& TypeDeclaration::typeName() const
{
    return m_id->id();
}

bool TypeDeclaration::checkSemantic(Scope& scope, Report& report)
{
}

std::shared_ptr<std::vector<std::string> > TypeDeclaration::typeDepends() const
{
    static auto vector = std::make_shared<std::vector<std::string> >();
    if ( vector->empty() )
        if ( isArrayDeclaration() or isAliasDeclaration() )
            vector->push_back( m_type->id() );
        else
            for ( auto& x : *m_fields )
                vector->push_back( x->type()->id() );
    return vector;
}
