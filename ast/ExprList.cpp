#include "ExprList.hpp"

using namespace ast;


ExprList::ExprList(const Position& pos) :
    Node( pos ),
    vector()
{
}

bool ExprList::checkSemantic(Scope &scope, Report &report)
{
    bool ok = true;
    for(auto& x : *this)
        ok = x->checkSemantic( scope, report ) and ok;
    return ok;
}

ExprList::operator std::string() const
{
    std::string s("ExprList( ");

    // The first element
    auto i = this->begin();

    if ( i != this->end() )
    {
        s += static_cast<std::string>( **(i++) );
        // The rest
        for (; i != this->end(); i++)
            s += ", " + static_cast<std::string>( **i );
    }

    return s += " )";
}
