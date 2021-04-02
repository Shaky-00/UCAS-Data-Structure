#include<stdio.h>
#include<malloc.h>
#define INIT_SIZE 20
#define INCREMENT_SIZE 5
#define OK 1
#define ERROR 0 
#define LIM 50
#define ON 1
#define OFF 0

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

int string = 0;
Status DividList(SqList *A, SqList *B, SqList *C)
{
	char temp;
	int i, i1=0, i2=0, i3=0;
	while((temp = getchar()) != '\n')
	{
		if(temp == ',')
			;
		else if(temp == ';' && string == 0)
			string = 1;
		else if(temp == ';' && string == 1)
			string = 2;
		else{
			if(string == 0)
			{
				A->elem[i1] = temp;
				A->length++;
				i1++;
			}else if(string == 1){
				B->elem[i2] = temp;
				B->length++;
				i2++;
			}else if(string == 2){
				C->elem[i3] = temp;
				C->length++;
				i3++;
			}else 
				return ERROR;
		}
	}
	return OK;
}

Status compare(Elemtype e1, Elemtype e2)
{
	if(e1 == e2)
		return 0;
	else if(e1 < e2)
		return -1;
	else
		return 1;
}

SqList A, B, C;
int main()
{
	InitList(&A);
	InitList(&B);
	InitList(&C);
	Elemtype temp[LIM];
	DividList(&A, &B, &C);
	
	int count = 0;
	int m, n;
	int i, j;
	for(i=0; i<B.length; i++)
	{
		for(j=0; j<C.length; j++)
		{
			if(!compare(B.elem[i], C.elem[j]))
			{
				temp[count] = B.elem[i];
				count++;
			}
		}
	}
	
	Status same = ERROR;
	
	Status space = OFF;
	for(m=0; m<A.length; m++)
	{	
		for(n=0; n<count; n++)
		{
			if(!compare(A.elem[m], temp[n]))
				same = OK;	
		}	
		if(same == ERROR){
			if(space == OFF)
				printf("%c", A.elem[m]);
			else
				printf(",%c", A.elem[m]);
			space = ON;
		}	
		same = ERROR;
	}
	
	return 0;
}

