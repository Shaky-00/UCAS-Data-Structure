#include<stdio.h>
#define SIZE 50
int main()
{
	char a[SIZE+1];
	a[0] = SIZE;
	int i = 1;
	int j = 0;
	int pos = 0;
	char c;
	while((c = getchar()) != '\n')
	{
		a[i] = c;
		i++;
	}
	int flag = i;
	int k = 0;
	int max = 0;
	int count = 0;
	int state = 0;//记录是否有重复的部分 
	for(i=1; i<flag; i++)
	{
		for(j=i+1; j<flag; j++)
		{
			while((a[i+k] == a[j+k])!='\0' && i+k < j)
			{
				state = 1;
				count++;
				k++;
			}
			if(state == 1)
				if(count > max){
					max = count;
					pos = i;
				}
			k = 0;	
			count = 0;		
		}
	}
	if(state == 1)
	{
		for(i=pos; i<pos+max; i++)
			printf("%c", a[i]);
		printf(" %d", pos-1);
	}else{
		printf("-1");
	}
	
	return 0;
 } 
