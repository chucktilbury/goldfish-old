
project(asm)

add_executable(${PROJECT_NAME}
    asm.c
)

target_link_libraries(${PROJECT_NAME}
    vm
    gc
    cord
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/../common
        ${PROJECT_SOURCE_DIR}/../include
        ${PROJECT_SOURCE_DIR}/../../external/include
)

link_directories (
    PUBLIC
        ${PROJECT_SOURCE_DIR}/bin
        ${PROJECT_SOURCE_DIR}/external/lib
)

target_compile_options(${PROJECT_NAME} PRIVATE "-Wall" "-Wextra" "-DMEMORY_DEBUG" "-g" "-DTRACE")
