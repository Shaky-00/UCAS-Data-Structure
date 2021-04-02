#include<stdio.h>

int test(int a, int b)
{
	if(a>0 && b>=0)
		return test(a-1, 2*b)+b;
}
int main()
{
	int m, n;
	char c;
	int result;
	scanf("%d %c %d", &m, &c, &n);
	
	result = test(m, n);
	printf("%d", result);
	return 0;
}
