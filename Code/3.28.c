#include<stdio.h>

int main()
{
	int n;
	int i;
	scanf("%d", &n);
	char array[2*n-1];
	
	for(i=0; i<2*n-1; i++)
	{
		scanf(" %c", &array[i]);
	}
	
	for(i=0; i<2*n-1; i++)
	{
		printf("%c", array[i]);
	}
	
	return 0;
 } 
