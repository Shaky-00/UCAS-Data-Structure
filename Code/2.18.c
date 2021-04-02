#include<stdio.h>
#include<malloc.h>
#define INIT_SIZE 20
#define INCREMENT_SIZE 5
#define OK 1
#define ERROR 0 

typedef int Status;
typedef int Elemtype;
typedef struct{
    Elemtype *elem;
    int length;
    int size;
}SqList;

Status InitList(SqList *L)
{
    L->elem = (Elemtype *)malloc(INIT_SIZE * sizeof(Elemtype));
    if(!L->elem)
        return ERROR;
    L->length = 0;
    L->size = INIT_SIZE;
    return OK;
}

SqList DeleteElem(SqList L, int i)
{
	if(i<1 || i>L.length)
	{
		printf("ERROR!\n"); 
	}

	Elemtype *p = &L.elem[i];
	for(; p<&L.elem[L.length]; p++)
	{
		*(p) = *(p+1);
	}
	--L.length;
	return L;
}

SqList CreateList(SqList L, int len)
{
    L.length = len;
    int i;
    
    for(i=0; i<len; i++)
    {
        scanf("%d", &L.elem[i]);
    }
    return L;
}

void PrintList(SqList L)
{
    int i;
    printf("%d", L.elem[0]);
    for(i=1; i<L.length; i++)
        printf(" %d", L.elem[i]);
}

int main()
{
    SqList L;
    InitList(&L);
    int len, pos;

    scanf("%d %d", &len, &pos);
    if(len == 1){
    	L = CreateList(L, len);
    	printf("NULL");
	}else{
	   	L = CreateList(L, len);
	    L = DeleteElem(L, pos);
	    PrintList(L);
	}
	

    return 0;
}
