cmake_minimum_required(VERSION 3.22.3)
project(tests)


find_package(PkgConfig REQUIRED)
pkg_check_modules(GTest gtest_main)

add_executable(${PROJECT_NAME} tests.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${GTest_INCLUDE_DIRECTORIES})
target_link_libraries(${PROJECT_NAME} ${GTest_LIBRARIES}) 