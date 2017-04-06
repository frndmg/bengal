#ifndef FIELDLIST_HPP
#define FIELDLIST_HPP

#include "Field.hpp"
#include "Node.hpp"

namespace ast
{

class FieldList : public Node, private std::vector< std::shared_ptr<Field> >
{
public:
    using vector = std::vector< std::shared_ptr< Field > >;
    using vector::push_back;
    using vector::begin;
    using vector::end;
    using vector::size;
    using vector::operator[];

    using vector::value_type;

    using vector::iterator;
    using vector::const_iterator;

    // Node interface
public:
    virtual bool checkSemantic(Scope &scope, Report &report) override;
};

} // ast namespace

#endif // FIELDLIST_HPP
