#include<stdio.h>

int main()
{
    int i, j;
    int count;
    int a[16], c[16];

    for (i = 1; i < 16; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 1; i < 16; i++)
    {
        count = 0;
        for (j = 1; j < 16; j++)
        {
            if(a[j] < a[i] && i != j)
                count++;
        }
        c[i] = count;
    }
	
	int printstate = 0;
    for (i = 0; i < 15; i++)
    {
    	j=0;
        while(c[j] != i)
        	j++;
        if(printstate == 0)
        {
        	printf("%d", a[j]);
        	printstate = 1;
		}else
        	printf(" %d", a[j]);
    }
    return 0;
}
