#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0

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
int result = 1;
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

Status Judge(BinTree *t){
	if(t != NULL)
	{
		if(t->lchild){
			if(t->data > t->lchild->data){
				Judge(t->lchild);
			}else{
				result = 0;
				return ERROR;
			}	
		}
		if(t->rchild){
			if(t->data < t->rchild->data){
				Judge(t->rchild);
			}else{
				result = 0;
				return ERROR;
			}		
		}
	}
	
	return OK;
}

int main(void)
{
    BinTree *root;
    int i;
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
		}else{
			c = getchar();
		}	
    }
    root = CreateBiTree();
    //result = 1;
    
    Judge(root);
    printf("%d", result);
    return 0;
}

