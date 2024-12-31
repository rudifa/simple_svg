cmake_minimum_required(VERSION 3.10)
project(simple-svg)

# Enable testing
enable_testing()

# Set C++17 for all targets
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add the main executable
add_executable(simple_svg main_1.0.0.cpp simple_svg_1.0.0.hpp)

if(MSVC)
    add_definitions(/D_CRT_SECURE_NO_WARNINGS)
    add_definitions(/D_SCL_SECURE_NO_WARNINGS)
    add_definitions(/DNOMINMAX)
endif(MSVC)

# Add Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add the test executable
add_executable(simple_svg_test tests/simple_svg_test.cpp simple_svg_1.0.0.hpp)
target_link_libraries(simple_svg_test ${GTEST_LIBRARIES} pthread)

# Add the test
add_test(NAME SimplesvgTest COMMAND simple_svg_test)
