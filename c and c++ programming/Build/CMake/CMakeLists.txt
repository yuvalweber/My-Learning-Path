cmake_minimum_required(VERSION 3.22.1)

project(HelloWorld)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(subdir)

target_link_directories(${PROJECT_NAME} PRIVATE subdir)

target_link_libraries(${PROJECT_NAME} lib)