#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 20

typedef int Status;
typedef struct node{
    int data;
    struct node *lchild;
	struct node *rchild;
}BinTree;

BinTree * ptr_array[1000];
int s[1000];
int front = 0, rear = 0;
int num = 0;
int ptr = 0;
int result[MAXSIZE];
BinTree* CreateBiTree(void)
{
    int n = num;
    int d, d1, d2;
    BinTree *t, *bt, *q;
    d = s[ptr++];
    if(d != -1){
        bt = (BinTree*)malloc(sizeof(BinTree));
        bt->data = d;
        bt->rchild = bt->lchild = NULL;
        ptr_array[rear++] = bt;
        n--;
    }else
        return NULL;
        
    while(n > 0 && ptr < num){
        t = ptr_array[front];
        front++;
        d1 = s[ptr++];
        if(d1 == -1)
            t->lchild = NULL;
        else{
            q = (BinTree*)malloc(sizeof(BinTree));
            q->data = d1;
            t->lchild = q;
            q->rchild = q->lchild = NULL;
            ptr_array[rear++] = q;
            n--;
        }

        d2 = s[ptr++];
        if(d2 == -1)
            t->rchild = NULL;
        else{
            q = (BinTree*)malloc(sizeof(BinTree));
            q->data = d2;
            t->rchild = q;
            q->rchild = q->lchild = NULL;
            ptr_array[rear++] = q;
            n--;
        }            
    }
    
    return bt;
}

int count = 0;
void GetElem(BinTree *T, int x){
	if(T != NULL)
	{
		if(T->lchild)
			GetElem(T->lchild, x);
		
		if(T->rchild)
			GetElem(T->rchild, x);
		
		if(T->data >= x)
			{
				result[count] = T->data;
				count++;
			}
	}
}

int main(void)
{
    BinTree *root;
    int i, j;
    int x;
    int max = 0;
    int pos = 0;
    char c = getchar();
    int target;
    while(c != '\n'){
    	if(c >= '0' && c <= '9')
    	{
	    	target = c - '0';
				while((c = getchar()) >= '0' && c <='9')
				{
					target = target * 10 + c - '0';
				}
	    	s[num] = target;
	        num++;
		}else if(c == 'n'){
			s[num] = -1;
			num++;
			c = getchar();
		}else if(c == ';'){
			scanf("%d", &x);
			c = getchar();
		}else{
			c = getchar();
		}	
    }
    root = CreateBiTree();
    GetElem(root, x);

    for(j=0; j<count; j++)
    {
    	max = result[0];
	    for(i=0; i<count; i++)
		{
			if(result[i] >= max){
				max = result[i];	
				pos = i;
			}		
		}
		if(j == 0)
			printf("%d", max);
		else
			printf(",%d", max);
		result[pos] = -1;
	}
   	 
    return 0;
}

