#include "ExprSeqExpr.hpp"

using namespace ast;

ExprSeqExpr::ExprSeqExpr( const Position& pos )
        : RValue( pos )
        , vector()
{ }

bool ExprSeqExpr::checkSemantic( Scope& scope, Report& report )
{
    bool ok = true;
    for ( auto& x : *this )
    {
        ok = x->checkSemantic( scope, report ) and ok;
        setType( x->type() );
    }
    return ok;
}

ExprSeqExpr::operator std::string() const
{
    std::string s = "ExprSeqExpr( ";

    // Get the first element
    auto i = this->begin();

    if ( i != this->end() )
    {
        s += static_cast<std::string>( **( i++ ) );
        // The rest
        for ( ; i != this->end(); i++ )
            s += ", " + static_cast<std::string>( **i );
    }

    return s + " )";
}
