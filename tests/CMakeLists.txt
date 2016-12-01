
function(add_tiger_test TEST_NAME TEST_TYPE TEST_SOURCE)
  get_filename_component(TEST_TARGET ${TEST_SOURCE} NAME_WE)

  add_test(NAME ${TEST_NAME}.${TEST_TYPE} COMMAND tiger tigs/${TEST_NAME}/${TEST_SOURCE} WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tests)
endfunction()

add_tiger_test(int_expr positive int_expr_01.tig)
add_tiger_test(int_expr negative int_expr_02.tig)

add_tiger_test(lvalue_expr simple lvalue_expr_01.tig)
add_tiger_test(lvalue_expr "" lvalue_expr_02.tig)
