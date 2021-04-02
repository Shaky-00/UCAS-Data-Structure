#include<stdio.h>

int main()
{
	int row, col;
	int i=0, j=0, count = 0;
	int length = 1;
	char c;
	int temp;
	scanf("%d;%d;", &row, &col);
	for(i=0; i<row; i++)
	{
		length *= col;
	}
	
	i = 0;
	int m[length];
	int target;
	while((c = getchar()) != '\n'){	
		if(c >= '0' && c <= '9'){
			target = c - '0';
			while((c = getchar()) >= '0' && c <='9')
			{
				target = target * 10 + c - '0';
			}
			m[i] = target;
			i++;
		}	
	}
	
	int k;
	for(i=length-1; i>=0; i--)
	{
		if(m[i] != 0){
			if(m[i] != 1 || i == 0)
				printf("%d", m[i]);
			for(k=1; k<=row; k++)
			{
				temp = i;
				for(j=0; j<row-k; j++)
				{
					temp = temp / col;
				}
				if(temp%col == 1)
				{
					printf("x%d", k);
				}else if(temp%col != 0)
					printf("x%dE%d", k, temp%col);
			}
		}
		if(i != 0 && m[i] != 0)
			printf("+");
	}
	
	return 0;
}
