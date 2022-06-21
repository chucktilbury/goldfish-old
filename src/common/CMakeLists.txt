
project(vm)

add_library(${PROJECT_NAME} STATIC
    opcodes.c
    values.c
    cmdline.c
    instrStore.c
    varStore.c
    strStore.c
    callStack.c
    valStack.c
    traps.c
    listing.c
    fileIo.c
    registers.c
    errors.c
    misc.c
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/../include
        ${PROJECT_SOURCE_DIR}/../common
)

target_compile_options(${PROJECT_NAME} PRIVATE "-Wall" "-Wextra" "-g" "-DTRACE")
