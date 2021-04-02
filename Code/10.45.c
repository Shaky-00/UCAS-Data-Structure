#include<stdio.h>
#include<stdlib.h> 
#include<math.h>

typedef struct List
{
	int digNum;
	int length;
	int data[10];
 } List;
 
int dig = 0;
void RadixPass(int *source, int *pass, int *count, int *pos, int length)
{
	dig++;
	int i;
	for(i=0; i<length; i++)
	{
		int bit = source[i] % (int)pow(10, dig) / pow(10, dig-1);
		count[bit]++;
	}
	pos[0] = 0;
	for(i=1; i<=length+1; i++)
		pos[i] = pos[i-1] + count[i-1];
		
	for(i=0; i<length; i++)
	{
		int bit = source[i] % (int)pow(10, dig) / pow(10, dig-1);
		pass[pos[bit]++] = source[i];
	}
}


void *RadixSort(List *list)
 {
 	int i, j;
 	int count[10];
 	int pos[10];
 	int *list1 = malloc(sizeof(int) * list->length);
 	for(i=1; i<=list->digNum; i++)
 	{
 		for(j=0; j<10; j++)
 		{
 			count[j] = 0;
		}
		if(i % 2 != 0)
		 	RadixPass(list->data, list1, count, pos, list->length);
		else
			RadixPass(list1, list->data, count, pos, list->length);
	}
	if(list->digNum % 2 != 0)
	{
		for(i=0; i<list->length; i++)
			list->data[i] = list1[i];
	}
	//return list;
 }

void CreateList(List *list)
{
	int i;
	list->digNum = 3;
	list->length = 10;
	for(i=0; i<10; i++)
	{
		scanf("%d", &list->data[i]);
	}
}

void PrintList(List *list)
{
	int i;
	int printstate = 0;
	for(i=0; i<10; i++)
	{
		if(printstate == 1)
			printf(" ");
		else
			printstate = 1;
		if(list->data[i] < 10)
			printf("00%d", list->data[i]);
		else if(list->data[i] >= 10 && list->data[i] < 100)
			printf("0%d", list->data[i]);
		else
			printf("%d", list->data[i]);
	}
}
int main()
{
	List L;
	CreateList(&L);
	RadixSort(&L);
	PrintList(&L);
	
	return 0;
}
