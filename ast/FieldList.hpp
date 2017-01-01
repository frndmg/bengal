#ifndef FIELDLIST_HPP
#define FIELDLIST_HPP

#include "Field.hpp"
#include "Node.hpp"

namespace ast
{

class FieldList : public Node, private ptr_list<Field>
{
public:
    using ptr_list<Field>::push_back;
    using ptr_list<Field>::begin;
    using ptr_list<Field>::end;
    using ptr_list<Field>::size;
    using ptr_list<Field>::operator[];

    // Node interface
public:
    virtual bool checkSemantic(Scope &scope, Report &report) override;
};

} // ast namespace

#endif // FIELDLIST_HPP
