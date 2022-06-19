
project(asm_test)
set(${PROJECT_NAME}_targets
    fake-test1
    fake-test2
)

add_custom_target(asm_tests)
set_target_properties(${asm_tests}
    PROPERTIES
        EXECUTABLE_OUTPUT_PATH
            "${PROJECT_SOURCE_DIR}/testing/bin"
)

foreach(test ${${PROJECT_NAME}_targets})
    add_executable(${test} EXCLUDE_FROM_ALL ${test}.c)
    add_test(NAME ${test} COMMAND $<TARGET_FILE:${test}> WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/../bin)
    add_dependencies(asm_tests ${test})
endforeach(test)