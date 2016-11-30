find_package(LLVM 3.6 REQUIRED)

# message("USING LLVM: " ${LLVM_DIR})

set(SOURCE Expr.cpp
           NumExpr.cpp
           RValue.cpp
           Node.cpp
           StringExpr.cpp
           NilExpr.cpp)
add_library(ast SHARED ${SOURCE})
