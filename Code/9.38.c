#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *lchild;
	struct node *rchild;
}BinTree;

int s[100];
int t[100];

BinTree* CreateBiTree(int *s, int num)
{
	int i;
	BinTree * ptr_array[1000];
	for(i=0; i<1000; i++)
		ptr_array[i] = NULL;
	int front = 0, rear = 0;
	int ptr = 0;
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
	if(bt != NULL && bt->data != -1){
		PrintBTree(bt->lchild);
    	if(printstate == 0){
    		printf("%d", bt->data);
    		printstate = 1;
		}else
        	printf(",%d", bt->data);
        PrintBTree(bt->rchild);
    }
}

BinTree* Insert(BinTree *T, int x)
{
	if(T == NULL)
	{
		T = (BinTree *)malloc(sizeof(BinTree));
		T->data = x;
		T->lchild = T->rchild = NULL;
		return T;
	}

	if(x <= T->data)
		T->lchild = Insert(T->lchild, x);
	else
		T->rchild = Insert(T->rchild, x);
	return T;
}

void InsertBST(BinTree *T1, BinTree *T2)
{
	if(T2 != NULL)
	{
		InsertBST(T1, T2->lchild);
		T1 = Insert(T1, T2->data);
		InsertBST(T1, T2->rchild);
	}
}

int main()
{
	BinTree *T1, *T2;
	int i;
	int sign = 1;
	int num1 = 0, num2 = 0;
    char c = getchar();
    int target;
    for(i=0; i<100; i++)
    {
    	s[i] = -1;
    	t[i] = -1;
	}
    	
    while(c != ';'){
    	if(c >= '0' && c <= '9')
    	{
	    	target = c - '0';
				while((c = getchar()) >= '0' && c <='9')
				{
					target = target * 10 + c - '0';
				}
			if(sign == -1)
				target *= -1;
	    	s[num1] = target;
	        num1++;
	        sign = 1;
		}else if(c == 'n'){
			s[num1] = -1;
			num1++;
			c = getchar();
		}else if(c == '-'){
			sign = -1;
			c = getchar();
		}else{
			c = getchar();
		}	
    }
    c = getchar();
    sign = 1;
    while(c != '\n' && c != EOF){
    	if(c >= '0' && c <= '9')
    	{
	    	target = c - '0';
				while((c = getchar()) >= '0' && c <='9')
				{
					target = target * 10 + c - '0';
				}
			if(sign == -1)
				target *= -1;
	    	t[num2] = target;
	    	sign = 1;
	        num2++;
		}else if(c == 'n'){
			t[num2] = -1;
			num2++;
			c = getchar();
		}else if(c == '-'){
			sign = -1;
			c = getchar();
		}else{
			c = getchar();
		}	
    }
    T1 = CreateBiTree(s, num1); 
    T2 = CreateBiTree(t, num2);
    InsertBST(T1, T2);
    PrintBTree(T1);
    return 0;
}
