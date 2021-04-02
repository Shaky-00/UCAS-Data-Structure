#include<stdio.h>
#define SIZE 20

/*
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
}*/

int judge(int T[], int son, int parent)
{
	if(T[son] == parent)
		return 1;
	else{
		if(T[son] && judge(T, T[son], parent))
			return 1;
	}
	
	return 0;	
}

int main()
{
	char c;
	int k;
	int A[SIZE+1], B[SIZE+1], T[SIZE+1];
	for(k=0; k<=SIZE; k++)
	{
		T[k] = 0;
	}
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
				if(A[i] != 0)
				{
					T[A[i]] = i;
				}
				i++;
				c = getchar();
			}else if (next == 1){
				scanf("%d", &B[j]);
				if(B[j] != 0)
				{
					T[B[j]] = j;
				}
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
	 
	printf("%d", judge(T, son, parent));
	
	return 0;
}
