#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}LinkNode, *LinkList;

void CreateList(LinkList *L)
{
	char c;
	LinkNode *p, *q;
	*L = (LinkNode *)malloc(sizeof(LinkNode));
	p = *L;
	q = p;
	scanf("%d", &p->data);
	p->next = NULL;
	while((c = getchar()) != ';'){
		p = (LinkNode *)malloc(sizeof(LinkNode));
		scanf("%d", &p->data);
		p->next = NULL;
		q->next = p;
		q = p;
	}
	p->next = *L;
}

LinkNode *h, *t, *p, *q;
void Traverse(LinkList *L, int target)
{
	printf("%d", t->data);
	if(t->data == target)
		return ;
	else
		printf(",");
	
	LinkNode *ptr;
	if(target < t->data)
		ptr = h;
	else
		ptr = t->next;

	while(ptr->data != target)
	{
		printf("%d,", ptr->data);
		ptr = ptr->next;
	}
	printf("%d", ptr->data);
	t = ptr;
	return ;
}

int main()
{
	LinkList L;
	
	CreateList(&L);
	p = L;
	q = (L)->next;
	while(q != L)//定位最小关键字位置 
	{
		if(q->data > p->data)
			q = q->next;
		else{
			p = q;
			q = q->next;
		}
	}
	h = p;
	t = h;
	int target;
	char c;
	int printstate = 0;
	do{
		if(printstate == 1)
			printf(";");
		else
			printstate = 1;
		scanf("%d", &target);
		Traverse(&L, target);
	}while((c = getchar()) != '\n');
	return 0;
}
