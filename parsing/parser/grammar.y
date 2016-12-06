%scanner                    ../scanner/scanner.h
%scanner-class-name         Scanner

%target-directory           parser
%filenames                  parser
%parsefun-source            parse.cpp

%baseclass-preinclude       parserPreinclude.hpp

// %expect 1

%start program

%polymorphic
    ARRAYEXPR: std::shared_ptr<ArrayExpr>;
    FIELDLIST: std::shared_ptr<FieldList>;
    NODE: std::shared_ptr<Node>;
    ASSIGNEXPR: std::shared_ptr<AssignExpr>;
    FOREXPR: std::shared_ptr<ForExpr>;
    NUMEXPR: std::shared_ptr<NumExpr>;
    BINEXPR: std::shared_ptr<BinExpr>;
    FUNCTIONCALLEXPR: std::shared_ptr<FunctionCallExpr>;
    RECORDEXPR: std::shared_ptr<RecordExpr>;
    BREAKABLEEXPR: std::shared_ptr<BreakableExpr>;
    FUNCTIONDECLARATION: std::shared_ptr<FunctionDeclaration>;
    RVALUE: std::shared_ptr<RValue>;
    DECLARATION: std::shared_ptr<Declaration>;
    ID: std::shared_ptr<Id>;
    STRINGEXPR: std::shared_ptr<StringExpr>;
    DECLARATIONLIST: std::shared_ptr<DeclarationList>;
    IFEXPR: std::shared_ptr<IfExpr>;
    TYPEDECLARATION: std::shared_ptr<TypeDeclaration>;
    EXPR: std::shared_ptr<Expr>;
    LETEXPR: std::shared_ptr<LetExpr>;
    VARIABLEDECLARATION: std::shared_ptr<VariableDeclaration>;
    EXPRSEQEXPR: std::shared_ptr<ExprSeqExpr>;
    LVALUE: std::shared_ptr<LValue>;
    WHILEEXPR: std::shared_ptr<WhileExpr>;
    FIELD: std::shared_ptr<Field>;
    NILEXPR: std::shared_ptr<NilExpr>;
    DECLARATIONSCOPE: std::shared_ptr<DeclarationScope>;
    FUNCTIONDECLARATIONSCOPE: std::shared_ptr<FunctionDeclarationScope>;
    TYPEDECLARATIONSCOPE: std::shared_ptr<TypeDeclarationScope>;
    TYPEFIELD: std::shared_ptr<TypeField>;
    TYPEFIELDS: std::shared_ptr<TypeFields>;
    EXPRLIST: std::shared_ptr<ExprList>;

%type <EXPR> expr
%type <NUMEXPR> num
%type <BINEXPR> bin_exp
%type <LVALUE> lvalue
%type <DECLARATIONLIST> declaration_list
%type <DECLARATIONSCOPE> declaration_scope
%type <FUNCTIONDECLARATIONSCOPE> function_declaration_scope
%type <TYPEDECLARATIONSCOPE> type_declaration_scope
%type <VARIABLEDECLARATION> variable_declaration
%type <EXPRSEQEXPR> expr_seq _expr_seq
%type <ID> id
%type <TYPEDECLARATION> type_declaration
%type <TYPEFIELD> type_field
%type <TYPEFIELDS> type_fields _type_fields
%type <EXPRLIST> expr_list _expr_list
%type <FIELD> field
%type <FIELDLIST> field_list _field_list
%type <FUNCTIONDECLARATION> function_declaration

%token T_ID T_NUM T_SEMI T_NIL T_STRING T_COMMA T_DOT T_COLON
       T_ARRAY T_BREAK T_DO T_END T_FOR T_FUNCTION T_IF T_IN T_LET T_OF
       T_THEN T_TO T_TYPE T_VAR T_WHILE
       T_LEFT_BRACKET T_RIGHT_BRACKET
       T_LEFT_BRACE T_RIGHT_BRACE
       T_LEFT_PAR T_RIGHT_PAR
%nonassoc T_ASSIGN
%nonassoc T_EQUAL T_NEQUAL T_GREATER T_LESS T_GEQ T_LEQ T_AND T_OR
%left T_PLUS T_MINUS
%left T_TIMES T_DIV
%left T_ELSE
%right UNARY

