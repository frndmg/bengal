//
// Created by frnd on 1/4/17.
//

#ifndef BENGAL_TYPES_HPP
#define BENGAL_TYPES_HPP

#include <string>
#include <map>

namespace semantic
{

struct IntType;
struct StringType;
struct NilType;

struct Type
{
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
    ArrayType(const std::string& typeName, Type* type) : Type( typeName ), m_type( type ) {}

private:
    Type* m_type;
};

struct StructType : Type, std::map<std::string, std::string>
{
    StructType(const std::string& typeName,
               std::initializer_list<value_type> init) :
            Type( typeName ), map( init ) {}
};

struct AliasType : Type
{
    AliasType(const std::string& typeName, const std::string& typeNameAlias) :
            Type( typeName ),
            m_typeNameAlias( typeNameAlias ) {}

private:
    std::string m_typeNameAlias;
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
