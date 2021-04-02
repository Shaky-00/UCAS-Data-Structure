#include<stdio.h>
#define SIZE 20
int main()
{
	char v[SIZE];
	int i=0, k=1;
	char c;
	v[0] = '0';
	for(i=0; v[i]!='@'; i++)
	{
		scanf("%c", &v[i+1]);
	}
	
	int state = 1;
	while((v[i-1] == v[k]) && (i-1 > k))
	{
		--i;
		++k;
	}
	
	if(i-1 > k)
	{
		printf("0");
		state = 0;
	}
	
	if(state == 1)
		printf("1");
		
	return 0;
		
}
