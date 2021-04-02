#include<stdio.h>
#define MAXSTRING 100

typedef unsigned char string[MAXSTRING + 1];

int main()
{
	int i = 0;
	string array[MAXSTRING];
	char c;
	while((c = getchar()) != '\n')
	{
		array[i] = c;
		i++;
	}
	
	for(i=0; i<MAXSTRING; i++)
	{
		if(array[i] == array[i+1])
		{
			printf("%c", string[i]);
		}
		else
			break;
	}
	
	printf("%c", string[i--]);
 } 
