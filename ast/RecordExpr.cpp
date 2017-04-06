#include "RecordExpr.hpp"

using namespace ast;

RecordExpr::RecordExpr(
        const std::shared_ptr<Id>& id,
        const std::shared_ptr<FieldList>& fields,
        const Position& pos )
        : RValue( pos )
        , m_id( id )
        , m_fields( fields )
{ }


bool RecordExpr::checkSemantic( Scope& scope, Report& report )
{
    bool ok = true;

    auto type = scope.getType( *id() );
    if ( type == nullptr )
    {
        report.error( *this, "There is no type named %s", id()->c_str() );
        ok = false;
    }
    else
    {
        auto struct_type = std::dynamic_pointer_cast<StructType>( type );
        if ( struct_type == nullptr )
        {
            report.error( *this,
                          "The type %s is not a struct",
                          type->typeName().c_str() );
            ok = false;
        }
        else
        {
            auto struct_body = struct_type->body();
            auto fields = *this->fields();

            // Check the semantic of the fields.
            ok = fields.checkSemantic( scope, report ) and ok;

            if ( struct_body.size() != fields.size() )
            {
                report.error( *this, "The quantity of parameters mismatch" );
                ok = false;
            }
            else
            {
                auto it_i = struct_body.begin();
                auto it_j = fields.begin();

                for ( ; it_i != struct_body.end(); it_i++, it_j++ )
                {
                    if ( it_i->first != *( **it_j ).id() )
                    {
                        report.error( *this, "The name of the field mismatch" );
                        ok = false;
                    }
                    if ( it_i->second != (**it_j).expr()->type() )
                    {
                        report.error( *this, "The type of the field mismatch" );
                        ok = false;
                    }
                }

            }

        }
    }

    return ok;
}
