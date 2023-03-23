cmake_minimum_required(VERSION 2.8.9)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(proj9)
include_directories(include)
set(SOURCE_SOURCES src/source/DataType.cpp
	src/source/NodeQueue.cpp
	src/source/ArrayQueue.cpp)

add_library(Source ${SOURCE_SOURCES})
add_executable(proj9 src/proj9.cpp)
target_link_libraries (proj9 Source)
install(TARGETS proj9 Source
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/devel/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib
	ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib/static)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
	FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
