cmake_minimum_required(VERSION 3.15)
project(OS_Colloq_1)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_TOOLCHAIN_FILE "C:/%userprofile%/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
include($ENV{USERPROFILE}/vcpkg/scripts/buildsystems/vcpkg.cmake)

find_package(GTest CONFIG REQUIRED)

add_executable(main main.cpp)
add_executable(tests main.cpp)
target_compile_definitions (tests PUBLIC -DUNIT_TEST=1)

add_custom_target(unit_tests
    COMMAND main --gtest_color=yes
    DEPENDS main
)


target_link_libraries(main PRIVATE
    GTest::gtest_main
	ws2_32
)
target_link_libraries(tests PRIVATE
    GTest::gtest_main
	ws2_32
)