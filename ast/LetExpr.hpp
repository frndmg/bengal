#ifndef LETEXPR_HPP
#define LETEXPR_HPP

#include "DeclarationList.hpp"
#include "ExprSeqExpr.hpp"
#include "RValue.hpp"

namespace ast
{

class LetExpr : public RValue
{
public:
    LetExpr( const std::shared_ptr<DeclarationList>& scope,
             const std::shared_ptr<ExprSeqExpr>&     expr_seq,
             const Position&                         pos = {0, 0, 0, 0} );

private:
    std::shared_ptr<DeclarationList> m_scope;
    std::shared_ptr<ExprSeqExpr>     m_expr_seq;

    // Node interface
public:
    virtual bool checkSemantic( Scope& scope, Report& report ) override;

    // Node interface
public:
    virtual operator std::string() const override
    {
        return "LetExpr( " + static_cast<std::string>( *m_scope ) + ", "
               + static_cast<std::string>( *m_expr_seq ) + " )";
    }
};

} // ast namespace

#endif // LETEXPR_HPP
