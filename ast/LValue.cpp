#include "LValue.hpp"
#include <algorithm>


using namespace ast;

LValue::LValue(const Position& pos) :
    RValue( pos )
{
}

LValue::LValue(std::shared_ptr<Id>& id,
               const Position& pos) :
    RValue( pos ),
    m_id( id )
{
}

LValue::LValue(std::shared_ptr<Expr>& index, const Position& pos) :
    RValue( pos ),
    m_index( index )
{
}

bool LValue::checkSemantic(Node::Scope& scope, Node::Report& report)
{
    if ( isSimple() )
        return true;

    // Type of current member
    auto type    = scope.getTypeOf( *m_id );

    // Current member
    auto current = std::shared_ptr<LValue>( this );

    if ( type == nullptr )
    {
        // TODO: Report error:
        // Current is not simple and it has no type.
        return false;
    }

    bool ok = true;

    do
    {
        // TODO: Resolve the alias type

        // If the next field is a member accesor
        // eg. <id>.<id>

        // For that reason the type of the current member must be
        // StructType.
        if ( current->m_next->isMemberAccesor() )
        {
            // dynamic_cast returns nullptr if there is no way to
            // perform the cast.
            if ( auto s_type = std::dynamic_pointer_cast<StructType>( type ) )
            {
                auto val = std::find_if( s_type->begin(), s_type->end(),
                                         [=](const auto& x)
                                         {
                                             return x.first == *current->m_next->m_id;
                                         } );
                if ( val == s_type->end() )
                {
                    // It has no sence to continue after founding a `current` that
                    // no has the member.

                    // TODO: Report error:
                    // There is no member named `*current->m_next->m_id`
                    return false;
                }
                type = val->second;
            }
            else
            {
                // TODO: Report error
                // The member `type()` of `current` is not StructType
                return false;
            }
        }

        // If current is an index accesor
        // eg. <id>[ <expr> ]
        else if ( current->m_next->isIndexAccesor() )
        {
            if ( auto a_type = std::dynamic_pointer_cast<ArrayType>( type ) )
            {
                if ( not current->m_next->checkSemantic( scope, report ) )
                    ok = false;

                type = a_type->type();
            }
            else
            {
                // TODO: Report Error
                // The member `type()` of `current` is not ArrayType
                return false;
            }
        }

        // Set the next element to inspect
        // The type was already setted
        current = current->m_next;

    } while ( not current->isSimple() );

    setType( type );

    return ok;
}

void LValue::setNext(const std::shared_ptr<LValue>& next)
{
    if ( not next->isSimple() )
        m_next = next;
}
