project(container_benchmark)

# 'lib' is the folder with Google Benchmark
option(BENCHMARK_ENABLE_TESTING "Enable testing of the benchmark library." OFF)
option(BENCHMARK_ENABLE_GTEST_TESTS "Enable testing of the Google Test integration." OFF)
option(BENCHMARK_INSTALL_DOCS OFF)
add_subdirectory(lib)

file(GLOB BENCHMARK_FILES *Benchmark.cpp)

message(" + Znaleziono pliki benchmarków: ${BENCHMARK_FILES}")

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES_WITHOUT_MAIN} ${BENCHMARK_FILES})
target_link_libraries(${PROJECT_NAME} benchmark::benchmark_main benchmark::benchmark)

############ KOMENDA: make run_benchmark
add_custom_target(run_${PROJECT_NAME} DEPENDS ${PROJECT_NAME}
    COMMAND ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
