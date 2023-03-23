//Project 10
//Nicholas Ang
//Project 10 Main Source File - Test Drivers

//Libraries and Header Files
#include <ArrayStack/ArrayStack.hpp>
#include <NodeStack/NodeStack.hpp>
#include <iostream>
using namespace std;

//Main Function - Test Drivers for ArrayStack and NodeStack classes
int main ()
{
	//Array Stack Tests
	//Tests all functions in ArrayStack class
	cout << "Array Stack Tests" << endl << endl;
	cout << "Testing Default Constructor" << endl;
	ArrayStack<int> aDef1;
	ArrayStack<double> aDef2;
	cout << aDef1 << endl;
	cout << aDef2 << endl<<endl;

	cout << "Testing Parameterized Constructor" << endl;
	ArrayStack<int> aPara1(3, 20);
	ArrayStack<double> aPara2(5, 1.1);
	cout << aPara1 << endl;
	cout << aPara2 << endl<<endl;

	cout << "Testing Copy Constructor" << endl;
	ArrayStack<int> aCopy1(aPara1);
	ArrayStack<double> aCopy2(aPara2);
	cout << aCopy1 << endl;
	cout << aCopy2 << endl<<endl;

	cout << "Testing Assignment operator" << endl;
	ArrayStack<int> aAssign1;
	ArrayStack<double> aAssign2;
	aAssign1 = aCopy1;
	aAssign2 = aCopy2;
	cout << aCopy1 << endl;
	cout << aCopy2 << endl <<endl;

	cout << "Testing Top Function" << endl;
	cout << aPara1.top() << endl <<endl;
	cout << "Testing Push Function" << endl;
	aPara1.push(70);
	cout << aPara1 << endl;
	cout << "Testing Pop Function" << endl;
	aPara1.pop();
	cout << aPara1 << endl << endl;

	cout << "Testing Size, Empty, and Full Functions" << endl;
	cout << "Size: " << aPara1.size() << endl;
	cout << "Empty: " << std::boolalpha << aPara1.empty() << endl;
	cout << "Full: " << std::boolalpha << aPara1.full() << endl;

	cout << "Testing Clear Function" << endl;
	aPara1.clear();
	cout << "Cleared... " << endl;
	cout << aPara1 << endl;

	////////////////////////////////////////////////////////
	
	//Node Stack Tests
	//Tests all functions in Node Stack Class
	cout << "Node Stack Tests" << endl << endl;
	cout << "Testing Default Constructor" << endl;
	NodeStack<int> nDef1;
	NodeStack<double> nDef2;
	cout << nDef1 << endl;
	cout << nDef2 << endl<<endl;

	cout << "Testing Parameterized Constructor" << endl;
	NodeStack<int> nPara1(7, 6);
	NodeStack<double> nPara2(6, 7.8);
	cout << nPara1 << endl;
	cout << nPara2 << endl<<endl;

	cout << "Testing Copy Constructor" << endl;
	NodeStack<int> nCopy1(nPara1);
	NodeStack<double> nCopy2(nPara2);
	cout << nCopy1 << endl;
	cout << nCopy2 << endl<<endl;

	cout << "Testing Assignment operator" << endl;
	NodeStack<int> nAssign1;
	NodeStack<double> nAssign2;
	nAssign1 = nCopy1;
	nAssign2 = nCopy2;
	cout << nCopy1 << endl;
	cout << nCopy2 << endl <<endl;

	cout << "Testing Top Function" << endl;
	cout << nPara1.top() << endl <<endl;
	cout << "Testing Push Function" << endl;
	nPara1.push(3762);
	cout << nPara1 << endl;
	cout << "Testing Pop Function" << endl;
	nPara1.pop();
	cout << nPara1 << endl << endl;

	cout << "Testing Size, Empty, and Full Functions" << endl;
	cout << "Size: " << nPara1.size() << endl;
	cout << "Empty: " << std::boolalpha << nPara1.empty() << endl;
	cout << "Full: " << std::boolalpha << nPara1.full() << endl;

	cout << "Testing Clear Function" << endl;
	nPara1.clear();
	cout << "Cleared... " << endl;
	cout << nPara1 << endl;


return 0;
}
