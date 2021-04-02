#include <stdio.h>
#include <stdlib.h>

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

int printstate = 0;
void PrintBTree(BinTree *bt)
{
    if(bt != NULL && bt->data != 0){
    	if(printstate == 0){
    		printf("%d", bt->data);
    		printstate = 1;
		}else
        	printf(",%d", bt->data);
        PrintBTree(bt->lchild);
        PrintBTree(bt->rchild);
    }
}

void ChangeBTree(BinTree *bt)
{
	BinTree *p;
	if(bt != NULL && bt->data != 0)
	{
		p = bt->lchild;
		bt->lchild = bt->rchild;
		bt->rchild = p;
	}
	
	if(bt->lchild != NULL)
		ChangeBTree(bt->lchild);
	if(bt->rchild != NULL)
		ChangeBTree(bt->rchild);
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
    ChangeBTree(root);
    PrintBTree(root);
    return 0;
}

