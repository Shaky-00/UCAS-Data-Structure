#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;
typedef int status;
typedef struct LNode{
	ElemType elem;
	struct LNode *next;
}LNode, LinkedList;
int count = 0;
LinkedList *CreateList_L()
{
	LinkedList *L, *p;
	ElemType c;
	int i;
	L = (LinkedList *)malloc(sizeof(LNode));
	L->next = NULL;

	while((c = getchar()) != '\n')
	{
		p = (LinkedList *)malloc(sizeof(LNode));
		p->elem = c;
		p->next = L->next;
		L->next = p;
		count++;
	}
	return L;
}

int main()
{
	LinkedList *L = CreateList_L();
	LinkedList *p;
	p = L;
	p = L->next;
	int i = 0;
	while(i < count)
	{
		printf("%c", p->elem);
		p = p->next;
		i++;
	}
	
	return 0;
}


