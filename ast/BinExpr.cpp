#include "BinExpr.hpp"


using namespace ast;

BinExpr::BinExpr(const std::shared_ptr<Expr>& lexpr,
                 const std::shared_ptr<Expr>& rexpr,
                 Operator op,
                 const Position& pos) :
        RValue( pos ),
        m_lexpr( lexpr ),
        m_rexpr( rexpr ),
        m_op( op )
{
}

bool BinExpr::checkSemantic(Node::Scope& scope, Node::Report& report)
{
    bool check = m_lexpr->checkSemantic( scope, report ) and
                 m_rexpr->checkSemantic( scope, report );

    setType( single_town<IntType>() );
    switch ( m_op )
    {
        case MUL:
        case DIV:
        case ADD:
        case SUB:
        case AND:
        case OR:
            // All this operations are over integers
            return check and sameType( single_town<IntType>(), { m_lexpr, m_rexpr } );
        case GREATER:
        case LESS:
        case GEQ:
        case LEQ:
            // All this operations are over integers and strings
            return check and ( sameType( single_town<IntType>(), { m_lexpr, m_rexpr } ) or
                               sameType( single_town<StringType>(), { m_lexpr, m_rexpr } ) );
        case EQUAL:
        case NEQUAL:
            return check and not sameType( single_town<NoneType>(), { m_lexpr } ) and
                   sameType( { m_lexpr, m_rexpr } );
        default:
            return check;
    }
}
