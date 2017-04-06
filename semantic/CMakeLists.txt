find_package(LLVM 3.6 REQUIRED)

set(BENGAL_SEMANTIC_LIBRARY semantic)
set(SOURCE
        Scope.cpp
        Report.cpp
        Types.cpp)

add_library(${BENGAL_SEMANTIC_LIBRARY} SHARED ${SOURCE})
set_property(TARGET ${BENGAL_SEMANTIC_LIBRARY} PROPERTY CXX_STANDARD 14)
target_link_libraries(${BENGAL_SEMANTIC_LIBRARY})
