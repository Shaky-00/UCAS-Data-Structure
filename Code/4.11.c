#include<stdio.h>

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
		if(input[k] == ' ')
		
			string = 2;
				
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
	int len1 = i;
	int len2 = j;
	
	char newstr[20];
	int position[20];
	int count = 0;
	int state = 1;
	for(i=0; i<len1; i++)
	{
		state = 1;
		for(j=0; j<len2; j++)
		{
			if(str1[i] == str2[j])
				state = 0;		
		}//没有与str2中的相同的 
		if(state == 1)
		{
			for(k=0; k<count; k++)
			{
				if(str1[i] == newstr[k])
					state = 0;
			}//没有与已经取出的数相同的 
		}
		
		if(state == 1)
		{
			newstr[count] = str1[i];		
			position[count] = i;
			count++; 
		}
	}

	if(count == 0)
	{
		printf("-1");
		return 0;
	}
	for(i=0; i<count; i++)
	{
		printf("%c", newstr[i]);
	}
	
	printf(" ");
	for(i=0; i<count; i++)
	{
		printf("%d", position[i]);
	}
	return 0;
}
