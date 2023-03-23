cmake_minimum_required(VERSION 2.8.9)

project(proj8)
include_directories(include)
set(SOURCE_SOURCES src/source/DataType.cpp
	src/source/NodeList.cpp
	src/source/ArrayList.cpp)

add_library(Source ${SOURCE_SOURCES})
add_executable(proj8 src/proj8.cpp)
target_link_libraries (proj8 Source)
install(TARGETS proj8 Source
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/devel/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib
	ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib/static)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
	FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