%%


//////////
// PROGRAM
//////////

program:
    expr EOF
;


/////////////
// EXPRESSION
/////////////

expr:
    T_STRING
|
    num { $$($1); }
|
    T_NIL
|
    lvalue { $$($1); }
|
    T_MINUS expr %prec UNARY
|
    bin_exp
    { $$( $1 ); }
|
    lvalue T_ASSIGN expr
    { $$( std::make_shared<AssignExpr>($1, $3) ); }
|
    // Function call
    id T_LEFT_PAR expr_list T_RIGHT_PAR
    { $$( std::make_shared<FunctionCallExpr>($1, $3) ); }
|
    T_LEFT_PAR expr_seq T_RIGHT_PAR
    { $$($2); }
|
    // Record creation
    id T_LEFT_BRACE field_list T_RIGHT_BRACE
    { $$( std::make_shared<RecordExpr>($1, $3) ); }
|
    // Array creation
    id T_LEFT_BRACKET expr T_RIGHT_BRACKET T_OF expr
    { $$( std::make_shared<ArrayExpr>($1, $3, $6) ); }
|
    T_IF expr T_THEN expr
|
    T_IF expr T_THEN expr T_ELSE expr
|
    T_WHILE expr T_DO expr
|
    T_FOR id T_ASSIGN expr T_TO expr T_DO expr
|
    break
|
    T_LET declaration_list T_IN expr_seq T_END
    {
        $$(std::make_shared<LetExpr>($2, $4));
    }
;

num:
    T_NUM { $$(std::make_shared<NumExpr>(std::stoll(d_scanner.matched()))); }
;

bin_exp:
    expr T_EQUAL expr
    { $$( std::make_shared<BinExpr>($1, $3, BinExpr::Operator::EQUAL) ); }
|
    expr T_NEQUAL expr
    { $$( std::make_shared<BinExpr>($1, $3, BinExpr::Operator::NEQUAL) ); }
|
    expr T_GREATER expr
    { $$( std::make_shared<BinExpr>($1, $3, BinExpr::Operator::GREATER) ); }
|
    expr T_LESS expr
    { $$( std::make_shared<BinExpr>($1, $3, BinExpr::Operator::LESS) ); }
|
    expr T_GEQ expr
    { $$( std::make_shared<BinExpr>($1, $3, BinExpr::Operator::GEQ) ); }
|
    expr T_LEQ expr
    { $$( std::make_shared<BinExpr>($1, $3, BinExpr::Operator::LEQ) ); }
|
    expr T_AND expr
    { $$( std::make_shared<BinExpr>($1, $3, BinExpr::Operator::AND) ); }
|
    expr T_OR expr
    { $$( std::make_shared<BinExpr>($1, $3, BinExpr::Operator::OR) ); }
|
    expr T_TIMES expr
    { $$( std::make_shared<BinExpr>($1, $3, BinExpr::Operator::MUL) ); }
|
    expr T_DIV expr
    { $$( std::make_shared<BinExpr>($1, $3, BinExpr::Operator::DIV) ); }
|
    expr T_PLUS expr
    { $$( std::make_shared<BinExpr>($1, $3, BinExpr::Operator::ADD) ); }
|
    expr T_MINUS expr
    { $$( std::make_shared<BinExpr>($1, $3, BinExpr::Operator::SUB) ); }
;

expr_list:
    { $$( std::make_shared<ExprList>() ); }
|
    _expr_list
    { $$( $1 ); }
;

_expr_list:
    expr
    {
        $$( std::make_shared<ExprList>() );
        $$->push_back($1);
    }
|
    expr_list T_COMMA expr
    {
        $$( $1 );
        $$->push_back($3);
    }
;

expr_seq:
    { $$( std::make_shared<ExprSeqExpr>() ); }
|
    _expr_seq
    { $$($1); }
;

_expr_seq:
    expr
    {
        $$( std::make_shared<ExprSeqExpr>() );
        $$->push_back($1);
    }
|
    _expr_seq T_SEMI expr
    {
        $$($1);
        $$->push_back($3);
    }
;

lvalue:
    id
    { $$( std::make_shared<LValue>($1) ); }
