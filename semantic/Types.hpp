//
// Created by frnd on 1/4/17.
//

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

struct Type
{
    virtual ~Type() {}

    const std::string& typeName() const
    {
        return m_typeName;
    }

protected:
    Type(const std::string& typeName) : m_typeName( typeName ) {}

private:
    std::string m_typeName;
};

struct IntType : Type
{
    IntType() : Type( "Int32" ) {}
};

struct StringType : Type
{
    StringType() : Type( "String" ) {}
};

struct NilType : Type
{
    NilType() : Type( "Nil" ) {}
};

struct NoneType : Type
{
    NoneType() : Type( "None" ) {}
};

struct ArrayType : Type
{
    ArrayType(const std::string& typeName, const std::shared_ptr<Type>& type) : Type( typeName ), m_type( type ) {}

    const std::shared_ptr<Type>& type() const { return m_type; }

    void setType(const std::shared_ptr<Type>& type) { m_type = type; }

private:
    std::shared_ptr<Type> m_type;
};

struct StructType : Type, std::vector<std::pair<std::string, std::shared_ptr<Type> > >
{
    StructType(const std::string& typeName) :
        Type( typeName ), vector() { }
    StructType(const std::string& typeName,
               std::initializer_list<value_type> init) :
            Type( typeName ), vector( init ) {}
};

struct AliasType : Type
{
    AliasType(const std::string& typeName, const std::shared_ptr<Type>& typeAlias) :
            Type( typeName ),
            m_typeAlias( typeAlias ) {}

    const std::shared_ptr<Type>& typeAlias() const
    {
        return m_typeAlias;
    }

    void setTypeAlias(const std::shared_ptr<Type>& typeAlias)
    {
        m_typeAlias = typeAlias;
    }

private:
    std::shared_ptr<Type> m_typeAlias;
};

struct FunctionType : Type
{
    FunctionType(const std::string& typeName) : Type( typeName ) {}
};

struct ProcedureType : FunctionType
{
    ProcedureType(const std::string& typeName) : FunctionType( typeName ) {}
};

//template <typename Type>
//Type* type(const std::string& typeName);
//
//template <>
//IntType* type<IntType>(const std::string&)
//{
//    static IntType* type = new IntType();
//    return type;
//}
//
//template <>
//ArrayType* type<ArrayType>(const std::string& typeName)
//{
////    ArrayType* arrayType = new ArrayType( typeName );
////    return arrayType;
//}

}

#endif //BENGAL_TYPES_HPP
