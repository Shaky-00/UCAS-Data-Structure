#include<stdio.h>

struct node{
    int v, net;
}graph[100];

int n, m, head[100], count;
int visit[100]; 

void add(int u, int v)
{
    ++count;
    graph[count].v = v;
    graph[count].net = head[u];
    head[u]=count;
}

int DFS(int s,int t) {
    int i;
    if(s == t)    
        return 1;
    visit[s] = 1;  
    for(i=head[s]; i; i=graph[i].net)
    {   
        if(!visit[graph[i].v])
            return DFS(graph[i].v,t);
    }
    return 0;
}

int main()
{
    int n, u, v, s, t;
    scanf("%d", &n);
    int i;
    char c;
    int state = 0;
	c = getchar();
	int end = 0;
    while(end == 0)
    {
        if(state == 0){
        	scanf("%d-%d", &u, &v);
        	state = 1;
		}else{
			scanf("%d-%d", &u, &v);
		}
        add(u,v); 
        c = getchar();
        if(c == '\n')
        	end = 1;
    }
    scanf("%d, %d", &s, &t);
    if(DFS(s,t))  
        printf("yes");
    else
        printf("no");
    return 0;
}
