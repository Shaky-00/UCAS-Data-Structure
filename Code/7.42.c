#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 20
typedef struct Node{
	int pos;
	int weight;
	struct Node *next;
}NodeLink;
typedef struct{
	int vexnum, edgenum;
	struct{
		char vertex;
		NodeLink *first;
	}v[MAXSIZE];
}AdjGraph;

int result[MAXSIZE];
int Dijkstra(AdjGraph G, int Origin, int shortest)
{
	NodeLink *m, *n;
	int i;
	m = G.v[Origin].first->next;
	while(m != NULL)
	{
		i = m->pos;
		if(m->weight + shortest < result[i])
			result[i] = m->weight + shortest;
		else
			result[i] = result[i];
		Dijkstra(G, i, result[i]);
		m = m->next;
		if(m != NULL && m->pos == 1)
			return 1;
	}
	return 1;
}

int main()
{
	AdjGraph G;
	NodeLink *p, *q;
	p = q = NULL;
	int i;
	for(i=0; i<MAXSIZE; i++)
		result[i] = 1000;//初始距离设为无穷大，才能找到最短距离 
		
	G.edgenum = 0;
	for(i=0; i<MAXSIZE; i++)
	{
		G.v[i].first = (NodeLink *)malloc(sizeof(NodeLink));
		G.v[i].first->pos = i;
		G.v[i].first->weight = 0;
		G.v[i].first->next = NULL;
		G.v[i].vertex = i;
	}
	int n, Origin;
	scanf("%d %d", &n, &Origin);//顶点个数和源点 
	G.vexnum = n;
	char c;
	c = getchar();
	int x, y, weight;

	while((c = getchar()) != EOF)
	{
		x = c - '0';
		scanf("-%d %d", &y, &weight);//扫描边和权值 
		p = (NodeLink *)malloc(sizeof(NodeLink));
		p->next = NULL;
		p->pos = y;
		p->weight = weight;
		q = G.v[x].first;
		G.edgenum++;
		while(q->next)
			q = q->next;
			
		q->next = p;
		weight = 0;
		c = getchar();
	}
	
	Dijkstra(G, Origin, 0);

	for(i=1; i<=G.vexnum; i++)
	{
		if(i != Origin){
			printf("%d", result[i]);
			if(i < G.vexnum)
				printf(",");
		}else
			;
	}
	
	return 0;
}
