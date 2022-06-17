
project(virt)

add_executable(${PROJECT_NAME}
    runLoop.c
    doArith.c
    doComp.c
    doJmps.c
    vmErrors.c
    virt.c
)

target_link_libraries(${PROJECT_NAME}
    vm
    m
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/../include
        ${PROJECT_SOURCE_DIR}/../common
)

target_compile_options(${PROJECT_NAME} PRIVATE "-Wall" "-Wextra" "-g" "-DTRACE")
