#ifndef EXPRSEQEXPR_HPP
#define EXPRSEQEXPR_HPP

#include "RValue.hpp"

namespace ast
{

class ExprSeqExpr
        : public RValue,
          public std::vector<std::shared_ptr<Expr> >
{
    typedef std::vector<std::shared_ptr<Expr> > vector;

public:
    ExprSeqExpr( const Position& pos = { 0, 0, 0, 0 } );

    // Node interface
public:
    virtual bool checkSemantic( Scope& scope, Report& report ) override;

    virtual operator std::string() const override;
};

} // ast namespace

#endif // EXPRSEQEXPR_HPP
