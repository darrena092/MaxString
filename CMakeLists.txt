add_library(max-string INTERFACE)
target_sources(max-string INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/max-string.c
)

target_include_directories(max-string INTERFACE
    include
)