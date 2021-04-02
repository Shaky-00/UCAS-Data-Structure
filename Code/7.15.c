#include<stdio.h>

int n;//全局变量，节点数n 
int Matrix[10][10];
void InsertVex(int Matrix[10][10], int x)//添加顶点 
{
	int i, j;
	for(i=0; i<n; i++)
		Matrix[i][x] = 0;
	for(j=0; j<n; j++)
		Matrix[x][j] = 0;
}

void InsertArc(int Matrix[10][10], int x, int y)
{
	Matrix[x][y] = 1;
	int i,j;
}

void DeleteVex(int Matrix[10][10], int x)
{
	int i, j;	
	for(i=0; i<10; i++)
		Matrix[i][x] = -1;
	for(j=0; j<10; j++)
		Matrix[x][j] = -1;
}

void DeleteArc(int Matrix[10][10], int x, int y)
{
	Matrix[x][y] = 0;
}

int main()
{
	scanf("%d", &n);//储存节点数量
	
	int i, j;
	for(i=0; i<10; i++)//初始化邻接矩阵 
	{
		for(j=0; j<10; j++)
		{
			if(i<n && j<n)
				Matrix[i][j] = 0;
			else
				Matrix[i][j] = -1;
		}
	}
			
	int a=0, b=0;
	int zero = 0;
	char c;
	do{
		scanf("%d-%d", &a, &b);
		if(a == 0)
			zero = 1;
		if(zero == 0)
			Matrix[a-1][b-1] = 1;
		else
			Matrix[a][b] = 1;
	}while((c = getchar()) != '\n');//读入图
	 
	char cate;
	int x, y;
	while((c = getchar()) != EOF)
	{
		if(c == 'I')
		{
			scanf("%c", &cate);
			if(cate == 'V')
			{
				n++;
				scanf("(%d)", &x);
				if(zero == 0)
					InsertVex(Matrix, x-1);
				else
					InsertVex(Matrix, x);
			}else if(cate == 'A')
			{
				scanf("(%d,%d)", &x, &y);
				if(zero == 0)
					InsertArc(Matrix, x-1, y-1);
				else
					InsertArc(Matrix, x, y);
			}
		}else if(c == 'D'){
			scanf("%c", &cate);
			if(cate == 'V')
			{
				scanf("(%d)", &x);
				if(zero == 0)
					DeleteVex(Matrix, x-1);
				else
					DeleteVex(Matrix, x);
				n--;
			}else if(cate == 'A'){
			 	scanf("(%d,%d)", &x, &y);
			 	if(zero == 0)
					DeleteArc(Matrix, x-1, y-1); 
				else
					DeleteArc(Matrix, x, y);
			}
		}
		getchar();
	}
	
	int notempty = 0;//每一行是不是空
	int putfirst = 0;//标记每一行打印的第一个数 
	int count;//打印行数 
	
	for(i=0; i<10; i++)
	{
		notempty = 0;
		putfirst = 0;
		for(j=0; j<10; j++)
		{
			if(Matrix[i][j] != -1){
				notempty = 1;
				if(putfirst == 1)
					printf(",%d", Matrix[i][j]);
				else
					printf("%d", Matrix[i][j]);
				putfirst = 1;
			}	
		}
		if(notempty)
			count++;
		if(notempty == 1 && count != n)
			printf("\n");
	}
	
	return 0;
}
