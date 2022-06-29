
project(gvm)

add_executable(${PROJECT_NAME}
    runLoop.c
    doArith.c
    doComp.c
    doJmps.c
    vmErrors.c
    traps.c
    gvm.c
)

target_link_libraries(${PROJECT_NAME}
    vm
    gc
    cord
    m
)

target_compile_options(${PROJECT_NAME} PRIVATE "-Wall" "-Wextra" "-DMEMORY_DEBUG" "-g" "-DTRACE")
