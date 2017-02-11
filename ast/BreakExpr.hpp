//
// Created by frnd on 12/30/16.
//

#ifndef BENGAL_BREAKEXPR_HPP
#define BENGAL_BREAKEXPR_HPP

#include "Expr.hpp"

namespace ast
{

class BreakExpr : public Expr
{
public:
    BreakExpr(const Position& pos = { 0, 0, 0, 0 });

    // Node interface
public:
    virtual bool checkSemantic(Scope &scope, Report &report) override;
    virtual operator std::string() const override;
};

} // ast namespace


#endif //BENGAL_BREAKEXPR_HPP
