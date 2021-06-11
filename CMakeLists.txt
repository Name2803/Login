cmake_minimum_required(VERSION 3.13 FATAL_ERROR)


set(PROJECT_NAME Login)
project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} 
	src/main.cpp
	secure/sec.h
	secure/sec.cpp
	secure/001.txt
	server/server.h
	server/server.cpp
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)