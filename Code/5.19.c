#include<stdio.h>
#define SIZE 100

int main()
{
	int a[SIZE][SIZE];
	char c;
	scanf("%d", &a[0][0]);
	int i=0, j=1;
	int row=0, col=0;
	while((c = getchar()) != '\n')
	{
		if(c == ',')
		{
			scanf("%d", &a[i][j]);
			j++;
		}else if(c == ';'){
			i++;
			row = j;
			j = 0;
			scanf("%d", &a[i][j++]);
		}	
	}
	col = i+1;
	
	int min[col][row];
	int max[col][row];
	for(i=0; i<col; i++)
	{
		for(j=0; j<row; j++)
		{
			min[i][j] = 0;
			max[i][j] = 0;
		}
	}
	
	int Min, Max;
	for(i=0; i<col; i++)
	{
		Min = a[i][0];
		for(j=1; j<row; j++)
		{	
			if(a[i][j] <= Min)
			{
				Min = a[i][j];
			}	
		}
		for(j=0; j<row; j++)
		{
			if(a[i][j] == Min)
				min[i][j] = 1;
		 } 
	}
	
	for(j=0; j<row; j++)
	{
		Max = a[0][j];
		for(i=0; i<col; i++)
		{
			if(a[i][j] > Max)
			{
				Max = a[i][j];
			}
		}
		for(i=0; i<col; i++)
		{
			if(a[i][j] == Max)
				max[i][j] = 1;
		 } 
	 } 
	
	
	int first = 0;
	for(i=0; i<col; i++)
	{
		for(j=0; j<row; j++)
		{
			if(min[i][j] == max[i][j] && min[i][j] == 1)
				if(first == 0)
				{
					printf("%d", a[i][j]);
					first = 1;
				}else
					printf(",%d", a[i][j]);
		}
	}
	
	if(first == 0)
		printf("null");
		
	return 0;
}
