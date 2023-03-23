cmake_minimum_required(VERSION 2.8.9)

project(hw4)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w -std=c++11")
include_directories(include)

set(SOURCE_SOURCES src/LeftLeaningRedBlack.cpp)

add_library(Source ${SOURCE_SOURCES})

add_executable(rbTreeMain src/rbTreeMain.cpp)
target_link_libraries (rbTreeMain Source)

install(TARGETS rbTreeMain Source
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/devel/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib
	ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib/static)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
	FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")

