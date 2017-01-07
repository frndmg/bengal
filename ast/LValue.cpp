#include "LValue.hpp"
#include <algorithm>


using namespace ast;

LValue::LValue()
{
}

LValue::LValue(std::shared_ptr<Id>& id) :
        m_id( id )
{
}

LValue::LValue(std::shared_ptr<Expr>& index) :
        m_index( index )
{
}

bool LValue::checkSemantic(Node::Scope& scope, Node::Report& report)
{
    if ( isSimple() )
        return true;

    auto type    = scope.getType( *m_id );
    auto current = std::shared_ptr<LValue>( this );
    while ( not current->isSimple() )
    {
        // TODO: Resolve the alias type
        if ( current->m_next->isMemberAccesor() )
        {
            if ( Expr::StructType* s_type = dynamic_cast<StructType*>(type.get()) )
            {
                auto val = std::find_if( s_type->begin(), s_type->end(),
                                         [=](auto& x)
                                         {
                                             return x.first == *current->m_next->m_id;
                                         } );
                if ( val == s_type->end() )
                {
                    // TODO: Report error
                    // There is no member named `current->m_next->m_id->id()`
                    return false;
                }
                type = val->second;
            }
            else
            {
                // TODO: Report error
                // The member `type()` of `current` is not StructType
            }
        }
        else if ( current->m_next->isIndexAccesor() )
        {
            if ( Expr::ArrayType* a_type = dynamic_cast<ArrayType*>(type.get()) )
            {
                if ( not current->m_next->checkSemantic( scope, report ) )
                    return false;

                type = a_type->type();
            }
            else
            {
                // TODO: Report Error
                // The member `type()` of `current` is not ArrayType
            }
        }
        current = current->m_next;
    }

    setType( type );

    return true;
}

void LValue::setNext(const std::shared_ptr<LValue>& next)
{
    if ( not next->isSimple() )
        m_next = next;
}
