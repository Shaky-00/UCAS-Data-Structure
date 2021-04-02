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

int JudgeSign(int m, int n){
	if((m == -4 || m == -5) && (n == -2 || n == -3))
		return 1;
	else if(m == n && m != -2 && m != -4)
		return 1;
	else
		return 0;	
}

int printstate = 0;
void PrintBTree(BinTree *bt)
{
    if(bt != NULL)
    {
    	if(bt->lchild != NULL)
		{
			if(bt->lchild->data < -1 && JudgeSign(bt->data, bt->lchild->data))
			{
				printf("(");
				PrintBTree(bt->lchild);
				printf(")");
			}else
				PrintBTree(bt->lchild);
		 } 
		 
		if(bt->data > 0)
		 	printf("%d", bt->data);
		else if(bt->data == -2)
			printf("+");
		else if(bt->data == -3)
			printf("-");
		else if(bt->data == -4)
			printf("*");
		else if(bt->data == -5)
			printf("/");
			
		if(bt->rchild != NULL)
		{
			if(bt->rchild->data < -1 && JudgeSign(bt->data, bt->rchild->data))
			{
				printf("(");
				PrintBTree(bt->rchild);
				printf(")");
			}else
				PrintBTree(bt->rchild);
		 } 
	}
}

int main(void)
{
    BinTree *root;
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
		}else if(c == '+'){
			s[num] = -2;
			num++;
			c = getchar();
		}else if(c == '-'){
			s[num] = -3;
			num++;
			c = getchar();
		}else if(c == '*'){
			s[num] = -4;
			num++;
			c = getchar();
		}else if(c == '/'){
			s[num] = -5;
			num++;
			c = getchar();
		}else{
			c = getchar();
		}	
    }
    
    root = CreateBiTree();
    PrintBTree(root);
    return 0;
}

