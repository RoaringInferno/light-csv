cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

project(light-csv)

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_library(light-csv STATIC ${SOURCES})
target_include_directories(light-csv PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

enable_testing()
add_executable(tests test/test.cpp)
target_link_libraries(tests light-csv)
add_test(NAME lcsv-tests COMMAND tests)