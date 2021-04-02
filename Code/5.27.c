#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct OLNode
{
    int i, j;
    ElemType e;
    struct OLNode *right, *down;
}OLNode, *OLink;

typedef struct
{
    OLink *r_head, *c_head;
    int mu, nu, tu;//稀疏矩阵行数、列数和非零元个数
}CrossList;


CrossList Create_Matrix(CrossList M)
{
    
    int i, j;
    OLNode *p, *q;
	int m = M.mu;
	int n = M.nu;
	char c;
    c = getchar();
    int data;
    
	if(!(M.r_head=(OLink*)malloc((m+1)*sizeof(OLink)))||!(M.c_head=(OLink*)malloc((n+1)*sizeof(OLink))))
    {
        printf("初始化矩阵失败");
        exit(0);
    }
    
    for(i=1; i<m+1; i++)
    {
        M.r_head[i] = NULL;
    }

    for(j=1; j<n+1; j++)
    {
        M.c_head[j] = NULL;
    }

    for(i=1; i<m+1; i++)
    {
        for(j=1; j<n+1; j++)
        {
            c = getchar();//读掉"["或者","
            scanf("%d", &data);
            if(data != 0)
            {
                p = (OLNode *)malloc(sizeof(OLNode));
                p->i = i;
                p->j = j;
                p->e = data;
                if(NULL == M.r_head[i] || j < M.r_head[i]->j)
                {
                    p->right = M.r_head[i];
                    M.r_head[i] = p;
                }else{
                	q = M.r_head[i];
                	while((q->right != NULL) && q->right->j < j)
                		q = q->right;
                		
                    //for(q=M.r_head[i]; (q->right != NULL) && q->right->j < j; q = q->right);
                        p->right = q->right;
                        q->right = p;   

                }

                if(M.c_head[j] == NULL ||  i < M.c_head[j]->i)
                {
                    p->down = M.c_head[j];
                    M.c_head[j] = p;
                }else{
                    q = M.c_head[j];
                    while((q->down != NULL) && q->down->i < i)
                    	q = q->down;
                    //for(q = M.c_head[j]; (q->down != NULL) && q->down->i < i; q = q->down);
                        p->down = q->down;
                        q->down = p;
                }
            }
        }
        c = getchar();//读掉"]"
        c = getchar();//读掉";"
    }
    return M;
}

void display(CrossList M)
{
	
    int temp_M[M.mu+1][M.nu+1];
	int i, j;

    for(i=1; i<M.mu+1; i++)
    {
        for(j=1; j<M.nu+1; j++)
        {
            temp_M[i][j] = 0;
        }
    }//临时矩阵初始化
 
    printf("开始输出矩阵：\n");
    for(i=1; i<=M.mu; i++)
    {
        if(M.r_head[i] != NULL)
        {
            OLink p = M.r_head[i];
            while(p != NULL)
            {
                temp_M[p->i][p->j] = p->e;
                p = p->right;
            }
        }    
    }
    printf("[");
    int state;
    for(i=1; i<=M.mu; i++)
    {
    	printf("[");
    	state = 0;
        for(j=1; j<=M.nu; j++)
        {
        	if(state == 0)
        	{
        		printf("%d", temp_M[i][j]);
        		state = 1;
			}else
            	printf(",%d", temp_M[i][j]);
        }
        printf("]");
        if(i != M.mu)
        	printf(";");
        else
        	printf("]");
    }
    
}

CrossList AddMatrix(CrossList M,CrossList N){
    OLNode *pm, *pn, *pre, *p;//pm指向M矩阵，pn指向N矩阵，pre记录M所指处前一个位置
    OLink *last = (OLink *)malloc(M.nu * sizeof(OLink));//记录每行末端非零元素
    pre = NULL;
	int i;
    for(i=1; i<=M.nu; i++) 
        last[i] = M.c_head[i];
        
    for(i=1; i<=M.mu; i++)
	{
        pm = M.r_head[i];
        pn = N.r_head[i];
        while (pn!=NULL)//将N矩阵转移到M矩阵上来
		{
            p = (OLNode *)malloc(sizeof(OLNode));
            p->i = pn->i;
            p->j = pn->j;
            p->e = pn->e;
            p->down = NULL;
            p->right = NULL;
            if(pm == NULL || pm->j > pn->j)
			{
                if(pre != NULL)				
                    pre->right = p; 
                else
                    M.r_head[p->i] = p;
					      
                p->right = pm;
                pre = p;
                if(M.c_head[p->j] != NULL || M.c_head[p->j]->i > p->i) {
                    p->down = M.c_head[p->j];
                    M.c_head[p->j] = p;
                }else{
                    p->down = last[p->j]->down;
                    last[p->j]->down = p;
                }
                last[p->j] = p;
            }else{
                if (pm->j < pn->j) {
                    pre = pm;
                    pm = pm->right;
                    continue;
                }
                if (pm->j == pn->j) {
                pm->e = pm->e + pn->e;
                if (pm->e == 0) {
                    if (pre == NULL) {
                        M.r_head[pm->i] = pm->right;
                    }else{
                        pre->right = pm->right;
                    }
                    p = pm;
                    pm = pm->right;
                    if(M.c_head[p->j] == p) {
                    	M.c_head[p->j] = p->down;
                        last[p->j] = p->down;
                    }else{
                        last[p->j]->down = p->down;
                    }
                    free(p);
                    }
                }
            }
            pn = pn->right;
        }
    }
    
    return M;
}

int main()
{
    CrossList M, N;
    printf("按要求输入数据：");
    int m, n;
    char c;
    scanf("%d;%d;", &m, &n);
    M.mu = m;
    M.nu = n;
    N.mu = m;
    N.nu = n;
    M = Create_Matrix(M);
    if((c = getchar()) != '+')
        printf("something error!");
    N = Create_Matrix(N);
    display(M);
    printf("\n");
    display(N);
	M = AddMatrix(M, N);
	printf("加法之后...\n");
	display(M);
    return 0;
}
