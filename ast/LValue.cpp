#include "LValue.hpp"
#include <llvm/IR/DerivedTypes.h>

using namespace ast;

LValue::LValue()
{
}

LValue::LValue(std::shared_ptr<Id>& id) :
    m_id(id)
{
}

LValue::LValue(std::shared_ptr<Expr>& index) :
    m_index(index)
{
}

void LValue::setParent(const std::shared_ptr<LValue>& parent)
{
    parent->m_next = std::shared_ptr<LValue>( this );
}

bool LValue::checkSemantic(Node::Scope &scope, Node::Report &report)
{
    throw std::logic_error("LValue::checkSemantic: Not implemented");

    bool check = true;

    auto lvalue_type = scope.getType(m_id->id());

    // If there is no type like `m_id->id()` and it is accessing some member
    // then check = false.
    if (not lvalue_type and not isSimple())
    {
        check = false;
        // TODO: Play with the report
    }

    for (auto lvalue = std::shared_ptr<LValue>( this ); not lvalue->isSimple(); lvalue = lvalue->m_next)
    {
        auto next = lvalue->m_next;
        auto next_type = next->type();

        if (next->isMemberAccesor())
        {
            // when next is member accesor
            if (not lvalue_type->isStructTy())
            {
                check = false;
                // TODO: Play with the report
                // lvalue is not a struct type
                break;
            }

            auto struct_type = static_cast<llvm::StructType*>(lvalue_type);
            auto id = next->m_id->id();

            std::find(struct_type->element_begin(), struct_type->element_end(), nullptr);
        }
        else if (next->isIndexAccesor())
        {
            // when next is index accesor
            next->m_index->checkSemantic(scope, report);
        }
    }

    return check;
}
