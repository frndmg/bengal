#ifndef TYPEFIELDS_HPP
#define TYPEFIELDS_HPP

#include "Node.hpp"
#include "TypeField.hpp"

namespace ast
{

class TypeFields :
        public Node, public std::vector<std::shared_ptr<TypeField> >
{
public:
    TypeFields();

    // Node interface
public:
    virtual bool checkSemantic(Scope &scope, Report &report) override;
};

} // ast namespace

#endif // TYPEFIELDS_HPP
