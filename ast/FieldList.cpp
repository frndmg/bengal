#include "FieldList.hpp"

using namespace ast;

bool FieldList::checkSemantic(Scope &scope, Report &report)
{
    bool ok = true;
    for ( auto& x : *this )
        ok = x->checkSemantic( scope, report ) and ok;
    return ok;
}
