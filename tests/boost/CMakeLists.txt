include_directories(../../ast ../../parsing/parser ../../semantic)

function(add_boost_tiger_test TEST_NAME)
    add_executable(${TEST_NAME} ${TEST_NAME}.cpp)
    target_link_libraries(${TEST_NAME} parsing ast semantic)
    set_property(TARGET ${TEST_NAME} PROPERTY CXX_STANDARD 14)
    # Params
    # --show_progress=yes
    # --color_output=yes
    # --log_level=all
    # --report_level=detailed
    add_test(
        NAME ${TEST_NAME}
        COMMAND ${TEST_NAME}
    )
endfunction()

add_boost_tiger_test(binary_expression_test)
