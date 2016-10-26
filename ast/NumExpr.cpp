#include "NumExpr.hpp"

using namespace ast;

NumExpr::NumExpr()
{

}

void NumExpr::generateCode()
{
    llvm::ConstantInt::get(llvm::getGlobalContext(), llvm::APInt(32, m_val));
}
