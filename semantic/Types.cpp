#include "Types.hpp"


namespace std
{

template <>
shared_ptr<semantic::IntType> make_shared()
{
    static std::shared_ptr<semantic::IntType> int_type;
    return int_type;
}

template <>
shared_ptr<semantic::StringType> make_shared()
{
    static std::shared_ptr<semantic::StringType> string_type;
    return string_type;
}

template <>
shared_ptr<semantic::NilType> make_shared()
{
    static std::shared_ptr<semantic::NilType> nil_type;
    return nil_type;
}

template <>
shared_ptr<semantic::NoneType> make_shared()
{
    static std::shared_ptr<semantic::NoneType> none_type;
    return none_type;
}

}
