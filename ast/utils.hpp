#ifndef UTILS_HPP
#define UTILS_HPP

#include <memory>

namespace ast
{

template<typename T>
using ptr = std::shared_ptr<T>;

} // ast namespace

#endif // UTILS_HPP
