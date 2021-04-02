#include<stdio.h>
#define SIZE 20
int len1 = 0;
int len2 = 0;
int minlen = 0;
int state = 0;
int strCompare(char S[], char T[])
{
	int i;
	for(i=0; i<minlen; i++)
	{
		if(S[i] == T[i])
			continue;
		else if(S[i] > T[i]){
			state = 1;
			return 1;
		}else{
			state = 1;
			return -1;
		}	
	}
	if(len1 == len2 && state == 0)
		return 0;
	else if(len1 > len2 && state == 0)
		return 1;
	else if(len1 < len2 && state == 0)
		return -1;
 } 
 
int main()
{
	int i=0, j=0, k=0;
	char input[20];
	int length;
	do
	{
		scanf("%c", &input[i]);
		i++;
	}while(input[i-1] != '\n');
	length = i-1;

	char str1[20], str2[20];
	int string = 1;
	i = 0;
	j = 0;
	for(k=0; k<length; k++)
	{
		if(input[k] == ' '){
			string = 2;
			continue;
		}
		if(string == 1)
		{
			str1[i] = input[k];
			i++;
		}
		if(string == 2)
		{
			str2[j] = input[k];
			j++;
		}		
	}
	len1 = i;
	len2 = j;
	
	if(len1 >= len2)
		minlen = len2;
	else
		minlen = len1;
		
	printf("%d", strCompare(str1, str2));
	
	return 0;
}
