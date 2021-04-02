#include<stdio.h>
#define arrsize 300
#define MAXINT 65535

int jiecheng(int n);
int mishu(int n);

int main()
{
    int fin = 1;
    int i = 0;
    int x;
    int a[arrsize];
    int n;
    scanf("%d", &n);
    
    for(i=0; i<n; i++)
    {
        if(i<arrsize && (fin = jiecheng(i)*mishu(i)) <= MAXINT)
        {
            a[i] = fin;
            x = i+1;
        }else{
        	x = i;
            break;
        }
    }
    
    printf("%d", a[x-1]);
    
    return 0;
}

int jiecheng(int n)
{
	int i;
    int result = 1;
    for(i=n; i>0; i--)
    {
        result *= i;
    }
    return result;
}

int mishu(int n)
{
    int result = 1;
    for(; n>0; n--)
    {
        result *= 2;
    }
    return result;
}
