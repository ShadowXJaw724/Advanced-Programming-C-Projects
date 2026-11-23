cmake_minimum_required(VERSION 4.3)
project(src)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(src
        main.cpp
)

target_include_directories(src PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

include(FetchContent)

set(GOOGLETEST_REVISION 03597a01ee50ed33e9dfd640b249b4be3799d395)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/${GOOGLETEST_REVISION}.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF)

FetchContent_MakeAvailable(googletest)

if(NOT TARGET GTest::gtest_main AND
        EXISTS "${googletest_SOURCE_DIR}/googletest-${GOOGLETEST_REVISION}/CMakeLists.txt")
    add_subdirectory(
            "${googletest_SOURCE_DIR}/googletest-${GOOGLETEST_REVISION}"
            "${googletest_BINARY_DIR}"
    )
endif()

enable_testing()

add_executable(merge_sort_tests
        mergeSortTesting.cpp
)

target_include_directories(merge_sort_tests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(merge_sort_tests PRIVATE
        GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(merge_sort_tests)
