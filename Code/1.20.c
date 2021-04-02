#include<stdio.h>

int mishu(int n, int x);
int main()
{
	int m;
	int n;
	int x;
	scanf("%d %d", &n, &x);

    int a[n+1];
    int sum = 0;
    int i,j;

    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    for(j=0; j<n; j++)
    {
    	m = mishu(j, x);
		sum = sum + a[j] * m;
    }

    printf("%d", sum);
}

int mishu(int n, int x)
{
    int i;
    int result = 1;
    for(i=0; i<n; i++){
        result *= x;
    }

    return result;
}


