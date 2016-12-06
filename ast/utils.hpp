#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <memory>

namespace ast
{

template<typename T>
using ptr = std::shared_ptr<T>;

template<typename T>
using ptr_list = std::vector<ptr<T>>;

} // ast namespace

#endif // UTILS_HPP
