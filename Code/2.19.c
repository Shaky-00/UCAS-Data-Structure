
#include<stdio.h>
#include<malloc.h>
#define LEN sizeof(List)
typedef struct node
{
    int data;
    struct node * next;
}List;
int n=0;
int min, max;
List *create(void)
{
    List * head;
    List * p1,* p2;
    int pre = 0;
    p1=(List*)malloc(LEN);
    p2=(List*)malloc(LEN);
    head=NULL;
    scanf("%d",&p1->data);
    while(p1->data > pre)
    {
        n++;
        pre = p1->data;
        if(n==1)
            head=p1;
        else
            p2->next=p1;
        p2=p1;
        p1=(List*)malloc(LEN);
        scanf("%d",&p1->data);
    }
    min = p1->data;
    p2->next = p1;
    p2 = p1;
    p1=(List*)malloc(LEN);
    scanf("%d",&p1->data);
    max = p1->data;
    free(p1);
    
    p2->next = NULL;
	
    return head;
}


int main()
{
   int m;
    List * head;
    List * pa=(List*)malloc(LEN);
    List * p1,*p2;
    head = create();

    p1 = head;
    printf("p1=%d, head=%d\n", &p1, &head);
	if((p1->data < min) || (p1->data > max))
        printf("%d",p1->data);
        p1=p1->next;
    if(head!=NULL)
        do{
        	if((p1->data <= min) || (p1->data >= max))
            	printf(" %d",p1->data);
            p1=p1->next;
        }while(p1->next!=NULL);
    


    p1->next=NULL;
    p2->next=NULL;
	
	return 0;
}


