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
{ }

const std::shared_ptr<Id> ArrayExpr::id() const
{ return m_id; }

const std::shared_ptr<Expr> ArrayExpr::size() const
{ return m_size; }

const std::shared_ptr<Expr> ArrayExpr::value() const
{ return m_val; }

bool ArrayExpr::checkSemantic( Scope& scope, Report& report )
{
    bool ok = true;

    auto type = scope.getType( *id() );
    if ( type == nullptr )
    {
        // If there is no type.
        report.error( *this, "There is no type named %s", id()->c_str() );
        ok = false;
    }
    else
    {
        auto array_type = std::dynamic_pointer_cast<ArrayType>( type );
        if ( array_type == nullptr )
        {
            // If the type is not an array type.
            report.error( *this,
                          "The type %s is not an array type",
                          type->typeName().c_str() );
            ok = false;
        }
        else
        {
            ok = value()->checkSemantic( scope, report) and ok;

            if ( not sameType( array_type->type(), { value() } ) )
            {
                // If not the same type of array and value.
                report.error( *this, "The type of array and value mismatch" );
                ok = false;
            }
        }
    }

    // Check the semantic of the size
    ok = size()->checkSemantic( scope, report ) and ok;

    if ( not sameType( scope.getType("int"), { size() } ) )
    {
        report.error(*this, "The size is not of type int");
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
