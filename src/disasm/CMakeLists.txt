
project(disasm)

add_executable(${PROJECT_NAME}
    disasm.c
)

target_link_libraries(${PROJECT_NAME}
    vm
    gc-lib
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/../include
        ${PROJECT_SOURCE_DIR}/../common
)

target_compile_options(${PROJECT_NAME} PRIVATE "-Wall" "-Wextra" "-g" "-DTRACE")
