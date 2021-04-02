#include<stdio.h>

int test(int a)
{
	if(a == 0)
		return a + 1;
	else if(a > 0)
		return a*test(a/2);
	else
		;
}

int main()
{
	int m;
	int result;
	scanf("%d", &m);
	
	result = test(m);
	printf("%d", result);
	return 0;
}
