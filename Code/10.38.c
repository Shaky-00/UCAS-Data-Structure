#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1000

typedef struct
{
    int length;
    int r[MAXSIZE+1];
} SqNode, *SqList;


void Merge(int SR[], int TR[], int i, int m, int n)
{
	int j, k, l;
	for(j=m+1, k=i; i<=m && j<=n; k++)
	{
		if(SR[i] < SR[j])
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	}
	if(i <= m)
	{
		for(l=0; l<=m-i; l++)
			TR[k+l] = SR[i+l];
	}
	if(j <= n)
	{
		for(l=0; l<=n-j; l++)
			TR[k+l] = SR[j+l];
	}
}

void MSort(int SR[], int TR1[], int s, int t)
{
	int m;
	int TR2[MAXSIZE+1];
	if(s == t)
		TR1[s] = SR[s];
	else{
		m = (s+t)/2;
		MSort(SR, TR2, s, m);
		MSort(SR, TR2, m+1, t);
		Merge(TR2, TR1, s, m, t);
	}
}

void MergeSort(SqNode *L)
{
	MSort(L->r, L->r, 1, L->length);
}

void CreateList(SqNode *L)
{
    int i = 1;
    char c;
    do
    {
        scanf("%d", &L->r[i]);
        i++;
    } while ((c = getchar()) != '\n');
    L->length = i-1;
}


void PrintList(SqNode *L)
{
    int i;
    int printstate = 0;
    for (i = 1; i <= L->length; i++)
    {
    	if(printstate == 0)
    	{
    		printf("%d", L->r[i]);
    		printstate = 1;
		}else
        	printf(" %d", L->r[i]);
    }
}

int main()
{
	SqList L;
    L = (SqNode *)malloc(sizeof(SqNode));
    CreateList(L);
    MergeSort(L);
    PrintList(L);
    
    return 0;
}
