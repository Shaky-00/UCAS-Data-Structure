#include <iostream>
#include<stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

using namespace std; 

typedef int Status;
typedef enum{Link, Thread} PointerTag;
typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild;
	PointerTag ltag, rtag;
}BiThrNode, *BiThrTree;

BiThrNode *pre;

BiThrNode *Get_target(BiThrNode *t, int target){
	if(!t){
		return NULL;
	}
	if(t->data == target){
		return t;
	}else if(Get_target(t->lchild,target)){
		return Get_target(t->lchild, target);
	}else{
		return Get_target(t->rchild, target);
	}
}

BiThrNode *CreateBiTree(int data[], int k){
	BiTNode *bt;
	if(data[k] == -100){
		bt = NULL;
	}else if(data[k] == -1){
		bt= NULL;	
	}else{
		bt = (BiThrNode*)malloc(sizeof(BiThrNode));
		if(!bt){
			return NULL;
		}
		bt->ltag = Link;
		bt->rtag = Link;
		bt->data = data[k];
		bt->lchild = CreateBiTree(data, 2*k);
		bt->rchild = CreateBiTree(data, 2*k+1);
	}
	return bt;
}

Status PreOrder(BiThrNode *T){
	if(T){
				
		PreOrder(T->lchild);
		printf("%d,",T->data);
		PreOrder(T->rchild);
	}else{
		return OK;
	}
}

void InThreading(BiThrNode *p){
	if(p != NULL){
		InThreading(p->lchild);
		if(!p->lchild)
		{
			p->ltag = Thread;
			p->lchild = pre;
		}
		
		if(!pre->rchild)
		{
			pre->rtag = Thread;
			pre->rchild = p;
		}
		pre = p;
		InThreading(p->rchild);
	}
}

void InOrderThread(BiThrTree T, BiThrNode *p){
    T->data = 0;
	T->ltag = Link;
	T->rtag  = Thread;
	T->rchild = T;
	if(p != NULL)
	{
		T->lchild = p;
		pre = T;
		InThreading(p);
		pre->rchild = T;
		pre->rtag = Thread;
		T->rchild = pre;
	}else{
		T->lchild = T;
	}  
}

void InorderTraverse(BiThrNode *t){
	BiThrNode *p;
	p = t->lchild;
	while(p!=t){
		while(p->ltag == Link ){
			p = p->lchild;
		}
		if(p){
			printf("%d,%d,%d,%d",p->ltag, p->lchild->data, p->rtag, p->rchild->data);
			if(p->rchild != t){
				printf(";");
			}
		}
			
		while(p->rtag == Thread && p->rchild != t ){
			p = p->rchild;
			printf("%d,%d,%d,%d", p->ltag, p->lchild->data, p->rtag, p->rchild->data);
			if(p->rchild != t){
			    printf(";");
			}
		}
		p = p->rchild;
	} 
}

int main(){
	int data[100];
	int tree[100];
	int i, k, k1, j=1;
	int depth = 0;
	int limit = 1;
	int *m;
	m = &j;
	
	char c;
	int target = 0;
	for(i = 0; i < 100; i++){
		data[i] = -100;
		tree[i]  =-100;
	}
	pre = NULL;
	i = 1;
	int count = 0;
	while(cin >> c && c != ';' ){
		if(c >= '0' && c <= '9'){
			while(data[i] == -1)
				i++;
			data[i] = c - '0';
			i++;
		}
		if(c == 'n'){
			while(data[i] == -1)
				i++;
			data[i] = -1;
			k = i;
			depth = 1;
			while(2*k < 100)
            {
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
			while(cin >> c && c != ','){
				;
			}
		}
	}
	i = 1;
	count = 0;
	while(cin >> c && c != ';' ){
		if(c >= '0' && c <= '9')
        {
			while(tree[i] == -1){
				i++;
			}
			tree[i] = c - '0';
			i = i + 1; 
		}
		if(c == 'n'){
			while(tree[i] == -1)
				i++;
			tree[i] = -1;
			k = i;
			depth = 1;
			while(2*k < 100)
            {
				k = k*2; 
				k1 = 0;
				while(k1 < depth){
					limit = limit*2;
					k1++;
				}
				k1 = 0;
				while(k1 < limit && k+k1 <100){
					tree[k+k1] = -1;
					k1++; 
				}
				depth++;
				limit = 1;
			}
			i++;
			while(cin >> c && c != ',')
				;
		}
	}	

	cin >> c;
	target = c - '0';	
	BiTNode *p, *q, *x, *t;
	p = CreateBiTree(data, 1);
	x = CreateBiTree(tree, 1);
	q = Get_target(p, target);

	if(q->lchild){
		x->rchild = q->lchild;
		q->lchild = x;	
	}else{
		q->lchild = x;
	}

	t = (BiThrNode*)malloc(sizeof(BiThrNode));
	InOrderThread(t, p);
	InorderTraverse(t);
	m  = &j;
	j = 1;
	return 0;
}
