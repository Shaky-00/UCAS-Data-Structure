#include<stdio.h>
#define MAXSIZE 40
int main()
{
    int lowbound, highbound, cellsize;
    scanf("%d %d %d", &lowbound, &highbound, &cellsize);
    int size = (highbound - lowbound) / cellsize;
    int space[MAXSIZE];
    int i, j=0;
    for(i=0; i<MAXSIZE; i++)
    {
        if(j < size)
        {
            scanf("%d", &space[i]);
            j++;
        }else
            space[i] = -1;
    }

    i = 0;
    int count;
    int printstate = 0;
    while(i < size)
    {
        count = 0;
        while(space[i] != 0 && i < size)
            i++;
        if(i == size)
        	break;
        if(printstate == 0){
        	printf("0 %d ", lowbound + i * cellsize);
        	printstate = 1;
		}else
			printf("\n0 %d ", lowbound + i * cellsize);
        count++;
        while(space[i+1] == 0)
        {
            count++;
            i++;
        }
        i++; 
        printf("%d", count * cellsize);
    }
    if(printstate == 0)
    	printf("0 0 0");
    return 0;
}
