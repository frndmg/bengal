#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <memory>

template<typename T>
using ptr = std::shared_ptr<T>;

template<typename T>
using ptr_list = std::vector<ptr<T>>;

template<typename T>
ptr<T> single_town()
{
    // No parameters in the constructor
    static ptr<T> interal_ptr = std::make_shared<T>();
    return interal_ptr;
}

#endif // UTILS_HPP
