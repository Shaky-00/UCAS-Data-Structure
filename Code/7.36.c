#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 40

typedef struct Node{
	int pos;
	struct Node *next;
}NodeLink;

typedef struct{
	int vexnum, edgenum;
	struct{
		int vertex;
		int MPL;
		NodeLink *first;
	}v[MAXSIZE];
}AdjGraph;

int result[MAXSIZE];
int MPL(AdjGraph G, int i)
{
	NodeLink *p;
	int length=0;
	p = G.v[i].first;
	if(p->next == NULL)
		return 0;
	while(p->next != NULL)
	{
		p = p->next;
		length = length + MPL(G, p->pos-1) + 1;
		if(length > result[i])
			result[i] = length;
		else
			;
		length = 0;
	}
	
	return result[i];
}

int main()
{
	AdjGraph G;
	int i;
	for(i=0; i<MAXSIZE; i++)
	{
		G.v[i].first = (NodeLink *)malloc(sizeof(NodeLink));
		G.v[i].first->pos = i+1;
		G.v[i].first->next = NULL;
		G.v[i].MPL = 0;
		G.v[i].vertex = i;
	}
	int n;
	int end = 0;
	char c;
	int x, y;
	NodeLink *p, *q;
	scanf("%d", &n);
	G.vexnum = n;
	c = getchar();//'\n'
	while(end == 0)
	{
		scanf("%d-%d", &x, &y);
		p = (NodeLink *)malloc(sizeof(NodeLink));
		p->pos = y;
		p->next = NULL;
		
		q = G.v[x-1].first;
		while(q->next && y<q->next->pos)
			q = q->next;
			
		p->next = q->next;
		q->next = p;
		c = getchar();
		if(c == '\n')
			end = 1;
	}	
	
	for(i=0; i<G.vexnum; i++)
	{
		if(result[i] != -1)
			printf("%d", MPL(G, i));
		else
			printf("0");
			
		if(i != G.vexnum-1)
			printf(",");
	}
	
	return 0;
}
