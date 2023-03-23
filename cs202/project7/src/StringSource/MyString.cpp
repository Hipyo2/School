//Nicholas Ang
//Project 7
//MyString Class source file

//Libraries and Header Files
#include <StringHeader/MyString.h>
#include <string.h>
using namespace std;

//Class Implementations
//Default Constructor
MyString::MyString() : m_buffer(NULL), m_size(0)
{
}

//Parameterized Constructor
MyString::MyString(const char *str) : m_buffer(NULL), m_size(strlen(str))
{
	buffer_allocate(m_size);
	strcpy(m_buffer, str);
}

//Copy Constructor
MyString::MyString(const MyString &other_myStr) : m_buffer(NULL), m_size(other_myStr.m_size)
{
	buffer_allocate(m_size);
	strcpy(m_buffer, other_myStr.m_buffer);
}

//Destructor
MyString::~MyString()
{
	buffer_deallocate();
}

//Deallocates and Frees up the memory used in dynamic memory allocation
void MyString::buffer_deallocate()
{
	//Deletes dynamic array of memory and sets values to NULL
	delete [] m_buffer;
	m_buffer = NULL;
	m_size = 0;
}

//Allocates memory in the freestory for dynamic memory usage
void MyString::buffer_allocate(size_t size)
{

	try
	{
		m_buffer = new char[size+1];
		m_size = size+1;
	}
	//Prevents faulty allocation from going through
	catch(const std::bad_alloc &exception)
	{
	}
}

//Size Function, returns size of string, include \0
size_t MyString::size() const
{
	return m_size;
}

//Length Function, returns length of string, does not include \0
size_t MyString::length() const
{
	return strlen(m_buffer);
}

//C_str function, returns c string from MyString class
const char *MyString::c_str() const
{
	return m_buffer;
}

//Operator overload for <<. Outputs MyString c string information
std::ostream &operator<<(std::ostream &outfile, const MyString &myStr)
{
	outfile << myStr.c_str() << endl;
	return outfile;
}

//Operator overload for =, assigns value of one MyString to another MyString
MyString &MyString::operator=(const MyString &other_myStr)
{
	//Checks if same
	if(this != &other_myStr)
	{
		buffer_allocate(other_myStr.m_size);
		strcpy(m_buffer, other_myStr.m_buffer);
	}
	return *this;
}

//Operator overload for +, Used for concatenation of two strings and returns the new string 
MyString MyString::operator+ (const MyString & other_myStr) const
{
	MyString string;
	string.buffer_allocate(m_size + other_myStr.m_size);
	strcpy(string.m_buffer, c_str());
	strcat(string.m_buffer, other_myStr.m_buffer);
	return string;
}

//Operator overload for ==, checks if two MyStrings are the same and 
//returns true or false based on comparison
bool MyString::operator== (const MyString & other_myStr) const
{
	if(strcmp(m_buffer,other_myStr.m_buffer) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Operator overload for [], returns letter at specific index by reference
//For regular Char
char & MyString::operator[] (size_t index)
{
	return m_buffer[index];
}

//Operator overload for [], returns letter at specific index by reference
//For Const Chars
const char & MyString::operator[] (size_t index) const
{
	return m_buffer[index];
}
