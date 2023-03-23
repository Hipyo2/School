//Project 8
//Nicholas Ang
//Project 8 Main function source file

#include <header/ArrayList.h>
#include <header/NodeList.h>
#include <header/DataType.h>
#include <iostream>
using namespace std;

//GG Test Driver
//Tests all functions in all classes
int main ()
{
ArrayList arrayL;
cout << "Testing Default Constructor for Arraylist" << endl;
NodeList nodeL;
cout << "Testing Default Constructor for Nodelist" << endl;

DataType d1(100, 12.42);
DataType d2(2, 324.67);
DataType d3(535, 2342.33);
DataType d4(23, 23.123);

ArrayList parameterizedA(2, d1);
ArrayList copyA(parameterizedA);
cout << "Testing parameterized Constructor for Array List: " << parameterizedA << endl;
cout << "Testing Copy Constructor for Array List: " << copyA << endl;

NodeList parameterizedN(3,d2);
NodeList copyN(parameterizedN);
cout << "Testing parameterized Constructor for Node List: " << parameterizedN << endl;
cout << "Testing Copy Constructor for Node List: " << copyN << endl;

cout << "Testing destructor for Array List" << endl;
ArrayList *deA = new ArrayList(1,d3);
cout << "Testing destructor for Node List" << endl;
NodeList *deN = new NodeList(1,d3);
delete deA;
delete deN;
deA = nullptr;
deN = nullptr;

cout << "Testing Assignment Operator" << endl;
parameterizedA = copyA;
parameterizedN = copyN;
cout << "Assignment operator for Array List: Assigned" << endl << parameterizedA << "   " << copyA << endl;
cout << "Assignment operator for Node List: Assigned" << endl << parameterizedN << "   " << copyN << endl;

cout << "Testing Access [] for Array List" << parameterizedA[1] << endl;
cout << "Testing Access [] for Node List" << parameterizedN[2] << endl;


DataType *previous1 = NULL;
cout << "Testing Find() for ArrayList" << endl;
DataType *result1 = parameterizedA.find(d1, previous1);
cout << "Find successful" << endl;
cout << "Testing Insert After and Insert Before for ArrayList" << endl;
copyA.insertAfter(DataType(*result1), DataType(100, 325.778));
cout << copyA << endl;
copyA.insertBefore(DataType(*result1), DataType(64, 23423.77));
cout << copyA << endl;
cout << "Testing Erase" << endl;
copyA.erase(*copyA.front());
cout << "Erased: " << copyA << endl;

Node *previous = NULL;
cout << "Testing Find() for ArrayList" << endl;
Node *result2 = parameterizedN.find(d2, previous);
cout << result2 << endl;
cout << "Find successful" << endl;
cout << "Testing Insert After and Insert Before for NodeList" << endl;
parameterizedN.insertAfter(d2, DataType(100, 325.778));
cout << parameterizedN << endl;
parameterizedN.insertBefore(d2, DataType(64, 23423.77));
cout << parameterizedN << endl;
cout << "Testing Erase" << endl;
parameterizedN.erase(parameterizedN.front()->data());
cout << "Erased: " << parameterizedN << endl;

cout << "Clearing..." << endl;
parameterizedA.clear();
copyA.clear();
parameterizedN.clear();
copyN.clear();
cout << "All cleared" << endl;
return 0;
}
