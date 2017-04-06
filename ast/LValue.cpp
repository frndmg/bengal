#include "LValue.hpp"

#include <algorithm>

using namespace ast;

LValue::LValue( const Position& pos )
        : RValue( pos )
{ }

LValue::LValue(
        const std::shared_ptr<Id>& id,
        const Position& pos )
        : RValue( pos )
        , m_id( id )
{ }

LValue::LValue( const std::shared_ptr<Expr>& index, const Position& pos )
        : RValue( pos )
        , m_index( index )
{ }

void LValue::setNext( const std::shared_ptr<LValue>& next )
{ m_next = next; }

bool LValue::isMemberAccessor()
{ return bool( m_id ); }

bool LValue::isIndexAccessor()
{ return bool( m_index ); }

bool LValue::isEmpty()
{ return not bool( m_next ); }

const std::shared_ptr<Id>& LValue::id() const
{ return m_id; }

const std::shared_ptr<Expr>& LValue::index() const
{ return m_index; }

const std::shared_ptr<LValue>& LValue::next() const
{ return m_next; }

bool LValue::checkSemantic( Scope& scope, Report& report )
{
    if ( not isMemberAccessor() )
    {
        // This is a paranoiac check, this is never syntactically correct.
        report.error( *this, "Invalid lvalue format" );
        return false;
    }

    // Type of current variable.
    // It can be nullptr if the variable does not exist.
    auto variable_type = scope.getVariable( *m_id );

    if ( next()->isEmpty() )
    {
        // Only a lvalue with an empty next.
        // The type is the same as the variable.
        setType( variable_type );
        return true;
    }

    bool ok = next()->checkSemantic( variable_type, scope, report );
    setType( variable_type );
    return ok;
}

bool LValue::checkSemantic(
        std::shared_ptr<Type>& parent_type,
        Scope& scope,
        Report& report )
{
    if ( isEmpty() )
        return true;

    if ( isMemberAccessor() )
    {
        auto struct_type = std::dynamic_pointer_cast<StructType>( parent_type );
        if ( struct_type == nullptr )
        {
            // Not valid cast. Current parent_type is not a StructType.
            report.error( *this, LVALUE_INVALID_MEMBER_ACCESSOR );
            parent_type = nullptr;
            return false;
        }

        const auto& body = struct_type->body();
        auto it = std::find_if( body.begin(), body.end(),
                                [=]( const auto& x )
                                {
                                    return x.first == *this->id();
                                } );
        if ( it == body.end() )
        {
            report.error( *this,
                          LVALUE_MISSING_MEMBER,
                          struct_type->typeName().c_str(),
                          id()->c_str() );
            parent_type = nullptr;
            return false;
        }

        parent_type = it->second;
    }
    else if ( isIndexAccessor() )
    {
        auto array_type = std::dynamic_pointer_cast<ArrayType>( parent_type );
        if ( array_type == nullptr )
        {
            report.error( *this,
                          LVALUE_INVALID_INDEX_ACCESSOR );

            parent_type = nullptr;
            return false;
        }

        // Check the semantic of the index.
        index()->checkSemantic( scope, report );
        if ( not sameType( scope.getType( "int" ), { index() } ) )
        {
            report.error( *this,
                          LVALUE_INDEX_NOT_A_NUMBER );

            // Assume that the index is valid and continue checking.
            // Not do this.
            // parent_type = nullptr;
        }

        parent_type = array_type->type();
    }
    else
    {
        // Paranoiac check, this will never happen.
        parent_type = nullptr;
    }

    return next()->checkSemantic( parent_type, scope, report );
}

LValue::operator std::string() const
{
    // TODO: Implement this
    return "LValue()";
}
