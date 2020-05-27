cmake_minimum_required(VERSION 3.1)
project(Male)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
file(GLOB SRC src/*.cpp *.cpp)

set(CMAKE_CXX_FLAGS "-Wall -g -std=c++14")
set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} ${SRC})

add_custom_target(valgrind
	COMMAND valgrind ./${PROJECT_NAME}
	DEPENDS ${PROJECT_NAME}
)
