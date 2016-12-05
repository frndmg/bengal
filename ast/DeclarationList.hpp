#ifndef DECLARATIONLIST_HPP
#define DECLARATIONLIST_HPP

#include "Node.hpp"
#include "DeclarationScope.hpp"

#include <vector>

namespace ast
{

class DeclarationList : public Node, private std::vector<ptr<DeclarationScope>>
{
public:
    DeclarationList();

    using std::vector<ptr<DeclarationScope>>::push_back;
};

} // ast namespace

#endif // DECLARATIONLIST_HPP
