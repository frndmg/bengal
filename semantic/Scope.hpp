//
// Created by frnd on 12/30/16.
//

#ifndef BENGAL_SCOPE_HPP
#define BENGAL_SCOPE_HPP

#include <llvm/IR/Type.h>
#include <map>

namespace semantic
{
template <typename T>
using ptr = std::shared_ptr<T>;

class Scope : public std::map< std::string, std::shared_ptr<llvm::Type> >, private std::vector< std::shared_ptr<Scope> >
{

    using map = std::map< std::string, std::shared_ptr<llvm::Type> >;
    using vector = std::vector< ptr<Scope> >;

public:
    Scope(ptr<Scope> parent = nullptr) :
          map(),
          vector(),
          m_parent(parent)
    {
    }

    std::shared_ptr<Scope> beginScope()
    {
        return std::make_shared<Scope>( (ptr<Scope>)this );
    }

    void endScope()
    {
        if (not vector::empty())
            pop_back();
    }

private:
    ptr<Scope> m_parent;
};

} // semantic namespace

#endif //BENGAL_SCOPE_HPP
