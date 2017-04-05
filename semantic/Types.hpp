#ifndef BENGAL_TYPES_HPP
#define BENGAL_TYPES_HPP

#include <string>
#include <vector>
#include <memory>

namespace semantic
{

struct IntType;
struct StringType;
struct NilType;
struct NoneType;

}

namespace std
{

template <>
shared_ptr<semantic::IntType> make_shared<semantic::IntType>()
{
    static std::shared_ptr<semantic::IntType> int_type;
    return int_type;
}

template <>
shared_ptr<semantic::StringType> make_shared<semantic::StringType>()
{
    static std::shared_ptr<semantic::StringType> string_type;
    return string_type;
}

template <>
shared_ptr<semantic::NilType> make_shared<semantic::NilType>()
{
    static std::shared_ptr<semantic::NilType> nil_type;
    return nil_type;
}

template <>
shared_ptr<semantic::NoneType> make_shared<semantic::NoneType>()
{
    static std::shared_ptr<semantic::NoneType> none_type;
    return none_type;
}

}

namespace semantic
{

struct Type
{
    virtual ~Type()
    { }

    const std::string& typeName() const
    {
        return m_typeName;
    }

protected:
    Type( const std::string& typeName )
            : m_typeName( typeName )
    { }

private:
    std::string m_typeName;
};

struct IntType
        : Type
{
    IntType()
            : Type( "int" )
    { }
};

struct StringType
        : Type
{
    StringType()
            : Type( "string" )
    { }
};

struct NilType
        : Type
{
    NilType()
            : Type( "nil" )
    { }
};

struct NoneType
        : Type
{
    NoneType()
            : Type( "none" )
    { }
};

struct ArrayType
        : Type
{
    ArrayType( const std::string& typeName, const std::shared_ptr<Type>& type )
            : Type( typeName ), m_type( type )
    { }

    const std::shared_ptr<Type>& type() const
    { return m_type; }

    void setType( const std::shared_ptr<Type>& type )
    { m_type = type; }

private:
    std::shared_ptr<Type> m_type;
};

struct StructType
        : Type
{
    typedef std::vector<std::pair<std::string, std::shared_ptr<Type> > > vector;
    typedef vector::value_type value_type;

    StructType(
            const std::string& typeName,
            std::initializer_list<value_type> init = { } )
            : Type( typeName ), vector( init )
    { }

    const vector& body()
    { return m_body; }

private:
    vector m_body;
};

struct AliasType
        : Type
{
    AliasType(
            const std::string& typeName,
            const std::shared_ptr<Type>& typeAlias )
            :
            Type( typeName ), m_typeAlias( typeAlias )
    { }

    const std::shared_ptr<Type>& typeAlias() const
    {
        return m_typeAlias;
    }

    void setTypeAlias( const std::shared_ptr<Type>& typeAlias )
    {
        m_typeAlias = typeAlias;
    }

private:
    std::shared_ptr<Type> m_typeAlias;
};

struct FunctionType
        : Type
{
    typedef std::vector<std::pair<std::string, std::shared_ptr<Type> > > vector;
    typedef vector::value_type value_type;

    FunctionType(
            const std::shared_ptr<Type>& return_type,
            const std::string& type_name,
            std::initializer_list<value_type> init = { } )
            : Type( type_name ), m_params( init )
    { }

public:
    const vector& params()
    { return m_params; }

    const std::shared_ptr<Type> return_type()
    { return m_return_type; }

private:
    vector m_params;
    std::shared_ptr<Type> m_return_type;
};

struct ProcedureType
        : FunctionType
{
    ProcedureType(
            const std::string& typeName,
            std::initializer_list<value_type> init = { } )
            : FunctionType( std::make_shared<NoneType>(), typeName, init )
    { }
};

}

#endif //BENGAL_TYPES_HPP
