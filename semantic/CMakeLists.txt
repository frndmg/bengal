find_package(LLVM 3.6 REQUIRED)

set(BENGAL_SEMANTIC_LIBRARY semantic)
set(SOURCE
        Scope.cpp
        Report.cpp)

add_library(${BENGAL_SEMANTIC_LIBRARY} SHARED ${SOURCE})
target_link_libraries(${BENGAL_SEMANTIC_LIBRARY})
