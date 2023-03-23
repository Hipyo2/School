#include <stdio.h>

union
{
int i;
char c;
float f;
}u;

int main()
{
u.c= 'A';
printf("%c \n",u.c);
printf("%d \n",u.i);
printf("%f \n",u.f);
printf("%d \n", u.c);
return 0;
}
/*
int main()
{
int n = 100;
float f=10;
f = *((float *) &n);
printf("%f\n", f);
}*/
/*int main()
{
char myChar;
myChar='A';
myChar=myChar+1;
printf("%c \n",myChar);
printf("%d \n",myChar);
}*/
