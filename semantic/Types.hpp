//
// Created by frnd on 1/4/17.
//

#ifndef BENGAL_TYPES_HPP
#define BENGAL_TYPES_HPP

#include <string>

struct Type
{
    Type() { }

    Type(const std::string& typeName) : m_typeName( typeName ) { }

private:
    std::string m_typeName;
};

struct IntType : Type
{
    IntType() : Type( "Int32" ) { }
};

struct StringType : Type
{
    StringType() : Type( "String" ) { }
};

struct NilType : Type
{
    NilType() : Type( "Nil" ) { }
};

struct ArrayType : Type
{
    ArrayType(const std::string& typeName, Type* type) : Type( typeName ), m_type( type ) { }

private:
    Type* m_type;
};

struct StructType : Type
{
    StructType(const std::string& typeName, std::pair< std::string, Type*> members, ...) : Type( typeName ) {  }
};

struct AliasType : Type
{
    AliasType(const std::string& typeName, Type* type) : Type( typeName ), m_type( type ) { }

private:
    Type* m_type;
};

struct FunctionType : Type { };

struct ProcedureType : FunctionType { };

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

void f()
{
//    type<ArrayType>("foo", nullptr);
}

#endif //BENGAL_TYPES_HPP
