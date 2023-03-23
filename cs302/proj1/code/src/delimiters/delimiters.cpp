//--------------------------------------------------------------------
//
//   delimiters.cpp
//
//--------------------------------------------------------------------

#include <iostream>

#   include "StackLinked.cpp"


using namespace std;
//--------------------------------------------------------------------

bool delimitersOk ( const string &expression );

//--------------------------------------------------------------------

int main()
{
/*    string inputLine;            // Input line
    char   ch;                   // Holding pen for input chars

    cout << "This program checks for properly matched delimiters."
         << endl;

    while( cin )
    {
        cout << "Enter delimited expression (<EOF> to quit) : "
             << endl;

        // Read in one line
        inputLine = "";
        cin.get(ch);
        while( cin && ch != '\n' )
        {
            inputLine = inputLine + ch;
            cin.get(ch);
        }

        if( ! cin )              // Reached EOF: stop processing
            break;
    
        if ( delimitersOk (inputLine) )
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
    }*/

	//My Menu
	int caseNum;
	//Input String
	string input;
	do
	{
		cout << "MENU" << endl << "1. Test Cases" << endl << "2. Check Delimited Expression" << endl << "3. Exit" << endl;
		cin >> caseNum;
		switch(caseNum)
		{
			//5 sample test cases to test delimitersOk function
			case 1: cout << "TEST CASES" << endl;
				cout << "1. [3*({1+2})]{6+2} " << (delimitersOk("[({1+2})]{}") ? "Valid" : "Invalid") << endl;
				cout << "2. a=(f(b)-(c+2)/2 " << (delimitersOk("a=(f(b)-(c+2)/2") ? "Valid" : "Invalid") << endl;
				cout << "3. a=(f(b)-(c+2)/2) " << (delimitersOk("a=(f(b)-(c+2)/2)") ? "Valid" : "Invalid") << endl;
				cout << "4. }}}}}{} " << (delimitersOk("}}}}}{}") ? "Valid" : "Invalid") << endl;
				cout << "5. []] " << (delimitersOk("[]]") ? "Valid" : "Invalid") << endl;
				break;

			//Input your delimited expression - Outputs valid or invalid based on proper matching delimiters
			case 2: input = "";
				cout << "Input delimited expression" << endl;
				cin.ignore();
				getline(cin,input);
				if ( delimitersOk (input) )
				{
          				cout << "Valid" << endl;
				}
       				else
				{
            				cout << "Invalid" << endl;
				}
				break;

			//Exits Program
			case 3: break;

		}
	}
	while(caseNum != 3);

	return 0;
}

//--------------------------------------------------------------------
// delimitersOk: the function that students must implement for 
//    Programming Exercise 3.
// Note: we used the term "braces" to describe '[' and ']'. It would
//    have been better to use the term "brackets". The program can be
//    easily modified to process any set of matching delimiters.
//--------------------------------------------------------------------

// Insert your delimitersOk function below


//DelimitersOk Function
//Uses stacks to find and process matching delimiters in a string. Outputs true when delimiters are all matching properly and false when there are mismatching or misused delimiters
bool delimitersOk ( const string &expression )
{
	StackLinked<char> stack;
	char c;

	//Loops through string, checking each character for delimiters
	for(int i = 0; i < expression.length(); i++)
	{
		c = expression[i];
		//If left side delimiter found, push onto stack
		if(c == '(' || c == '{' || c == '[')
		{
			stack.push(expression[i]);
		}
		//If right side delimiter found, check if empty stack before checking popped character
		//If empty, returns false
		//If a left side delimiter is popped but is not matching, return false
		else if(c == ')')
		{
			if(stack.isEmpty())
			{
				return false;
			}
			else if(stack.pop() != '(')
			{
				return false;
			}
		}
		else if(c == '}')
		{
			if(stack.isEmpty())
			{
				return false;
			}
			else if(stack.pop() != '{')
			{
				return false;
			}
		}
		else if(c == ']')
		{
			if(stack.isEmpty())
			{
				return false;
			}
			else if(stack.pop() != '[')
			{
				return false;
			}
		}
	}
	//Returns true if stack is empty and all values and delimiters are matching properly
	return stack.isEmpty();
}
