
function(add_tiger_test TEST_NAME TEST_TYPE TEST_LABEL)
    set(NAME ${TEST_NAME}-${TEST_TYPE}_${TEST_LABEL})
    add_test(NAME ${NAME}
             COMMAND tiger tigs/${TEST_NAME}/${NAME}.tig
             WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tests
    )
endfunction()

add_tiger_test(int_expr positive 01)
add_tiger_test(int_expr negative 01)

add_tiger_test(lvalue_expr simple 01)
add_tiger_test(lvalue_expr simple 02)

# LET EXPRESSION
## SIMPLE
add_tiger_test(let_expr simple 01)
## TYPE DECLARATION
add_tiger_test(let_expr type_declaration 01)
add_tiger_test(let_expr type_declaration 02)
add_tiger_test(let_expr type_declaration 03)

# EXPRESSION SEQUENCE EXPRESSION
## SIMPLE
add_tiger_test(expr_seq simple 01)
add_tiger_test(expr_seq simple 02)

# ASSIGN EXPRESSION
## SIMPLE
add_tiger_test(assign_expr simple 01)
