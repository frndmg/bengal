%scanner                    ../scanner/scanner.h
%scanner-class-name         Scanner

%target-directory           parser
%filenames                  parser
%parsefun-source            parse.cpp

%baseclass-preinclude       parserPreinclude.hpp

%expect 1

%start program

%polymorphic
    ARRAYEXPR: std::shared_ptr<ArrayExpr>;
    EXPRSEQEXPR: std::shared_ptr<ExprSeqExpr>;
    LVALUE: std::shared_ptr<LValue>;
    RVALUE: std::shared_ptr<RValue>;
    ASSIGNEXPR: std::shared_ptr<AssignExpr>;
    FOREXPR: std::shared_ptr<ForExpr>;
    NILEXPR: std::shared_ptr<NilExpr>;
    STRINGEXPR: std::shared_ptr<StringExpr>;
    BINEXPR: std::shared_ptr<BinExpr>;
    FUNCTIONCALLEXPR: std::shared_ptr<FunctionCallExpr>;
    NODE: std::shared_ptr<Node>;
    WHILEEXPR: std::shared_ptr<WhileExpr>;
    BREAKABLEEXPR: std::shared_ptr<BreakableExpr>;
    IFEXPR: std::shared_ptr<IfExpr>;
    NUMEXPR: std::shared_ptr<NumExpr>;
    EXPR: std::shared_ptr<Expr>;
    LETEXPR: std::shared_ptr<LetExpr>;
    RECORDEXPR: std::shared_ptr<RecordExpr>;

%type <EXPR> expr
%type <NUMEXPR> num
%type <BINEXPR> bin_exp
%type <LVALUE> lvalue

%token T_ID T_NUM T_SEMI T_NIL T_STRING T_COMMA T_DOT T_COLON
       T_ARRAY T_BREAK T_DO T_ELSE T_END T_FOR T_FUNCTION T_IF T_IN T_LET T_OF
       T_THEN T_TO T_TYPE T_VAR T_WHILE
       T_LEFT_BRACKET T_RIGHT_BRACKET
       T_LEFT_BRACE T_RIGHT_BRACE
       T_LEFT_PAR T_RIGHT_PAR
%nonassoc T_ASSIGN
%nonassoc T_EQUAL T_NEQUAL T_GREATER T_LESS T_GEQ T_LEQ T_AND T_OR
%left T_PLUS T_MINUS
%left T_TIMES T_DIV
%right UNARY

%%

program:
    expr EOF
;

expr:
    T_STRING
|
    num { $$ = $1; }
|
    T_NIL
|
    lvalue { $$ = $1; }
|
    T_MINUS expr %prec UNARY
|
    bin_exp { $$ = $1; }
|
    lvalue T_ASSIGN expr
|
    id T_LEFT_PAR expr_list T_RIGHT_PAR
|
    T_LEFT_PAR expr_seq T_RIGHT_PAR
|
    id T_LEFT_BRACE field_list T_RIGHT_BRACE
|
    id T_LEFT_BRACKET expr T_RIGHT_BRACKET T_OF expr
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
;

num:
    T_NUM { $$ = std::make_shared<NumExpr>(std::stoll(d_scanner.matched())); }
;

bin_exp:
    expr T_EQUAL expr
|
    expr T_NEQUAL expr
|
    expr T_GREATER expr
|
    expr T_LESS expr
|
    expr T_GEQ expr
|
    expr T_LEQ expr
|
    expr T_AND expr
|
    expr T_OR expr
|
    expr T_TIMES expr
|
    expr T_DIV expr
|
    expr T_PLUS expr
|
    expr T_MINUS expr
;

expr_list:
|
    expr
|
    expr_list T_COMMA expr
;

expr_seq:
|
    expr
|
    expr_seq T_SEMI expr
;

lvalue:
    id
|
//    lvalue T_DOT id
    id T_DOT lvalue
|
//    lvalue T_LEFT_BRACKET expr T_RIGHT_BRACKET
    id T_LEFT_BRACKET expr T_RIGHT_BRACKET
;

id:
    T_ID
;

field_list:
|
    id T_EQUAL expr
|
    field_list T_COLON id T_EQUAL expr
;

break:
    T_BREAK
;

declaration_list:
    declaration
|
    declaration_list declaration
;

declaration:
    type_declaration
|
    variable_declaration
|
    function_declaration
;

type_declaration:
    T_TYPE id T_EQUAL type
;

type:
    id
|
    T_LEFT_BRACE type_fields T_RIGHT_BRACE
|
    T_ARRAY T_OF id
;

type_fields:
|
    type_field
|
    type_fields T_COMMA type_field
;

type_field:
    id T_COLON id
;

variable_declaration:
    T_VAR id T_ASSIGN expr
|
    T_VAR id T_COLON id T_ASSIGN expr
;

function_declaration:
    T_FUNCTION id T_LEFT_PAR type_fields T_RIGHT_PAR T_EQUAL expr
|
    T_FUNCTION id T_LEFT_PAR type_fields T_RIGHT_PAR T_COLON id T_EQUAL expr
;
