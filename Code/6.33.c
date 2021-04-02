#include<stdio.h>
#define SIZE 20

int judge(int A[], int B[], int son, int parent)
{
	if(A[parent] == son || B[parent] == son)
		return 1;
	else{
		if(A[parent] && judge(A, B, son, A[parent]))
			return 1;
		if(B[parent] && judge(A, B, son, B[parent]))
			return 1;
	}
	
	return 0;	
}

int main()
{
	char c;
	int A[SIZE+1], B[SIZE+1];
	int i=1, j=0;
	int next = 0;
	int son, parent;
	scanf("%d", &A[0]);
	c = getchar();
	while(c != '\n')
	{
		if(c == ',')
		{
			if(next == 0)
			{
				scanf("%d", &A[i]);
				i++;
				c = getchar();
			}else if (next == 1){
				scanf("%d", &B[j]);
				j++;
				c = getchar();
			}else if (next == 2){
				scanf("%d", &son);
				c = getchar();
			}else{
				scanf("%d", &parent);
				c = getchar();
			}			
		}else if(c == ';'){
			next++;
			c = ',';
		}
	 } 
	 
	printf("%d", judge(A, B, son, parent));
	
	return 0;
}
