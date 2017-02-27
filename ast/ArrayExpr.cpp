#include "ArrayExpr.hpp"

using namespace ast;

ArrayExpr::ArrayExpr(
        const std::shared_ptr<Id>& id,
        const std::shared_ptr<Expr>& size,
        const std::shared_ptr<Expr>& val,
        const Position& pos )
        : RValue( pos )
        , m_id( id )
        , m_size( size )
        , m_val( val )
{
}

bool ArrayExpr::checkSemantic( Scope& scope, Report& report )
{
    bool ok = true;

    // Check if the type exists and if it is of type `ArrayType`
    std::shared_ptr<Type> type;
    if ( ( type = scope.getTypeDef( *m_id ) ) == nullptr )
    {
        // TODO: Report error. Type `*m_id` does not exist
        ok = false;
    }
    std::shared_ptr<ArrayType> array_type;
    if ( ( array_type = std::dynamic_pointer_cast<ArrayType>( type ) ) == nullptr )
    {
        // TODO: Report error. Type `*m_id` is not of type ArrayType
        ok = false;
    }

    // Check the semantic of the `m_size` and `m_val`
    if ( not( m_size->checkSemantic( scope, report ) and
              m_val->checkSemantic( scope, report ) ) )
    {
        // If problems with m_size or m_val
        ok = false;
    }

    // Check the type of `m_size` and `m_val`
    if ( not sameType( scope.getTypeDef( "Int32" ), { m_size } ) )
    {
        // TODO: Report error. Type of `m_size` is not Int32
        ok = false;
    }
    if ( array_type != nullptr and not sameType( array_type->type(), { m_val } ) )
    {
        // TODO: Report error. The Type of the array and the value differs
        ok = false;
    }

    return ok;
}

ArrayExpr::operator std::string() const
{
    return "ArrayExpr( " + *m_id
           + ", " + static_cast<std::string>( *m_size )
           + ", " + static_cast<std::string>( *m_val )
           + " )";
}
