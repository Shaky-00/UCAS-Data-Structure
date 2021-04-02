#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int pos;
	struct Node *next;
}NodeLink;

typedef struct{
	int vexnum, edgenum;
	struct{
		int vertex;
		NodeLink *first;
	}v[20];
}AdjGraph;

int BFS(AdjGraph G, int k, int m, int n, int *road)
{
	NodeLink *p;
	if(k <= 0)
		return 0;
	p = G.v[m-1].first->next;
	while(p != NULL)
	{
		if(k == 1 && p->pos == n)
			*road = 1;
		else
			BFS(G, k-1, p->pos, n, road);
		p = p->next;
	}
	return 0;
}

int main()
{
	AdjGraph G;
	int i, k;
	char c;
	int result = 0;

	int start, end;
	int isend=0;
	for(i=0; i<20; i++)
	{
		G.v[i].first = (NodeLink *)malloc(sizeof(NodeLink));
		G.v[i].first->pos = i+1;
		G.v[i].first->next = NULL;
		G.v[i].vertex = i;
	}
	scanf("%d,%d", &G.vexnum, &k);
	getchar();
	int m, n;
	scanf("%d,%d", &m, &n);
	getchar();
	NodeLink *p, *q;
	p = q = NULL;
	while(isend == 0)
	{
		scanf("%d-%d", &start, &end);
		c = getchar();
		if(c == '\n')
			isend = 1;
	
		p = (NodeLink *)malloc(sizeof(NodeLink));
		p->pos = end;
		p->next = NULL;
		q = G.v[start-1].first;
		while(q->next!=NULL && end < q->next->pos)
			q = q->next;
		
		p->next = q->next;
		q->next = p;
		p = (NodeLink *)malloc(sizeof(NodeLink));
		p->next = NULL;
		p->pos = start;
		q = G.v[end-1].first;
		while(q->next && start < q->next->pos){
			q = q->next;
		}
		p->next = q->next;
		q->next = p;
	}
	int *road;

	road = &result;
	BFS(G, k, m, n, road);
	if(result == 0)
	{
		printf("no");
	}else{
		if(k >= G.vexnum)
			printf("no");
		else
			printf("yes");
	}
		
	return 0;
}

