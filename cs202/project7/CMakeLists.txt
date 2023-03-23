cmake_minimum_required(VERSION 2.8.9)

project(proj7)
include_directories(include)
set(STRINGSOURCE_SOURCES src/StringSource/MyString.cpp)

add_library(StringSource ${STRINGSOURCE_SOURCES})
add_executable(proj7 src/proj7.cpp)
target_link_libraries (proj7 StringSource)
install(TARGETS proj7 StringSource
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/devel/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib
	ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib/static)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
	FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
