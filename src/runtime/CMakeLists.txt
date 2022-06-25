project(runtime)

add_library(${PROJECT_NAME} STATIC
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/../include
        ${PROJECT_SOURCE_DIR}/../common
)

target_compile_options(${PROJECT_NAME} PRIVATE "-Wall" "-Wextra" "-DMEMORY_DEBUG" "-g" "-DTRACE")
