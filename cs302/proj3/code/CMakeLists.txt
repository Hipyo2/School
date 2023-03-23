cmake_minimum_required(VERSION 2.8.9)

project(hw3)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w -std=c++14")
include_directories(include)

set(SOURCE_SOURCES src/BinaryNode.cpp
	src/BinaryNodeTree.cpp
	src/BinarySearchTree.cpp
	src/PrecondViolatedExcept.cpp
	src/NotFoundException.cpp)

add_library(Source ${SOURCE_SOURCES})

add_executable(treeMain src/treeMain.cpp)
target_link_libraries (treeMain Source)

install(TARGETS treeMain Source
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/devel/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib
	ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib/static)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
	FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")

