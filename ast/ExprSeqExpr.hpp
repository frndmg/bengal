#ifndef EXPRSEQEXPR_HPP
#define EXPRSEQEXPR_HPP

#include "RValue.hpp"

namespace ast
{

class ExprSeqExpr : public RValue, private ptr_list<Expr>
{

public:

    // Vector public members
    using ptr_list<Expr>::push_back;
    using ptr_list<Expr>::begin;
    using ptr_list<Expr>::end;
    using ptr_list<Expr>::size;
    using ptr_list<Expr>::operator[];
};

} // ast namespace

#endif // EXPRSEQEXPR_HPP
