//
// Created by frnd on 12/30/16.
//

#ifndef BENGAL_SCOPE_HPP
#define BENGAL_SCOPE_HPP

#include <llvm/IR/Type.h>
#include <map>

namespace semantic
{

class Scope : public std::map< std::string, std::shared_ptr<llvm::Type> >, private std::vector< Scope >
{
public:
    Scope(const std::shared_ptr<Scope>& parent = nullptr)
    {
        m_parent = parent;
    }

    std::shared_ptr<Scope> beginScope()
    {
        return std::make_shared<Scope>(& (*this) );
    }

    void endScope()
    {
        if (not empty())
            pop_back();
    }

private:
    std::shared_ptr<Scope> m_parent;
};

} // semantic namespace

#endif //BENGAL_SCOPE_HPP
