#include<stdio.h> 
#include<stdlib.h>
typedef char ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, LinkedList; 

int count;
LinkedList *CreateList_L(LinkedList *head)
{
	LinkedList *p, *q;
	ElemType n, temp;
	head = p = (LinkedList *)malloc(sizeof(LinkedList));

	int i=0;
	getchar();
	for(i=0; i<count-1; i++)
	{
		q = (LinkedList *)malloc(sizeof(LNode));
		p->next = q;
		scanf("%c,", &q->data);
		q->next = head;
		p = q;
	}
	q = (LinkedList *)malloc(sizeof(LNode));
	scanf("%c", &q->data);
	p->next = q;
	q->next = head;	
	
	return head;
}

void printList(LinkedList *p)
{
	int i = 1;
	printf("%c", p->data);
	p = p->next;
	while(i < count)
	{
		printf(",%c", p->data);
		p = p->next;
		i++;
	}
}

int main()
{
	scanf("%d", &count);
	LinkedList *L;

	L = CreateList_L(L);
	printList(L->next);
	
	return 0;
}
