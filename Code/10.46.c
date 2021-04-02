#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int key;
	struct node *next;
}LinkNode;

void CreateList(LinkNode *L)
{
	LinkNode *p, *pre, *ptr;
	char c;
	int data;
	pre = L;
	L->next = NULL;
	do{
		pre = L;
		ptr = L->next;
		scanf("%d", &data);
		p = (LinkNode *)malloc(sizeof(LinkNode));
		p->key = data;
		if(ptr != NULL)
		{
			while(ptr->key <= data)
			{
				pre = ptr;
				ptr = ptr->next;
				if(ptr == NULL)
					break;
			}
			pre->next = p;
			p->next = ptr;
		}else{
			pre->next = p;
			p->next = NULL;
			pre = p;
		}
		
			
	}while((c = getchar()) != '\n');
}

void PrintList(LinkNode *L)
{
	LinkNode *p;
	p = L->next;
	int printstate = 0;
	while(p != NULL)
	{
		if(printstate == 0){
			printf("%d", p->key);
			printstate = 1;
		}else
			printf(" %d", p->key); 
					
		p = p->next;
	}
}

int main()
{
	LinkNode L;
	CreateList(&L);
	PrintList(&L);
}
