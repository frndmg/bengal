#include "Types.hpp"


namespace std
{

template <>
shared_ptr<semantic::IntType> make_shared()
{
    static semantic::IntType* int_ptr = new semantic::IntType;
    static std::shared_ptr<semantic::IntType> int_type(int_ptr);
    return int_type;
}

template <>
shared_ptr<semantic::StringType> make_shared()
{
    static semantic::StringType* string_ptr = new semantic::StringType;
    static std::shared_ptr<semantic::StringType> string_type(string_ptr);
    return string_type;
}

template <>
shared_ptr<semantic::NilType> make_shared()
{
    static semantic::NilType* nil_ptr = new semantic::NilType;
    static std::shared_ptr<semantic::NilType> nil_type(nil_ptr);
    return nil_type;
}

template <>
shared_ptr<semantic::NoneType> make_shared()
{
    static semantic::NoneType* none_ptr = new semantic::NoneType;
    static std::shared_ptr<semantic::NoneType> none_type(none_ptr);
    return none_type;
}

}
