#include "my_string.h"

char *myStringCopy(char *destination,const char *source)
{
	//Copies string from source to destination string
	int i=0;
	for(i = 0; *source != '\0';i++ && source++ && destination++)
	{
		*destination = *source;
	}
	*destination = '\0';
	return destination;
}

int myStringCompare(const char *string1,const char *string2)
{
	//Compares each letter to see which string should go first
	int i=0;
	for(i=0; *string1 != '\0' || *string2 !='\0';++i && string1++ && string2++)
	{
		if (*string1 < *string2)
		{
			return 1;
		}
		else if(*string1 > *string2)
		{
			return -1;
		}
		if (*string1 == *string2)
		{
			if (*string1 < *string2)
			{
				return 1;
			}
			else if(*string1 > *string2)
			{
				return -1;
			}
		}
	}
	return 0;
}

size_t myStringLength(const char *str)
{
	//Checks the length of a string
	int length;
	for(length = 0; *str != '\0'; length++)
	{
	str++;
	}

	return length;
}

char *myStringCat(char *destination, const char *source)
{
for(int i=0; *destination != '\0'; destination++ && i++)
{
}

for(int i=0; *source != '\0'; i++)
{
*destination = *source;
destination++;
source++;
}
*destination = '\0';
return destination;
}
