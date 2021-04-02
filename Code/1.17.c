#include <stdio.h>
#define n 100

int sum(int m, int k);
int arr[n] = {0};
int main()
{
	int k, m, i;
	scanf("%d %d", &k, &m);
	
	for(i=0; i<k-1; i++)
	{
		arr[i] = 0;
	}
	
	arr[k-1] = 1;
	
	for(i=k; i<n; i++)
	{
		arr[i] = sum(k, i);
	}
	
	printf("%d", arr[m]);
	
	return 0;
	
}

int sum(int k, int m)
{
	int i;
	int value = 0;
	for(i=0; i<k; i++)
	{
		value += arr[m-i-1];
	}
	
	return value;
 } 
