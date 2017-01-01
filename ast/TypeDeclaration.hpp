#ifndef TYPEDECLARATION_HPP
#define TYPEDECLARATION_HPP

#include "Id.hpp"
#include "Node.hpp"
#include "TypeFields.hpp"

namespace ast
{

class TypeDeclaration : public Node
{
public:
    TypeDeclaration(ptr<Id> id, ptr<Id> type, bool isArray = false);
    TypeDeclaration(ptr<Id> id, ptr<TypeFields> fields);

private:
    ptr<Id> m_id;
    ptr<Id> m_type;
    ptr<TypeFields> m_fields;
    bool m_isArray;

    // Node interface
public:
    virtual bool checkSemantic(Scope &scope, Report &report) override;
};

} // ast namespace

#endif // TYPEDECLARATION_HPP
