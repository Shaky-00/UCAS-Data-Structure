#include<stdio.h>
#include<stdlib.h>
#define MAXVERTEX 50

typedef struct node * EdgeNode;
typedef struct vnode * VertexNode;
typedef struct graph * AdjGraph;
struct node{
    int adjvex;
    EdgeNode next;
};

struct vnode
{
    int vertex;
    EdgeNode firstedge;
};

struct graph
{
    struct vnode *adjlist;
    int n;
    int l;
};
int vertexbox[50];
int box[50];
void CreateGraph(AdjGraph G)
{
    
    EdgeNode s;
    int x, y;
    int i=0;
    scanf("%d,%d", &G->n, &G->l);
    for(i=0; i<50; i++){
    	vertexbox[i] = i;
    	box[i] = 0;
	}

    for(i=0; i<50; i++)
    {
        G->adjlist[i].vertex = vertexbox[i];
        G->adjlist[i].firstedge = NULL;
    }

    int state = 0;
    for(i=0; i<G->l; i++)
    {
        if(state == 0)
        {
            scanf("%d-%d", &x, &y);
            box[x] = 1;
            box[y] = 1;
            state = 1;
        }else{
            scanf(",%d-%d", &x, &y);
            box[x] = 1;
            box[y] = 1;
        }
        s = malloc(sizeof(struct node));
        s->adjvex = y;
        s->next = G->adjlist[x].firstedge;
        G->adjlist[x].firstedge = s;
    }
}

void OrderOut(int array[100], int limit)
{
    int max;
    int pos;
    int i=0, j=0;
    int num = 0;
    while(num < limit)
    {
        pos = 0;
        max = array[0];
        for(i=1; i<10; i++)
        {
            if(array[i] > max)
            {
                max = array[i];
                pos = i;
            }
        }
        array[pos] = 0;
        if(num == 0)
            printf(" %d", max);
        else
            printf(",%d", max);
        num++;
    }
}

void PrintGraph(AdjGraph G)
{
    int i=0, j;
    int temp[100];
    int num = 0;
    
	i = 0;
    while(num < G->n)
    {
    	int state = 0;
        for(j=0; j<10; j++)
        {
            temp[j] = 0;
        }
        j = 0;
        if(box[i] == 0){
        	i++;
        	continue;
		}else{
        	printf("%d", G->adjlist[i].vertex);
        	num++;
        	state = 1;
		}
        	
        while(G->adjlist[i].firstedge != NULL)
        {
            j++;
            temp[j] = G->adjlist[i].firstedge->adjvex;
            G->adjlist[i].firstedge = G->adjlist[i].firstedge->next;
        }
        OrderOut(temp, j);
        if(num < G->n && state == 1)
        	printf("\n");	
		i++;
    }
}

int main()
{
	AdjGraph G;
	G = malloc(sizeof(struct graph));
	G->adjlist = (struct vnode *)malloc(sizeof(struct vnode)*MAXVERTEX);
	CreateGraph(G);
	PrintGraph(G);
	
	return 0;
}
