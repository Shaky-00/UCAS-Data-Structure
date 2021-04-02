#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000

typedef struct
{
    int length;
    int r[MAXSIZE];
} SqNode, *SqList;

void CreateList(SqNode *L)
{
    int i = 0;
    char c;
    do
    {
        scanf("%d", &L->r[i]);
        i++;
    } while ((c = getchar()) != '\n');
    L->length = i;
}

void swap(SqNode *L, int low, int high)
{
    int temp;
    temp = L->r[low];
    L->r[low] = L->r[high];
    L->r[high] = temp;
}

int Partition(SqNode *L, int low, int high)
{
    int pivotkey;
    pivotkey = L->r[low];
    while (low < high)
    {
        while (low < high && L->r[high] >= pivotkey)
            high--;
        swap(L, low, high);
        while (low < high && L->r[low] <= pivotkey)
            low++;
        swap(L, low, high);
    }
    return low;
}

void QSort(SqList L, int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = Partition(L, low, high);
        QSort(L, low, pivot - 1);
        QSort(L, pivot + 1, high);
    }
}

void PrintList(SqNode *L)
{
    int i;
    int printstate = 0;
    for (i = 0; i < L->length; i++)
    {
    	if(printstate == 0)
    	{
    		printf("%d", L->r[i]);
    		printstate = 1;
		}else
        	printf(",%d", L->r[i]);
    }
}

int main()
{
    SqList L;
    L = (SqNode *)malloc(sizeof(SqNode));
    CreateList(L);
	QSort(L, 0, L->length-1);
    PrintList(L);
    return 0;
}
