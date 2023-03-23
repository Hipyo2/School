all: proj3
proj3: proj3.cpp menu.o my_string.o RentalCar.o
	$(CXX) $(CXX_FLAGS) -o proj3 proj3.cpp menu.o my_string.o RentalCar.o
menu.o: menu.cpp menu.h
	$(CXX) $(CXX_FLAGS) -c -o menu.o menu.cpp
my_string.o: my_string.cpp my_string.h
	$(CXX) $(CXX_FLAGS) -c -o my_string.o my_string.cpp
RentalCar.o: RentalCar.cpp RentalCar.h Agency.h
	$(CXX) $(CXX_FLAGS) -c -o RentalCar.o RentalCar.cpp
clean:
	rm -rf *.o proj3
