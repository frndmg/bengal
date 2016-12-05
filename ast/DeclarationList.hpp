#ifndef DECLARATIONLIST_HPP
#define DECLARATIONLIST_HPP

#include "Node.hpp"
#include "DeclarationScope.hpp"

#include <vector>
#include <memory>

namespace ast
{

class DeclarationList : public Node, private std::vector<std::shared_ptr<DeclarationScope>>
{
public:
    DeclarationList();

    using std::vector<std::shared_ptr<DeclarationScope>>::push_back;
};

} // ast namespace

#endif // DECLARATIONLIST_HPP
