function(add_tiger_test FOLDER TIGER_FILE_NAME)
    add_test(NAME ${FOLDER}/${TIGER_FILE_NAME}
             COMMAND tiger tigs/${FOLDER}/${TIGER_FILE_NAME}.tig
             WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tests)
endfunction()

# INT EXPRESSION
## POSITIVE
add_tiger_test(int_expr positive)
## NEGATIVE
add_tiger_test(int_expr negative)

# NIL EXPRESSION
# SIMPLE
add_tiger_test(nil_expr simple)

# LVALUE EXPRESSION
## SIMPLE
add_tiger_test(lvalue_expr simple01)
add_tiger_test(lvalue_expr simple02)


# UNARY EXPRESSION
## SIMPLE
add_tiger_test(unary_expr simple01)
add_tiger_test(unary_expr simple02)


# BINARY EXPRESSION
## SIMPLE
add_tiger_test(bin_expr simple01)
add_tiger_test(bin_expr simple02)
## WITH PARENTECES
add_tiger_test(bin_expr with_parenteces)
## SEMANTIC ERRORS
add_tiger_test(bin_expr/semantic_error add_string_int)

# LET EXPRESSION
## SIMPLE
add_tiger_test(let_expr simple01)
## TYPE DECLARATION
add_tiger_test(let_expr/type_declaration alias)
add_tiger_test(let_expr/type_declaration array_of_int)
add_tiger_test(let_expr/type_declaration two_fields)
add_tiger_test(let_expr/type_declaration/semantic_error alias_b_does_not_exist)
## FUNCTION DECLARATION
add_tiger_test(let_expr/function_declaration no_params_no_return_no_body)
add_tiger_test(let_expr/function_declaration one_param_no_return_no_body)
add_tiger_test(let_expr/function_declaration no_params_returns_no_body)
add_tiger_test(let_expr/function_declaration one_param_returns_no_body)
add_tiger_test(let_expr/function_declaration two_functions)

# EXPRESSION SEQUENCE EXPRESSION
## SIMPLE
add_tiger_test(expr_seq simple01)
add_tiger_test(expr_seq simple02)

# ASSIGN EXPRESSION
## SIMPLE
add_tiger_test(assign_expr simple01)

# FUNCTION CALL EXPRESSION
## SIMPLE
add_tiger_test(function_call_expr no_params)
add_tiger_test(function_call_expr one_param)
add_tiger_test(function_call_expr two_params)

# RECORD EXPRESSION
## SIMPLE
add_tiger_test(record_expr no_params)
add_tiger_test(record_expr one_param)
add_tiger_test(record_expr two_params)

# ARRAY EXPRESSION
## SIMPLE
add_tiger_test(array_expr simple01)


# IF EXPRESSION
add_tiger_test(if_expr if_then)
add_tiger_test(if_expr if_then_else)
add_tiger_test(if_expr if_then_if_then_else)


# FOR EXPRESSION
add_tiger_test(for_expr simple01)


# WHILE EXPRESSION
add_tiger_test(while_expr simple01)


# OTHER TESTS
add_tiger_test(other 8queens)


# Add boost testing
add_subdirectory(boost)


# Add catch testing
add_subdirectory(catch)
