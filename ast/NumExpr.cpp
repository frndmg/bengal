#include "NumExpr.hpp"

using namespace ast;

NumExpr::NumExpr()
{

}

llvm::Value *NumExpr::generateCode()
{
    return llvm::ConstantInt::get(llvm::getGlobalContext(), llvm::APInt(32, m_val));
}
