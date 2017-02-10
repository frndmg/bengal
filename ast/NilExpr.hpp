#ifndef NILEXPR_HPP
#define NILEXPR_HPP

#include "RValue.hpp"

namespace ast
{

class NilExpr : public RValue
{
    // Node interface
public:
    virtual bool checkSemantic(Scope&, Report&) override {
        setType( single_town<NilType>() );
        return true; }
};

} // ast namespace

#endif // NILEXPR_HPP
