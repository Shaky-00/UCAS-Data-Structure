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

int Path(BinTree *bt, int x, BinTree * path[50])
{
	BinTree node[50];
	int i = 0;
	if(bt == NULL)
		return 0;
	
	path[i] = bt;
	node[i] = *bt;
	
	while(i >= 0)
	{
		while(node[i].lchild != NULL || path[i]->data == x)
		{
			if(path[i]->data == x)
				return 1;
			else{
				path[i+1] = node[i].lchild;
				if(node[i].lchild != NULL)
					node[i+1] = *(node[i].lchild);
				node[i].lchild = NULL;
				i++;
			}
		}
		if(node[i].rchild != NULL)
		{
			path[i+1] = node[i].rchild;
			if(node[i].rchild != NULL)
				node[i+1] = *(node[i].rchild);
			node[i].rchild = NULL;
			i++;
		}else{
			path[i] = NULL;
			i--;
		}
	}	
	if(i < 0)
		return 0;
}

int FindParent(BinTree * bt, int x, int y)
{
	BinTree * path1[50];
	BinTree * path2[50];
	int k = 0;
	if(Path(bt, x, path1) && Path(bt, y, path2))
	{
		if(path1[k]->data != x && path2[k]->data != y)
		{
			while(path1[k]->data == path2[k]->data)
				k++;
			printf("%d", path1[k-1]->data);
			return 1; 
		}
	}
	return 0;
}

int main(void)
{
    BinTree *root;
    int x, y;
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
			break;
		}else{
			c = getchar();
		}
    }
    
    scanf("%d;%d", &x, &y);
    root = CreateBiTree();
    if(FindParent(root, x, y))
    	;
    else
    	printf("error!\n");
    return 0;
}

