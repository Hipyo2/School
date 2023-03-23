//Project 9
//Nicholas Ang
//Project 9 Main source file

//Libraries and Header Files
#include <iostream>
#include <header/DataType.h>
#include <header/ArrayQueue.h>
#include <header/NodeQueue.h>
using namespace std;

//Project 9 Test Driver for ArrayQueue functions and NodeQueue functions
int main()
{
	//Creating some data types with random values
	DataType d1(70, 2.346);
	DataType d2(342, 9.2754);
	DataType d3(2423, 463.0032);
	DataType d4(100, 100.1);
	
	//ArrayQueue Tests
	//Constructors of Array Queue
	cout << "Array Queue Tests" << endl;
	ArrayQueue defaultAq;
	cout << "Default Constructor of Array Queue: " << defaultAq << endl;
	ArrayQueue paraAq(5, d1);
	cout << "Parameterized Constructor of Array Queue: " << paraAq << endl;
	ArrayQueue copyAq(paraAq);
	cout << "Copy Constructor of Array Queue: " << copyAq << endl << endl;
	
	//Assignment Operator for Array Queue
	cout << "Testing Assignment Operator for Array Queue" << endl;
	ArrayQueue assignAq;
	assignAq = paraAq;
	cout << "Assigned... Output of Assigned Array Queue: " << assignAq << endl; 
	//Front, Back, Size Functions of Array Queue
	cout << "Testing Front function" << endl << "Front: " << paraAq.front() << endl;
	cout << "Testing Back function" << endl << "Back: " << paraAq.back() << endl;
	cout << "Testing size function" << endl << "Size: " << paraAq.size() << endl << endl;
	
	//Push Pop functions of Array Queue
	cout << "Testing push function" << endl;
	paraAq.push(d2);
	cout << "Pushed Array Queue: " << paraAq << endl;
	cout << "Testing pop function" << endl;
	paraAq.pop();
	cout << "Popped Array Queue: " << paraAq << endl;
	//Empty and Full function checks
	cout << "Checking if Array Queue is empty for Default Queue" << endl;
	cout << std::boolalpha << defaultAq.empty() << endl;
	cout << "Checking if Array Queue is full for Parameterized Queue" << endl;
	cout << std::boolalpha << paraAq.full() << endl;
	cout << "Clearing Array Queues" << endl;
	//Clear all made array queues
	paraAq.clear();
	defaultAq.clear();
	copyAq.clear();
	assignAq.clear();
	cout << "Cleared" << endl;




	//NodeQueue Tests
	//Constructors of Node Queue	
	cout << "Node Queue Tests" << endl;
	NodeQueue defaultNq;
	cout << "Default Constructor of Node Queue: " << defaultNq << endl;
	NodeQueue paraNq(7, d3);
	cout << "Parameterized Constructor of Node Queue: " << paraNq << endl;
	NodeQueue copyNq(paraNq);
	cout << "Copy Constructor of Node Queue: " << copyNq << endl << endl;
	
	//Assignment Operator for Node Queue
	cout << "Testing Assignment Operator for Node Queue" << endl;
	NodeQueue assignNq;
	assignNq = paraNq;
	cout << "Assigned... Output of Assigned Node Queue: " << assignNq << endl; 
	//Front back and size function for Node Queue
	cout << "Testing Front function" << endl << "Front: " << paraNq.front() << endl;
	cout << "Testing Back function" << endl << "Back: " << paraNq.back() << endl;
	cout << "Testing size function" << endl << "Size: " << paraNq.size() << endl << endl;

	//Push Pop Function for Node Queue
	cout << "Testing push function" << endl;
	paraNq.push(d4);
	cout << "Pushed Node Queue: " << paraNq << endl;
	cout << "Testing pop function" << endl;
	paraNq.pop();
	cout << "Popped Node Queue: " << paraNq << endl;
	//Empty and Full Queue checks
	cout << "Checking if Node Queue is empty for Default Queue" << endl;
	cout << std::boolalpha << defaultNq.empty() << endl;
	cout << "Checking if Node Queue is full for Parameterized Queue" << endl;
	cout << std::boolalpha << paraNq.full() << endl;
	//Clears all made node queues
	cout << "Clearing Node Queues" << endl;
	paraNq.clear();
	defaultNq.clear();
	copyNq.clear();
	assignNq.clear();
	cout << "Cleared" << endl;


	return 0;
}
