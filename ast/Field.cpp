#include "Field.hpp"

using namespace ast;

Field::Field(
        const std::shared_ptr<Id>& id,
        const std::shared_ptr<Expr>& expr,
        const Position& pos )
        : Node()
        , m_id( id )
        , m_expr( expr )
{ }


bool ast::Field::checkSemantic( Scope& scope, Report& report )
{
    return expr()->checkSemantic( scope, report );
}
