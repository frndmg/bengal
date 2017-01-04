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
    UNARYEXPR: std::shared_ptr<UnaryExpr>;
    BREAKEXPR: std::shared_ptr<BreakExpr>;

%type <EXPR> expr
%type <STRINGEXPR> string_expr
%type <NUMEXPR> num
%type <NILEXPR> nil_expr
%type <BINEXPR> bin_expr
%type <LVALUE> lvalue _lvalue
%type <UNARYEXPR> unary_expr
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
%type <IFEXPR> if_expr
%type <BREAKEXPR> break

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
    { m_ast.setRoot( $1 ); }
;


/////////////
// EXPRESSION
/////////////

expr:
    string_expr
    { $$( $1 ); }
|
    num
    { $$( $1 ); }
|
    nil_expr
    { $$( $1 ); }
|
    lvalue { $$($1); }
|
    unary_expr
    { $$( $1 ); }
|
    bin_expr
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
    if_expr
    { $$( $1 ); }
|
    T_WHILE expr T_DO expr
    { $$( std::make_shared<WhileExpr>( $2, $4 ) ); }
|
    T_FOR id T_ASSIGN expr T_TO expr T_DO expr
    { $$( std::make_shared<ForExpr>( $2, $4, $6, $8 ) ); }
|
    break
    { $$( $1 ); }
|
    T_LET declaration_list T_IN expr_seq T_END
    {
        $$(std::make_shared<LetExpr>($2, $4));
    }
;


////////////////////
// STRING EXPRESSION
////////////////////

string_expr:
    T_STRING
    { $$( std::make_shared<StringExpr>( d_scanner.matched() ) ); }
;


////////////////////
// NUMBER EXPRESSION
////////////////////

num:
    T_NUM
    { $$( std::make_shared<NumExpr>(std::stoi( d_scanner.matched() )) ); }
;


/////////////////
// NIL EXPRESSION
/////////////////

nil_expr:
    T_NIL
    { $$( single_town<NilExpr>() ); }
;


///////////////////
// UNARY EXPRESSION
///////////////////

unary_expr:
    T_MINUS expr %prec UNARY
    { $$( std::make_shared<UnaryExpr>( $2, UnaryExpr::NEG ) ); }
;

bin_expr:
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


//////////////////
// EXPRESSION LIST
//////////////////

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


/////////////////////////////////
// EXPRESSION SEQUENCE EXPRESSION
/////////////////////////////////

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


/////////
// LVALUE
/////////

lvalue:
    id _lvalue
    {
        $$( std::make_shared<LValue>( $1 ) );
        $2->setParent( $$ );
    }
;

_lvalue:
    { $$( std::make_shared<LValue>() ); }
|
    T_DOT id _lvalue
    {
        $$( std::make_shared<LValue>( $2 ) );
        if ( not $3->isSimple() )
            $3->setParent( $$ );
    }
|
    T_LEFT_BRACKET expr T_RIGHT_BRACKET _lvalue
    {
        $$( std::make_shared<LValue>( $2 ) );
        if ( not $4->isSimple() )
            $4->setParent( $$ );
    }
;


/////
// Id
/////

id:
    T_ID
    { $$(std::make_shared<Id>( d_scanner.matched() ) ); }
;


/////////////
// FIELD LIST
/////////////

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


////////
// FIELD
////////

field:
    id T_EQUAL expr
    { $$( std::make_shared<Field>($1, $3) ); }
;


////////////////
// IF EXPRESSION
////////////////

if_expr:
    T_IF expr T_THEN expr
    { $$( std::make_shared<IfExpr>($2, $4) ); }
|
    T_IF expr T_THEN expr T_ELSE expr
    { $$( std::make_shared<IfExpr>($2, $4, $6) ); }
;


///////////////////
// BREAK EXPRESSION
///////////////////

break:
    T_BREAK
    { $$( std::make_shared<BreakExpr>() ); }
;


///////////////////
// DECLARATION LIST
///////////////////

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
    { $$( std::make_shared<TypeFields>() ); }
|
    _type_fields
    { $$( $1 ); }
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
