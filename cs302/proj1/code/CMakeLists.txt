cmake_minimum_required(VERSION 2.8.9)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(hw1)
include_directories(include)

set(SOURCE_SOURCES src/test6/StackArray.cpp
	src/test6/StackLinked.cpp)

add_library(Source ${SOURCE_SOURCES})

add_executable(delimiters src/delimiters/delimiters.cpp)
target_link_libraries (delimiters Source)

add_executable(test6 src/test6/test6.cpp)
target_link_libraries (test6 Source)

add_executable(postfix src/postfix/postfix.cpp)
target_link_libraries (postfix Source)

install(TARGETS delimiters postfix test6 Source
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/devel/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib
	ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib/static)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/test6/include/
	DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
	FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
