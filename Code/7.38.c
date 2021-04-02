#include<stdio.h>
#include <stdlib.h>

#define MAXSIZE 40

typedef struct Node{
	int pos;
	struct Node *next, *pre;
}NodeLink; 

typedef struct{
	int vexnum, edgenum;
	struct{
		char vertex;
		NodeLink *first;
	}v[MAXSIZE]; 
}AdjGraph;

int note = 0;
char result[MAXSIZE];

int TraverseGraph(AdjGraph G, int i){
	NodeLink *p, *q;
	result[note] = G.v[i].vertex; 
	note++;
	if(G.v[i].vertex >= 'a' && G.v[i].vertex <= 'z')
		return 0;
	
	p = G.v[i].first->next;
	if(p != NULL)
	{
		while(p != NULL && p != G.v[i].first)
		{
			TraverseGraph(G, p->pos);
			p = p->next;
		}
	}else
		return 0;
	
	
	return 1;
}

int main(){
	AdjGraph G;
	int i;
	char c;
	NodeLink *p, *q;
	p = NULL;
	q = NULL;
	
	for(i = 0; i < MAXSIZE; i++){
		G.v[i].first = (NodeLink *)malloc(sizeof(NodeLink));
		G.v[i].first->pos= i;
		G.v[i].first->next = NULL;
		G.v[i].first->pre = G.v[i].first;
		G.v[i].vertex = i; 
	}
	
	c = getchar();
	G.vexnum = c - '0';
	i = 0;
	while(i < G.vexnum)//建立邻接链表 
	{
		c = getchar();
		if(c != '\n')//新的一行链表 
			G.v[i].vertex = c;
		else
			continue;
		
		while((c = getchar())!= '\n')//行内处理 
		{
			if(c >= '0' && c <= '9'){
				p = (NodeLink *)malloc(sizeof(NodeLink));
				p->pos = c - '0';
				p->next = NULL;
				p->pre = NULL;
				q = G.v[i].first;
				while(q->next != NULL){
					q = q->next;
				}
				p->pre = q;
				q->next = p;//添加p结点	
			}
		}
		i++;
	}
	
	TraverseGraph(G, 0);
	for(i=note-1; i>=0; i--)
		printf("%c", result[i]);
	
	return 0;	
}
