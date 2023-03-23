
#include <iostream>
#include <fstream>
using namespace std;
void solVector(char opt[], char sol[]);

#define matrixSize 10

void solVector(char opt[], char sol[])
{
for(int i = matrixSize-1; i >= 0; i--)
{
if(opt[i] == 'B')
{
sol[i] = 'B';
sol[i-1] = 'B';
sol[i-2] = 'B';
sol[i-3] = 'B';
i = i-3;
}
else
{
sol[i] = 'A';
}
}
}

int main()
{
char c[] = {'A','B','A','B','A','A','B','A','A','A'};
char s[matrixSize];

for(int j = 0; j < matrixSize; j++)
	{
		cout << endl << c[j] << " ";
	}
	cout << endl;
solVector(c, s);
for(int j = 0; j < matrixSize; j++)
	{
		cout << endl << s[j] << " ";
	}
return 0;
}
