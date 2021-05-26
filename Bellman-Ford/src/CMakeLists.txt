add_executable (Bellman-Ford main.cpp)

add_custom_target(run_Bellman-Ford DEPENDS Bellman-Ford
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/Bellman-Ford
)
