#include<stdio.h>

int main()
{
	int row, col;
	int i=0, j=0, count = 0;
	scanf("%d;%d;", &row, &col);
	int m[row*col+1];
	getchar();
	for(i=0; i<row; i++)
	{
		getchar();
		scanf("%d", &m[count++]);
		for(j=1; j<col; j++)
			scanf(",%d", &m[count++]);
		getchar();
		getchar();
	}
	
	int sign = 0;
	printf("[");
	for(i=0; i<count; i++)
	{
		if(m[i] != 0)
			if(sign == 1)
				printf(",%d", m[i]);
			else if(sign == 0){
				printf("%d", m[i]);
				sign = 1;
			}				
	}
	printf("];[");
	
	int pick = 0;
	for(i=0; i<row; i++)
	{
		printf("[");
		if(m[pick++] == 0)
			printf("0");
		else
			printf("1");
		for(j=1; j<col; j++)
		{
			if(m[pick++] == 0)
				printf(",0");
			else
				printf(",1");
		}
		if(pick / col == row)
			printf("]");
		else
			printf("];");
	}
	printf("]");
	
	return 0;
 } 
