#include<stdio.h>
#include<stdlib.h>

typedef struct node{
   int data;
    struct node *lchild;
	struct node *rchild;
}BinTree;

int xianxu[50];
int zhongxu[50];
BinTree * CreateTree(int start, int end, int z_start, int z_end)
{
	BinTree * bt;
	int i;
	int new_lside, new_rside;
	bt = (BinTree *)malloc(sizeof(BinTree));
	bt->data = xianxu[start];
	bt->lchild = bt->rchild = NULL;
	i = z_start;
	
	while(zhongxu[i] != bt->data)
		i++;//找到data在中序序列里的位置 
	
	new_lside = i - z_start;
	new_rside = z_end - i;
	if(new_lside > 0)
		bt->lchild = CreateTree(start+1, start+new_lside, z_start, i-1);
	if(new_rside > 0)
		bt->rchild = CreateTree(start+new_lside+1, end, i+1, z_end);
		
	return bt;
	
}

int printstate = 0;
void PrintBTree(BinTree *bt)
{
    if(bt != NULL && bt->data != 0){
    	PrintBTree(bt->lchild);
        PrintBTree(bt->rchild);
		if(printstate == 0){
    		printf("%d", bt->data);
    		printstate = 1;
		}else
        	printf(",%d", bt->data); 
    }
}

int main()
{
	int i=1, j=1;
	int length;
	char c;
	scanf("%d", &xianxu[0]);
	while((c = getchar()) != ';')
	{
		scanf("%d", &xianxu[i]);
		i++;
	}
	scanf("%d", &zhongxu[0]);
	while((c = getchar()) != '\n')
	{
		scanf("%d", &zhongxu[j]);
		j++;
	}
	length = i;
	BinTree * root;
	root = CreateTree(0, length-1, 0, length-1);
	PrintBTree(root);
	return 0;
}
