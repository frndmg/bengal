#ifndef TYPEFILELD_HPP
#define TYPEFILELD_HPP

#include "Node.hpp"
#include "Id.hpp"


namespace ast
{

class TypeField : public Node
{
public:
    TypeField(const std::shared_ptr<Id>& id, const std::shared_ptr<Id>& type);

    const std::shared_ptr<Id>& id() const;

    const ptr<ast::Id>& type() const;

private:

    std::shared_ptr<Id> m_id;
    std::shared_ptr<Id> m_type;

    // Node interface
public:
    virtual bool checkSemantic(Scope& scope, Report& report) override;
};
} // ast namespace

#endif // TYPEFILELD_HPP
