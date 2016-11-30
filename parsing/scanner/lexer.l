%target-directory = "scanner"
%class-name = "Scanner"
%filenames = "scanner"
%lex-source = "lex.cpp"

%%

[ \t\n]+                            // skip white spaces

// Reserved words
nil                                 return Parser::T_NIL;
array                               return Parser::T_ARRAY;
break                               return Parser::T_BREAK;
do                                  return Parser::T_DO;
else                                return Parser::T_ELSE;
end                                 return Parser::T_END;
for                                 return Parser::T_FOR;
function                            return Parser::T_FUNCTION;
if                                  return Parser::T_IF;
in                                  return Parser::T_IN;
let                                 return Parser::T_LET;
of                                  return Parser::T_OF;
then                                return Parser::T_THEN;
to                                  return Parser::T_TO;
type                                return Parser::T_TYPE;
var                                 return Parser::T_VAR;
while                               return Parser::T_WHILE;

// Punctuation symbols
","                                 return Parser::T_COMMA;
":"                                 return Parser::T_COLON;
";"                                 return Parser::T_SEMI;
"("                                 return Parser::T_LEFT_PAR;
")"                                 return Parser::T_RIGHT_PAR;
"["                                 return Parser::T_LEFT_BRACKET;
"]"                                 return Parser::T_RIGHT_BRACKET;
"{"                                 return Parser::T_LEFT_BRACE;
"}"                                 return Parser::T_RIGHT_BRACE;
"."                                 return Parser::T_DOT;
"+"                                 return Parser::T_PLUS;
"-"                                 return Parser::T_MINUS;
"*"                                 return Parser::T_TIMES;
"/"                                 return Parser::T_DIV;
"="                                 return Parser::T_EQUAL;
"<>"                                return Parser::T_NEQUAL;
"<"                                 return Parser::T_LESS;
"<="                                return Parser::T_LEQ;
">"                                 return Parser::T_GREATER;
">="                                return Parser::T_GEQ;
"&"                                 return Parser::T_AND;
"|"                                 return Parser::T_OR;
":="                                return Parser::T_ASSIGN;

// Identifier
[[:alpha:]][[:alnum:]_]*            return Parser::T_ID;

// Integrer constant
[[:digit:]]+                        return Parser::T_NUM;

// String constant
\"[^\"\n]*\"                        return Parser::T_STRING;
