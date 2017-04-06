#include "RecordExpr.hpp"

using namespace ast;

RecordExpr::RecordExpr(
        const std::shared_ptr<Id>& id,
        const std::shared_ptr<FieldList>& fields,
        const Position& pos )
        : RValue( pos )
        , m_id( id )
        , m_fields( fields )
{ }


bool ast::RecordExpr::checkSemantic( Scope& scope, Report& report )
{
}
