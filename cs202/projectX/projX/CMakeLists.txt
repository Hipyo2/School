cmake_minimum_required(VERSION 2.8.9)

project(projX)
include_directories(include)
set(DATATYPE_SOURCES src/DataType/DataType.cpp)
set(SMARTPTR_SOURCES src/SmartPtr/SmartPtr.cpp)
add_library(DataType ${DATATYPE_SOURCES})
add_library(SmartPtr ${SMARTPTR_SOURCES})
add_executable(projX src/projX.cpp)
target_link_libraries (projX SmartPtr)
install(TARGETS projX SmartPtr
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/devel/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib
	ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib/static)

target_link_libraries (projX DataType)
install(TARGETS projX DataType
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/devel/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib
	ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib/static)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
	FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
