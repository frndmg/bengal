find_package(LLVM 3.6)

message("USING LLVM: " ${LLVM_DIR})

set(SOURCE Expr.cpp
           NumExpr.cpp
           RValue.cpp
           Node.cpp)
add_library(ast ${SOURCE})
