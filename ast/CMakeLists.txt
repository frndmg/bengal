find_package(LLVM 3.6 REQUIRED)

set(BENGAL_AST_LIBRARY ast)
set(SOURCE
    Expr.cpp
    NumExpr.cpp
    RValue.cpp
    Node.cpp
    StringExpr.cpp
    NilExpr.cpp
)

add_library(${BENGAL_AST_LIBRARY} SHARED ${SOURCE})
target_link_libraries(ast)
