#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}LinkNode, *LinkList;

void InsertNode(LinkList L, int x)
{
	LinkNode *p, *pre, *q;
	p = L->next;
	pre = L;
	if(p == NULL)
	{
		p = (LinkNode *)malloc(sizeof(LinkNode));
		p->data = x;
		p->next = NULL;
		L->next = p;
		return ;
	}
	while(p->data < x)
	{
		pre = p;
		p = p->next;
		if(p == NULL)
			break;
	}
	q = (LinkNode *)malloc(sizeof(LinkNode));
	q->data = x;
	pre->next = q;
	q->next = p;
	return ;
}

void PrintList(LinkList L)
{
	LinkNode *p;
	p = L->next;
	int printstate = 0;
	while(p != NULL)
	{
		if(printstate == 1)
			printf(" %d", p->data);
		else{
			printf("%d", p->data);
			printstate = 1;
		}
		p = p->next;
	}
}

int main()
{
	LinkList L;
	int value;
	char c;
	L = (LinkNode *)malloc(sizeof(LinkNode));
	L->next = NULL;
	L->data = 0;
	do{
		scanf("%d", &value);
		InsertNode(L, value);
	}while((c = getchar()) != '\n');
	
	PrintList(L);
	
	return 0;
}
