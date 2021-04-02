#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef enum {Link, Thread} PointerTag;
//Link(0):左右孩子指针
//Thread(1): 前驱后继线索 
typedef struct BiThrNode
{
	ElemType data;
	struct BiThrNode *lchild, *rchild;
	PointerTag ltag, rtag;
}BiThrNode, *BiThrTree;

int totalnode = 0;
//前驱结点 
BiThrTree pre; 
int i=0;
int s[20];
int count = 0;
void CreateBiThrTree(BiThrTree *T)
{
	
	printf("creating...\n");
	int x;
	if(count < totalnode){
		x = s[i];
		i++;
		if(x == -1)
			*T = NULL;
		else{
			count++;
			*T = (BiThrNode *)malloc(sizeof(BiThrNode));
			(*T)->data = x;
			(*T)->ltag = Link;
			(*T)->rtag = Link;
			CreateBiThrTree(&(*T)->lchild);
			CreateBiThrTree(&(*T)->rchild);
		}
		
	}
}

//中序遍历线索化
void InThreading(BiThrTree T)
{
	if(T)
	{
		if(T->lchild != NULL)
			InThreading(T->lchild);
		if(!T->lchild)
		{
			T->ltag = Thread;
			T->lchild = pre;
		}
		if(!pre->rchild)
		{
			pre->rtag = Thread;
			pre->rchild = T;
		}
		pre = T;
		if(T->rchild != NULL)
			InThreading(T->rchild);
	}
 } 
 
void InOrderThreading(BiThrTree *p, BiThrTree T)
{
	*p = (BiThrTree)malloc(sizeof(BiThrNode));
	(*p)->ltag = Link;
	(*p)->rtag = Thread;
	(*p)->rchild = *p;
	if(!T)
	{
		(*p)->lchild = *p;
	}else{
		(*p)->lchild = T;
		pre = *p;
		InThreading(T);
		pre->rchild = *p;
		pre->rtag = Thread;
	}
}

void visit(char c)
{
	printf("%d ", c);
}

//中序遍历二叉树
void InOrderTraverse(BiThrTree T) 
{
	BiThrTree p;
	p = T->lchild;
	while(p != T)
	{
		while(p->ltag == Link)
		{
			p = p->lchild;
		}
		visit(p->data);
		while(p->rtag == Thread && p->rchild != T)
		{
			p = p->rchild;
			visit(p->data);
		}
		p = p->rchild;
	}
}


int num=0;
int main(void)
{
    BiThrTree P, T = NULL;
    char c = getchar();
    int target;
    s[0] = 0;
    num++;
    printf("start input:");
    while(c != '\n'){
    	if(c >= '0' && c <= '9')
    	{
	    	target = c - '0';
				while((c = getchar()) >= '0' && c <='9')
				{
					target = target * 10 + c - '0';
				}
	    	s[num] = target;
	    	totalnode++;
	        num++;
		}else if(c == 'n'){
			s[num] = -1;
			num++;
			c = getchar();
		}else{
			c = getchar();
		}	
    }
    printf("totalnode = %d\n", totalnode);
    CreateBiThrTree(&T);
    InOrderThreading(&P, T);
	printf("中序遍历输出：\n");
	InOrderTraverse(P);
	return 0;
}
