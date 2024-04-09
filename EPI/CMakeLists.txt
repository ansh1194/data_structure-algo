cmake_minimum_required(VERSION 3.22)

project(EPI LANGUAGES CXX)

add_executable(${PROJECT_NAME} Arrays/dutch_nat_flag.cpp)
message(${CMAKE_SOURCE_DIR})
target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/Lib/build)
target_link_libraries(${PROJECT_NAME} myLib)