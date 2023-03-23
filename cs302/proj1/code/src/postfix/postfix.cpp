//Postfix.cpp

//Libraries and Header Files
#include <iostream>
#include <string.h>
#include "Stack.h"
#include "StackLinked.h"
#include "StackLinked.cpp"

using namespace std;


//Function Declarations
double evalPostfix(std::string equation, StackLinked<double> &stack);
double powerPos(double a, double b);


//Main function
int main ()
{
	int caseNum;
	StackLinked<double> stack;
	string input;
	//Menu Interface
	do
	{
		cout << "MENU" << endl << "1. Test Cases" << endl << "2. Postfix Calculation" << endl << "3. Exit" << endl;
		cin >> caseNum;
		switch(caseNum)
		{
			//5 Sample Test Cases to test the evalPostfix function
			case 1: cout << "TEST CASES" << endl;
				cout << "1. 1+2+(3*4) = 1 2 + 3 4 * + = "<< evalPostfix("1 2 + 3 4 * +", stack)  << endl;
				cout << "2. 2^(2^(2^2)) = 2 2 2 2 ^ ^ ^ = " << evalPostfix("2 2 2 2 ^ ^ ^", stack) << endl;
				cout << "3. 4+7+(9*(4/2)) = 4 7 + 9 4 * 2 / + = " << evalPostfix("4 7 + 9 4 * 2 / +", stack) << endl;
				cout << "4. (3^2)+(8/4)-6 = 3 2 ^ 8 4 / + 6 - = " << evalPostfix("3 2 ^ 8 4 / + 6 -", stack) << endl;
				cout << "5. 9-6+(((1*3)*2)/4) = 9 6 - 1 3 * 2 * 4 / + = " << evalPostfix("9 6 - 1 3 * 2 * 4 / +", stack) << endl << endl;
				break;

			//Input your own equation to be evaluated. Only evaluates with VALID Equations in Postfix
			case 2: input = "";
				cout << "Input postfix equation" << endl;
				cin.ignore();
				getline(cin,input);
				cout << "Evaluated: " << evalPostfix(input, stack) << endl;
				break;

			//Exits Program
			case 3: break;

		}
	}
	while(caseNum != 3);

	return 0;
}

//Evaluates a postfix equation and returns a double type value
double evalPostfix(std::string equation, StackLinked<double> &stack)
{
	char c;
	double op1, op2, value;
	//Clears Stack so nothing is inside and could potentially mess up the postfix evaluation
	if(!stack.isEmpty())
	{
		stack.clear();
	}

	//Loops through equation string to push digits on the stack and when operator is found, evaluate the top two values in the stack
	for(int i = 0; i < equation.length(); i++)
	{
		c = equation[i];
		//Pushes digit onto stack and converts from char to float value
		if(c >= '0' && c <= '9')
		{
			stack.push(c - '0');
		}
		//Adds two operands and pushes value onto stack for further evaluation
		else if(c == '+')
		{
			op1 = stack.pop();
			op2 = stack.pop();
			value = op2 + op1;
			stack.push(value);
		}
		//Subtracts two operands in correct order and pushes value onto stack for further evaluation
		else if(c == '-')
		{
			op1 = stack.pop();
			op2 = stack.pop();
			value = op2 - op1;
			stack.push(value);
		}
		//Multiplies two operands and pushes value onto stack for further evaluation
		else if(c == '*')
		{
			op1 = stack.pop();
			op2 = stack.pop();
			value = op2 * op1;
			stack.push(value);
		}
		//Divides the two operands in correct order and pushes value onto stack for further evaluation
		else if(c == '/')
		{
			op1 = stack.pop();
			op2 = stack.pop();
			value = op2 / op1;
			stack.push(value);
		}
		//Calls the powerPos function to calculate exponents and pushes value back onto the stack for further evaluation
		else if(c == '^')
		{
			op1 = stack.pop();
			op2 = stack.pop();
			value = powerPos(op2, op1);
			stack.push(value);
		}
		//Do nothing when a space is found
		else if(c == ' ')
		{

		}
	}
	//Returns fully evaluated answer
	return stack.pop();

}

//Power function for exponents
//Recursively multiplies value A by itself B times
double powerPos(double a, double b)
{
	if (b > 0)
	{
		return a * powerPos(a, b-1);
	}
	//When the exponent becomes 0, A to the power of 0 is 1
	else
	{
		return 1;
	}
}
