#include <stdio.h>
#include <malloc.h>

typedef struct node
{
    int data;
    struct node *next;
} List;

List *LinkList(List *L1, List *L2)
{
    if (L1 == NULL && L2 == NULL)
        return NULL;
    if (L1 == NULL)
        return L2;
    if (L2 == NULL)
        return L1;
    List *tarList = (List *)malloc(sizeof(List));
    List *p = tarList;

    while (L1 != NULL)
    {
        p->data = L1->data;
        p->next = (List *)malloc(sizeof(List));
        p = p->next;
        L1 = L1->next;
    }

    while (L2->next != NULL)
    {
        p->data = L2->data;
        p->next = (List *)malloc(sizeof(List));
        p = p->next;
        L2 = L2->next;
    }
    p->data = L2->data;
    p->next = NULL;
    return tarList;
}

void printList(List *list) 
{
	printf("%d", list->data);
	list = list->next;
    while (list != NULL)
    {
        printf(" %d", list->data);
        list = list->next;
    }
}

List *CreateList(int n)
{
    if (n == 0)
        return NULL;
    List *list = (List *)malloc(sizeof(List));
    List *ha = list;
    while (n > 1)
    {
        scanf("%d", &ha->data);
        ha->next = (List *)malloc(sizeof(List));
        ha = ha->next;
        n--;
    }
    scanf("%d", &ha->data);
    ha->next = NULL;
    return list;
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    List *L1 = CreateList(m);
    List *L2 = CreateList(n);
    List *L3 = NULL;

	if(m < n)
	{
		L3 = LinkList(L1, L2);
	}else{
		L3 = LinkList(L2, L1);
	}
	
    printList(L3);

    return 0;
}

