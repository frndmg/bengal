#include "BinExpr.hpp"

using namespace ast;

BinExpr::BinExpr(
        const std::shared_ptr<Expr>& lexpr,
        const std::shared_ptr<Expr>& rexpr,
        Operator op,
        const Position& pos )
        : RValue( pos )
        , m_lexpr( lexpr )
        , m_rexpr( rexpr )
        , m_op( op )
{ }

bool BinExpr::checkSemantic( Scope& scope, Report& report )
{
    // If the semantic of any of the two expressions is invalid
    if ( not m_lexpr->checkSemantic( scope, report ) or
         not m_rexpr->checkSemantic( scope, report ) )
        return false;

    auto ok = true;
    auto int_type = scope.getType( "int" );
    auto string_type = scope.getType( "string" );
    auto none_type = scope.getType( "none" );

    switch ( m_op )
    {
        case MUL:
        case DIV:
        case ADD:
        case SUB:
        case AND:
        case OR:
            // All this operations are over integers
            if ( not( ok = sameType( int_type, { m_lexpr, m_rexpr } ) ) )
            {
                report.error( *this,
                              " Operands must be of type int, found expressions of type "
                                      "[%s] and [%s]",
                              m_lexpr->type()->typeName().c_str(),
                              m_rexpr->type()->typeName().c_str() );
            }
            break;
        case GREATER:
        case LESS:
        case GEQ:
        case LEQ:
            // All this operations are over integers and strings
            if ( not( ok = ( sameType( int_type, { m_lexpr, m_rexpr } ) or
                             sameType( string_type, { m_lexpr, m_rexpr } ) ) ) )
            {
                report.error( *this,
                              " Operands must be of type int or string, found expressions of type "
                                      "[%s] and [%s]",
                              m_lexpr->type()->typeName().c_str(),
                              m_rexpr->type()->typeName().c_str() );
            }
            break;
        case EQUAL:
        case NEQUAL:
            return ok and
                   not sameType( none_type, { m_lexpr } ) and
                   sameType( { m_lexpr, m_rexpr } );
        default:
            break;
    }

    if ( ok )
        setType( int_type );

    return ok;
}

BinExpr::operator std::string() const
{
    static const std::string ops[]{ "=", "!=", ">", "<", ">=", "<=", "&", "|",
                                    "*", "/", "+", "-" };

    return "BinExpr( "
           + static_cast<std::string>( *m_lexpr )
           + ", " + static_cast<std::string>( *m_rexpr )
           + ", '" + ops[m_op] + "' )";
}
