//Nicholas Ang
//Project 7
//Main Function Source File

//Libraries and Header Files
#include <iostream>
#include <string.h>
#include <StringHeader/MyString.h>
using namespace std;


//Test Driver for Project
int main()
{
	//Default Constructor Test
	cout << "Testing Default ctor" << endl;
	MyString ms_default;
	//Parameterized Ctor test
	cout << "Testing Parameterized ctor" << endl;
	MyString ms_parameterized("MyString parameterized constructor!");
	//Copy ctor test
	cout << "Testing Copy ctor" << endl;
	MyString ms_copy(ms_parameterized);
	//Dtor test
	cout << "Testing dtor" << endl << endl;
	{
		MyString *ms_destroy = new MyString("MyString to be destroyed...");
		delete ms_destroy;
		ms_destroy = NULL;
	}

	//Size and Length Tests
	MyString ms_size_length("Size and length test");
	cout << "Testing size ()" << endl;
	cout << "Size: "<< ms_size_length.size() << endl << endl;
	cout << "Testing length ()" << endl;
	cout << "Length: " << ms_size_length.length() << endl << endl;

	//C string from Class test
	cout<< "Testing c_str ()" << endl;
	MyString ms_toCstring("C-String equivalent successfully obtained!");
	cout << ms_toCstring.c_str() << endl << endl;

	//Operator== test
	cout << "Testing operator==()" << endl;
	MyString ms_same1("The same"), ms_same2("The same");
	if(ms_same1 == ms_same2)
	{
		cout << "Same success" << endl;
	}
	MyString ms_different("The same (NOT)");
	if (!(ms_same1 == ms_different))
	{
		cout << "Different success" << endl << endl;
	}

	//Testing Operator=
	cout << "Testing operator= ()" << endl;
	MyString ms_assign("Before assignment");
	cout << ms_assign;
	ms_assign = MyString("After performing assignment");
	cout << ms_assign << endl;

	//Testing Operator+ for concatenation
	cout << "Testing operator+" << endl;
	MyString ms_append1("The first part");
	MyString ms_append2(" and the second");
	MyString ms_concat = ms_append1 + ms_append2;
	cout << ms_concat << endl;

	//Testing operator[]
	cout << "Testing operator[] ()" << endl;
	MyString ms_access("Access successful (NOT)");
	ms_access[17] = 0;

	//Testing operator <<
	cout << "Testing operator<< ()" << endl;
	cout << ms_access << endl;
	return 0;
}
