#include<stdio.h>
#include<stdlib.h>
#define SIZE 30
int n;
typedef int ElemType;
typedef int status;
typedef struct LNode{
	ElemType elem;
	struct LNode *next;
	struct LNode *prior;
	int freq;
}LNode, LinkedList;
int count = 0;

LinkedList *CreateList_L(LinkedList *head)
{
	LinkedList *p, *q;
	ElemType n, temp;
	head = p = (LinkedList *)malloc(sizeof(LinkedList));
	head->prior = NULL;
	head->freq = 0;
	int i=0;

	while(i < count)
	{
		scanf("%d", &n);
		q = (LinkedList *)malloc(sizeof(LinkedList));
		p->next = q;
		q->prior = p;
		p = p->next;
		q->elem = n;
		q->freq = 0;	
		i++;
	}
	q->next = head;	
	head->prior = q;
	return head;
}


void printList(LinkedList *p)
{
	int i = 1;
	printf("%d", p->elem);
	p = p->next;
	while(i < count)
	{
		printf(" %d", p->elem);
		p = p->next;
		i++;
	}
}

LinkedList *LocateElem(LinkedList *L, ElemType x)
{   
    LinkedList *p, *q;   
    p = L;   
    q = p->next;   
    while(q != L && q->elem != x)
	{
		q = q->next;
	}  
           
    if(q!=L)
    {  
        q->freq++;   
        p = q->next;   
        p->prior = q->prior;
		q->prior->next = p;   
        p = L->next;
        while(p!=L && p->freq >= q->freq)    
            p = p->next;   
        q->next = p;   
        p->prior->next = q;   
        q->prior = p->prior;   
        p->prior = q;   
        return p;   
    }   
} 

int main()
{
	scanf("%d", &count);
	LinkedList *L;
	ElemType x[SIZE];
	ElemType c;
	L = CreateList_L(L);

	int i = 0, j = 0, k = 0;
	int input = 0;
	int time[SIZE];
    int flag[SIZE];  
    char ch;
	for(j=0;j<SIZE;j++)
    {
       	x[j] = 0;
        time[j] = 0;
		flag[j] = 0;
    }

    do
    {
        scanf("%d", &input);
        time[input]++;
        if (flag[input] != 1)
        {
            x[i] = input;
            i++;
        }
        flag[input] = 1;
    }while((ch=getchar())!='\n'&&ch!=EOF);
    

    for(j=0;j<i;j++)
    {
        for (k=0;k<time[x[j]];k++)
        {
            LocateElem(L, x[j]);
        }
    }
        
	printList(L->next);
	
	return 0;
}