|
    id T_DOT lvalue
    { $$( std::make_shared<LValue>($1, $3) ); }
|
    id T_LEFT_BRACKET expr T_RIGHT_BRACKET
    { $$( std::make_shared<LValue>($1, $3) ); }
;

id:
    T_ID
    { $$(std::make_shared<Id>( d_scanner.matched() ) ); }
;

field_list:
    { $$( std::make_shared<FieldList>() );  }
|
    _field_list
    { $$( $1 ); }
;

_field_list:
    field
    {
        $$( std::make_shared<FieldList>() );
        $$->push_back($1);
    }
|
    field_list T_COMMA field
    {
        $$( $1 );
        $$->push_back($3);
    }
;

field:
    id T_EQUAL expr
    { $$( std::make_shared<Field>($1, $3) ); }
;

break:
    T_BREAK
;

declaration_list:
    { $$( std::make_shared<DeclarationList>() ); }
|
    declaration_list declaration_scope
    {
        $$($1);
        $$->push_back($2);
    }
;


////////////////////
// DECLARATION SCOPE
////////////////////

declaration_scope:
    type_declaration_scope
    {
        $$( $1 );
    }
|
    function_declaration_scope
    {
        $$( $1 );
    }
|
    variable_declaration
    {
        $$( $1 );
    }
;


/////////////////////////
// TYPE DECLARATION SCOPE
/////////////////////////

type_declaration_scope:
    type_declaration
    {
        $$( std::make_shared<TypeDeclarationScope>() );
        $$->push_back($1);
    }
|
    type_declaration_scope type_declaration
    {
        $$($1);
        $$->push_back($2);
    }
;


/////////////////////////////
// FUNCTION DECLARATION SCOPE
/////////////////////////////

function_declaration_scope:
    function_declaration
    {
        $$( std::make_shared<FunctionDeclarationScope>() );
        $$->push_back($1);
    }
|
    function_declaration_scope function_declaration
    {
        $$( $1 );
        $$->push_back($2);
    }
;


///////////////////////
// VARIABLE DECLARATION
///////////////////////

variable_declaration:
    T_VAR id T_ASSIGN expr
    {
        $$(std::make_shared<VariableDeclaration>($2, $4));
    }
|
    T_VAR id T_COLON id T_ASSIGN expr
    {
        $$(std::make_shared<VariableDeclaration>($2, $4, $6));
    }
;


///////////////////
// TYPE DECLARATION
///////////////////

// Type declaration
// Alias type declaration
//  type A = B
// New Type declaration
//  type A = { a : int, b : string }
// New Array Type declaration
//  type A = array of int
type_declaration:
    T_TYPE id T_EQUAL id
    // alias
    { $$( std::make_shared<TypeDeclaration>($2, $4) ); }
|
    T_TYPE id T_EQUAL T_LEFT_BRACE type_fields T_RIGHT_BRACE
    // new type
    { $$( std::make_shared<TypeDeclaration>($2, $5) ); }
|
    T_TYPE id T_EQUAL T_ARRAY T_OF id
    // new array type
    { $$( std::make_shared<TypeDeclaration>($2, $6, true) ); }
;


///////////////////////
// FUNCTION DECLARATION
///////////////////////

function_declaration:
    T_FUNCTION id T_LEFT_PAR type_fields T_RIGHT_PAR T_EQUAL expr
    { $$( std::make_shared<FunctionDeclaration>($2, $4, $7) ); }
|
    T_FUNCTION id T_LEFT_PAR type_fields T_RIGHT_PAR T_COLON id T_EQUAL expr
    { $$( std::make_shared<FunctionDeclaration>($2, $4, $9, $7) ); }
;

//////////////
// TYPE FIELDS
//////////////

type_fields:
    // Accept empty
    { $$(); }
|
    _type_fields
    { $$($1); }
;

_type_fields:
    type_field
    {
        $$( std::make_shared<TypeFields>() );
        $$->push_back($1);
    }
|
    type_fields T_COMMA type_field
    {
        $$($1);
        $$->push_back($3);
    }
;

/////////////
// TYPE FIELD
/////////////

type_field:
    id T_COLON id
    { $$( std::make_shared<TypeField>($1, $3) ); }
;
