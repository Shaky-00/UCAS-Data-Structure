#include <iostream>
#include<stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
using namespace std; 
typedef enum{Link, Thread} PointerThr;
//Link == 0 指针
//Thread==1 线索 
typedef int Status;
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild, *rchild;
	PointerThr LTag,Rtag;
}BiTree;
BiTree *CreateBiTree(int *data, int k);
BiTree *Find(BiTree *t, int target);
Status PreOrder(BiTree *T); 
void InThreading(BiTree *p);
Status InorderThread(BiTree *t, BiTree *p);
void InorderTraverse(BiTree *t);
BiTree *pre;

int main(){
	int data[100];
	int data1[100];
	int i;
	int k;
	int k1;
	int depth = 0;
	int limit = 1;
	int *m;
	int j = 1;
	m = &j;
	char item;
	int target = 0;
	for(i = 0; i < 100; i++){
		data[i] = -100;
		data1[i]  =-100;
	}
	pre = NULL;
	i = 1;
	int count = 0;
	while(cin >> item && item != ';' ){
		if(item >= '0' && item <= '9'){
			while(data[i] == -1){
				i++;
			}
			data[i] = item - '0';
			i = i + 1; 
	
		}
		if(item == 'n'){
			while(data[i] == -1){
				i++;
			}
			data[i] = -1;
			k = i;
			depth = 1;
			while(2*k < 100){
				k = k*2; 
				k1 = 0;
				while(k1 < depth){
					limit = limit*2;
					k1++;
				}
				k1 = 0;
				while(k1 < limit && k+k1 <100){
					data[k+k1] = -1;
					k1++; 
				}
				depth++;
				limit = 1;
			}
			i++;
			while(cin >> item && item != ','){
				;
			}
		}
	}
	i = 1;
	count = 0;
	while(cin >> item && item != ';' ){
		if(item >= '0' && item <= '9'){
			while(data1[i] == -1){
				i++;
			}
			data1[i] = item - '0';
			i = i + 1; 
	
		}
		if(item == 'n'){
			while(data1[i] == -1){
				i++;
			}
			data1[i] = -1;
			k = i;
			depth = 1;
			while(2*k < 100){
				k = k*2; 
				k1 = 0;
				while(k1 < depth){
					limit = limit*2;
					k1++;
				}
				k1 = 0;
				while(k1 < limit && k+k1 <100){
					data1[k+k1] = -1;
					k1++; 
				}
				depth++;
				limit = 1;
			}
			i++;
			while(cin >> item && item != ','){
				;
			}
		}
	}	
	cin >> item;
	target = item - '0';	
	BiTNode *p, *x, *q,*t;
	p = CreateBiTree(data,1);
//	PreOrder(p);
	x = CreateBiTree(data1,1);
	q = Find(p, target);
	if(q->lchild){
		x->rchild = q->lchild;
		q->lchild = x;	
	}else{
		q->lchild = x;
	}
//	PreOrder(p);
//	printf("\n");
	t = (BiTree*)malloc(sizeof(BiTree));
	InorderThread(t,p);
	InorderTraverse(t);
	
	m  = &j;
	j = 1;


	return 0;
}
BiTree *Find(BiTree *t, int target){
	if(!t){
		return NULL;
	}
	if(t->data == target){
		return t;
	}else if(Find(t->lchild,target)){
		return Find(t->lchild, target);
	}else{
		return Find(t->rchild, target);
	}
}
BiTree *CreateBiTree(int *data, int k){
	BiTNode *bt;
	if(data[k] == -100){
		bt = NULL;
	}else if(data[k] == -1){
		bt= NULL;	
	}else{
		bt = (BiTree*)malloc(sizeof(BiTree));
		if(!bt){
			return NULL;
		}
		bt->LTag = Link;
		bt->Rtag = Link;
		bt->data = data[k];
		bt->lchild = CreateBiTree(data, 2*k);
		bt->rchild = CreateBiTree(data, 2*k+1);
	}
	return bt;
}
Status PreOrder(BiTree *T){
	if(T){
				
		PreOrder(T->lchild);
		printf("%d,",T->data);
		PreOrder(T->rchild);
	}else{
		return OK;
	}
}
Status InorderThread(BiTree *t, BiTree *p){
//	BiTree *pre;//pre指向刚刚访问过的结点 
	//t指向头结点，p指向根节点
	t->LTag = Link;
	t->data = 0;
	t->Rtag  = Thread;
	t->rchild = t;
	if(!p) 
		t->lchild = t;//空树时指向自己
	else{
		t->lchild = p;
		pre = t;//pre指向头结点 
		InThreading(p);
		pre->rchild = t;
		pre->Rtag = Thread;
		t->rchild = pre;
	} 
	return OK;	 
}
void InThreading(BiTree *p){
	if(p){
		InThreading(p->lchild);
		if(!p->lchild){
			p->LTag = Thread;
			p->lchild = pre;
		}
		if(!pre->rchild){
			pre->Rtag = Thread;
			pre->rchild = p;
		}
		pre = p;
		InThreading(p->rchild);
	}
}
void InorderTraverse(BiTree *t){
	BiTree *p;
	p = t->lchild;//p指向根节点
	while(p!=t){//空树或遍历结束时，p == T 
		while(p->LTag == Link ){
			p = p->lchild;
		}
		if(p){
			printf("%d,%d,%d,%d",p->LTag,p->lchild->data,p->Rtag,p->rchild->data);
			if(p->rchild != t){
				printf(";");
			}
		}
			
		while(p->Rtag == Thread && p->rchild != t ){
			p = p->rchild;
				printf("%d,%d,%d,%d",p->LTag,p->lchild->data,p->Rtag,p->rchild->data);
				if(p->rchild != t){
				printf(";");
				}
		}
		p = p->rchild;//p进到右子树根 
	} 
}
