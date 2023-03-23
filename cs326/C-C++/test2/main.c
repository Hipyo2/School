#include <stdio.h>

void p () 
{ 
 int y; 
 printf ("%d ", y); 
 y = 2; 
}

void callP()
{
    p();
}

void main () 
{

 p();
 callP();
 p(); 
} 
