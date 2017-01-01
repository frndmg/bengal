#ifndef TYPEFILELD_HPP
#define TYPEFILELD_HPP

#include "Node.hpp"
#include "Id.hpp"

namespace ast
{

class TypeField : public Node
{
public:
    TypeField(ptr<Id> id, ptr<Id> type);

private:
    ptr<Id> m_id;
    ptr<Id> m_type;

    // Node interface
public:
    virtual bool checkSemantic(Scope &scope, Report &report) override;
};

} // ast namespace

#endif // TYPEFILELD_HPP
