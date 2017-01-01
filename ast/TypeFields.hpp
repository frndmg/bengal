#ifndef TYPEFIELDS_HPP
#define TYPEFIELDS_HPP

#include "Node.hpp"
#include "TypeField.hpp"

namespace ast
{

class TypeFields : public Node, private ptr_list<TypeField>
{
public:
    TypeFields();

    using ptr_list<TypeField>::push_back;
    using ptr_list<TypeField>::begin;
    using ptr_list<TypeField>::end;
    using ptr_list<TypeField>::size;

    // Node interface
public:
    virtual bool checkSemantic(Scope &scope, Report &report) override;
};

} // ast namespace

#endif // TYPEFIELDS_HPP
