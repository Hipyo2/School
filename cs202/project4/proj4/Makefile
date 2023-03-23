CXX = g++ 
CXX_FLAGS = -Wall -std=c++98


INCLUDES_DIR = ./include
LIBRARIES_DIR = ./lib
SOURCES_DIR = ./src
CXX_INCLUDE_PATH_COMMAND = -I$(INCLUDES_DIR)
CXX_LINK_PATH_COMMAND = -L$(LIBRARIES_DIR)

CXX_BUILD_COMMAND = $(CXX) $(CXX_FLAGS) $(CXX_INCLUDE_PATH_COMMAND) $(CXX_LINK_PATH_COMMAND)

LIBRARY_INSTALL_DIR = ./lib
EXECUTABLE_INSTALL_DIR = ./bin

all: proj4

proj4: $(SOURCES_DIR)/proj4.cpp \
            libMyFiles.a 
	$(CXX_BUILD_COMMAND) -o $(EXECUTABLE_INSTALL_DIR)/proj4 \
	                        $(SOURCES_DIR)/proj4.cpp \
					-lMyFiles 


#Rules to build Library

MY_MODULE_A_SOURCES_DIR = $(SOURCES_DIR)/files
MY_MODULE_A_INCLUDES_DIR = $(INCLUDES_DIR)/files

Agency.o: $(MY_MODULE_A_SOURCES_DIR)/Agency.cpp \
            $(MY_MODULE_A_INCLUDES_DIR)/Agency.h
	$(CXX_BUILD_COMMAND) -c -o $(LIBRARY_INSTALL_DIR)/Agency.o \
	                           $(SOURCES_DIR)/files/Agency.cpp

Car.o: $(MY_MODULE_A_SOURCES_DIR)/Car.cpp \
             $(MY_MODULE_A_INCLUDES_DIR)/Car.h
	$(CXX_BUILD_COMMAND) -c -o $(LIBRARY_INSTALL_DIR)/Car.o \
	                           $(SOURCES_DIR)/files/Car.cpp

Sensor.o: $(MY_MODULE_A_SOURCES_DIR)/Sensor.cpp \
             $(MY_MODULE_A_INCLUDES_DIR)/Sensor.h
	$(CXX_BUILD_COMMAND) -c -o $(LIBRARY_INSTALL_DIR)/Sensor.o \
	                           $(SOURCES_DIR)/files/Sensor.cpp

my_string.o: $(MY_MODULE_A_SOURCES_DIR)/my_string.cpp \
             $(MY_MODULE_A_INCLUDES_DIR)/my_string.h
	$(CXX_BUILD_COMMAND) -c -o $(LIBRARY_INSTALL_DIR)/my_string.o \
	                           $(SOURCES_DIR)/files/my_string.cpp

menu.o: $(MY_MODULE_A_SOURCES_DIR)/menu.cpp \
             $(MY_MODULE_A_INCLUDES_DIR)/menu.h
	$(CXX_BUILD_COMMAND) -c -o $(LIBRARY_INSTALL_DIR)/menu.o \
	                           $(SOURCES_DIR)/files/menu.cpp


libMyFiles.a: Agency.o \
                Car.o \
		Sensor.o \
		menu.o\
		my_string.o
	ar rvs $(LIBRARY_INSTALL_DIR)/libMyFiles.a $(LIBRARY_INSTALL_DIR)/Agency.o \
	                                             $(LIBRARY_INSTALL_DIR)/Car.o\
							$(LIBRARY_INSTALL_DIR)/Sensor.o\
							$(LIBRARY_INSTALL_DIR)/menu.o\
							$(LIBRARY_INSTALL_DIR)/my_string.o
			




clean: 
	rm -rf $(LIBRARY_INSTALL_DIR)/* $(EXECUTABLE_INSTALL_DIR)/*

