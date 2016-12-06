find_package(LLVM 3.6 REQUIRED)

set(BENGAL_AST_LIBRARY ast)
set(SOURCE
    Expr.cpp
    NumExpr.cpp
    RValue.cpp
    Node.cpp
    StringExpr.cpp
    NilExpr.cpp
    BinExpr.cpp
    LValue.cpp
    ArrayExpr.cpp
    RecordExpr.cpp
    ExprSeqExpr.cpp
    IfExpr.cpp
    FunctionCallExpr.cpp
    LetExpr.cpp
    WhileExpr.cpp
    ForExpr.cpp
    AssignExpr.cpp
    BreakableExpr.cpp
    Id.cpp
    DeclarationList.cpp
    TypeDeclaration.cpp
    FunctionDeclaration.cpp
    VariableDeclaration.cpp
    FieldList.cpp
    Field.cpp
    DeclarationScope.cpp
    FunctionDeclarationScope.cpp
    TypeDeclarationScope.cpp
    TypeField.cpp
    TypeFields.cpp
)

add_library(${BENGAL_AST_LIBRARY} SHARED ${SOURCE})
target_link_libraries(ast)
