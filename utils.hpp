#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <memory>

template<typename T>
using ptr = std::shared_ptr<T>;

template<typename T>
using ptr_list = std::vector<ptr<T>>;

template<typename T, typename ...Args>
std::shared_ptr<T> single_town(const Args&... args)
{
    // No parameters in the constructor
    static std::shared_ptr<T> internal_ptr = std::make_shared<T>( args... );
    return internal_ptr;
}

struct Position
{
    size_t init_line;
    size_t init_column;
    size_t end_line;
    size_t end_column;

    operator std::string() const
    {
        return "(" + std::to_string(init_line) + ", " + std::to_string(init_column) + ")";
    }

    friend std::ostream& operator<<(std::ostream& out, const Position& pos)
    {
        return out << static_cast<std::string>( pos );
    }
};

#endif // UTILS_HPP
