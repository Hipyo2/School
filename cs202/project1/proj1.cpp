//Project 1
//Libraries and Constants
#include <iostream>
#include <fstream>
using namespace std;
#define fileEntries 10
#define nameLength 8
#define maxstr 100

//Function Prototypes
int readNames(char nameArray [][nameLength+1], int numbers[fileEntries], ifstream &infile, int nameNum);
void printNamesToTerminal(char nameArray [][nameLength+1], int numbers[fileEntries],int nameNum);
void myStringCopy(char destination[nameLength+1],const char source[nameLength+1]);
int myStringCompare(const char string1[nameLength+1],const char string2[nameLength+1]);
void sortNamesAlphabetic(char nameArray [][nameLength+1], int numbers[fileEntries],int nameNum);
int myStringLength(const char str[nameLength+1]);
void sortNamesByLength(char nameArray[][nameLength+1],int numbers[fileEntries],int nameNum);
void printNamesToFile(char nameArray[][nameLength+1],int numbers[fileEntries], int nameNum, ofstream &outfile);

int main ()
{
	//Declaring arrays and variables
	char namesArray[fileEntries][nameLength+1];
	char inputfile [maxstr];
	int associatedNum[fileEntries];
	int nameAmount=0;
	char outputfile [maxstr];

	//Set up files and Prompt user for input/output files
	ofstream outfile;
	ifstream infile;
	cout << "Please enter the name of the input file." << endl;
	cin >> inputfile;
	cout << "Please enter the name of the output file." << endl;
	cin >> outputfile;
	infile.open(inputfile);
	outfile.open(outputfile);

	//Read Names into Array using Read Names Function
	nameAmount = readNames(namesArray, associatedNum, infile, nameAmount);

	//Printing to Terminal and File using Print to Terminal and Print to File functions
	cout << "Unsorted Data (Original Input Order and Name)" << endl << "=============================================" << endl;
	printNamesToTerminal(namesArray, associatedNum, nameAmount);
	outfile << "Unsorted Data (Original Input Order and Name)" << endl << "=============================================" << endl;
	printNamesToFile(namesArray, associatedNum, nameAmount, outfile);
	cout << "Alphabetically Sorted Data (Original Input Order and Name)" << endl << "=============================================" << endl;
	sortNamesAlphabetic(namesArray, associatedNum, nameAmount);
	printNamesToTerminal(namesArray, associatedNum, nameAmount);
	outfile << "Alphabetically Sorted Data (Original Input Order and Name)" << endl << "=============================================" << endl;
	printNamesToFile(namesArray, associatedNum, nameAmount, outfile);
	cout << "Sorted-By-Length -and- Alphabetically Data  (Original Input Order and Name)" << endl << "=============================================" << endl;
	sortNamesByLength(namesArray, associatedNum, nameAmount);
	printNamesToTerminal(namesArray, associatedNum, nameAmount);
	outfile << "Sorted-By-Length -and- Alphabetically Data  (Original Input Order and Name)" << endl << "=============================================" << endl;
	printNamesToFile(namesArray, associatedNum, nameAmount, outfile);
	return 0;
}

int readNames(char nameArray [][nameLength+1], int numbers[fileEntries], ifstream &infile, int nameNum)
{
	//Sets up initial order and reads names from input file into array.
	for (int i =0; i< fileEntries+1; i++)
	{
		numbers[i] = i;
		infile >> nameArray[i];
		nameArray[i][nameLength+1] = '\0';
		//File ends so stop, finds amount of names in file
		if(infile.eof())
		{
			nameNum = i+1;
			break;
		}
	}
	return nameNum;
}

void printNamesToTerminal(char nameArray [][nameLength+1], int numbers[fileEntries],int nameNum)
{
	//Prints Names and Associated Number to Terminal
	for (int i =0; i< nameNum; i++)
	{
		cout << numbers[i] << " " << nameArray[i] << endl;
	}
	cout << endl;
}

int myStringCompare(const char string1[nameLength+1],const char string2[nameLength+1])
{
	//Compares each letter to see which string should go first
	int i=0;
	for(i=0; string1[i] != '\0' || string2[i] !='\0';++i)
	{
		if (string1[i] < string2[i])
		{
			return 1;
		}
		else if(string1[i] > string2[i])
		{
			return -1;
		}
		if (string1[i] == string2[i])
		{
			if (string1[i] < string2[i])
			{
				return 1;
			}
			else if(string1[i] > string2[i])
			{
				return -1;
			}
		}
	}
	return 0;
}

void myStringCopy(char destination[nameLength+1],const char source[nameLength+1])
{
	//Copies string from source to destination string
	int i=0;
	for(i = 0; source[i] != '\0';i++)
	{
		destination[i] = source[i];
	}
	destination[i] = '\0';
}

void sortNamesAlphabetic(char nameArray [][nameLength+1], int numbers[fileEntries],int nameNum)
{
	//Sorts names alphabetically using myStringCompare Function and myStringCopy
	//Temporary values to hold swapping numbers
	char temp[nameLength+1];
	int tempNum;
	for(int r=1; r<=nameNum-1;r++)
	{
		for(int i=0; i<=nameNum-r-1;i++)
		{
			if(myStringCompare(nameArray[i], nameArray[i+1])<0)
			{
				//Swaps based on alphabet, associated number goes along with associated string
				myStringCopy(temp,nameArray[i]);
				tempNum = numbers[i];
				myStringCopy(nameArray[i],nameArray[i+1]);
				numbers[i] = numbers[i+1];
				myStringCopy(nameArray[i+1],temp);
				numbers[i+1] = tempNum;
			}
		}
	}
}

int myStringLength(const char str[nameLength+1])
{
	//Checks the length of a string
	int length;
	for(length = 0; str[length] != '\0'; length++)
	{
	}

	return length;
}

void sortNamesByLength(char nameArray[][nameLength+1],int numbers[fileEntries],int nameNum)
{
	//Sorts names by length using myStringCompare Function and myStringCopy
	//Temporary values to hold swapping numbers
	char temp[nameLength+1];
	int tempNum;
	for(int r=1; r<=nameNum-1;r++)
	{
		for(int i=0; i<=nameNum-r-1;i++)
		{
			//Swaps based on length, associated number goes along with associated string
			if(myStringLength(nameArray[i]) > myStringLength(nameArray[i+1]))
			{
				myStringCopy(temp,nameArray[i]);
				tempNum = numbers[i];
				myStringCopy(nameArray[i],nameArray[i+1]);
				numbers[i] = numbers[i+1];
				myStringCopy(nameArray[i+1],temp);
				numbers[i+1] = tempNum;
			//If length is equal, sorts by alphabet
				if (myStringLength(nameArray[i]) == myStringLength(nameArray[i+1]))
				{
					sortNamesAlphabetic(nameArray,numbers,nameNum);
				}
			}
		}
	}
}

void printNamesToFile(char nameArray[][nameLength+1],int numbers[fileEntries], int nameNum, ofstream &outfile)
{
	//Prints Names and Associated Number to output file
	for (int i =0; i< nameNum; i++)
	{
		outfile << numbers[i] << " " << nameArray[i] << endl;
	}
	outfile << endl;

}
