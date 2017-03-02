#ifndef TYPEDECLARATION_HPP
#define TYPEDECLARATION_HPP

#include "Id.hpp"
#include "TypeFields.hpp"

namespace ast
{

class TypeDeclaration : public Node
{
public:
    ///////////////
    // Constructors
    ///////////////

    TypeDeclaration( const std::shared_ptr<Id>& id,
                     const std::shared_ptr<Id>& type, bool isArray = false );
    TypeDeclaration( const std::shared_ptr<Id>&         id,
                     const std::shared_ptr<TypeFields>& fields );

    //////////
    // Methods
    //////////

    // Check if the type is
    // Type Declaration
    bool isTypeDeclaration() const { return bool( m_fields ); }
    // Array Declaration
    bool isArrayDeclaration() const
    {
        return bool( m_id ) and bool( m_type ) and m_isArray;
    }
    // Alias Declaration
    bool isAliasDeclaration() const
    {
        return bool( m_id ) and bool( m_type ) and not m_isArray;
    }

    // Show wich types this type depends
    std::shared_ptr<std::vector<std::string> > typeDepends() const;

    /////////////
    // Properties
    /////////////

    const std::shared_ptr<Id>&         id() const;
    const std::shared_ptr<Id>&         type() const;
    const std::shared_ptr<TypeFields>& fields() const;

    // Node interface
public:
    virtual bool checkSemantic( Scope& scope, Report& report ) override;
    virtual operator std::string() const override;

private:
    std::shared_ptr<Id>         m_id;
    std::shared_ptr<Id>         m_type;
    std::shared_ptr<TypeFields> m_fields;
    bool                        m_isArray;
};
} // ast namespace

#endif // TYPEDECLARATION_HPP
