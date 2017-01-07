#ifndef TYPEDECLARATION_HPP
#define TYPEDECLARATION_HPP

#include "Id.hpp"
#include "TypeFields.hpp"


namespace ast
{

class TypeDeclaration : public Node
{
public:
    TypeDeclaration(const std::shared_ptr<Id>& id, const std::shared_ptr<Id>& type, bool isArray = false);

    TypeDeclaration(const std::shared_ptr<Id>& id, const std::shared_ptr<TypeFields>& fields);

    bool isTypeDeclaration() const { return bool( m_fields ); }

    bool isArrayDeclaration() const { return bool( m_id ) and bool( m_type ) and m_isArray; }

    bool isAliasDeclaration() const { return bool( m_id ) and bool( m_type ) and not m_isArray; }

    const std::shared_ptr<Id>& typeId() const;

    std::shared_ptr<std::vector<std::string> > typeDepends() const;

    const std::shared_ptr<Id>& type() const
    {
        return m_type;
    }

    const std::shared_ptr<TypeFields>& fields() const
    {
        return m_fields;
    }

private:
    std::shared_ptr<Id>         m_id;
    std::shared_ptr<Id>         m_type;
    std::shared_ptr<TypeFields> m_fields;
    bool                        m_isArray;

    // Node interface
public:
    virtual bool checkSemantic(Scope& scope, Report& report) override;
};
} // ast namespace

#endif // TYPEDECLARATION_HPP
