#include<stdio.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1

typedef int Status;
typedef enum{Easr, South, West, North} Direction;
typedef struct{
	int x;
	int y;
	int direct;
}ElemType;

void Color(int g[][17], ElemType start);
void InitGraph(int g[][17], ElemType *start);
void PaintGraph(int g[][17]);
Status Pass(ElemType e, int g[][17]);
void Mark(ElemType *e, int g[][17]);
Status NextPos(ElemType *e);
Status IsCross(ElemType e);

int row_size, column_size;
int direction;
int main()
{
	int x, y;
	int category;
	scanf("%d%d%d%d%d%d", &row_size, &column_size, &x, &y, &direction, &category);
	int g[row_size][column_size];
	ElemType start;
	InitGraph(g, &start);
	PaintGraph(g);
	
	Color(g, start);
	
	return 0;
}

void Color(int g[][17], ElemType start)
{
	ElemType e;
	ElemType stack[10000];
	int top = -1;
	
	e = start;
	do{
		if(Pass(e, g))
		{
			Mark(&e, g);
			ShowGraph(g);
			stack[++top] = e;
			NextPos(&e);
		}else{
			if(top != -1)
			{
				e = stack[top--];
				while(e.direct == North && top != -1)
					e = stack[top--];
				if(e.direct < North)
				{
					e.direct++;
					stack[++top] = e;
					NextPos(&e);
				}
			}
		}
	}while(top != -1);
}

void InitGraph(int g[][17], ElemType *start)
{
	int i, j;
	int matrix[row_size][column_size];
	
	switch(row_size)
	{
		case 10: 
				matrix[row_size][column_size] = {	{0,0,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0},
								                	{0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0},
								                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
								                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
								                    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
								                    {0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
								                    {0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0},
								                    {0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0},
								                    {0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0},
								                    {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0}}; break;
		  
																			                
		case 8:  matrix[row_size][column_size] = {  {0,0,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0},
								                    {0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0},
								                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
								                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
								                    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
								                    {0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
								                    {0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0},
								                    {0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0}}; break;
	
		case 6: matrix[row_size][column_size] = {   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
								                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
								                    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
								                    {0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
								                    {0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0},
								                    {0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0}}; break;
		
		case 7: matrix[row_size][column_size] = {   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
								                    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
								                    {0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
								                    {0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0},
								                    {0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0},
								                    {0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0},
								                    {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0}}; break;
		
		case 5: matrix[row_size][column_size] = {   {0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
								                    {0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0},
								                    {0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0}, 
								                    {0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0},
								                    {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0}}; break;
		default:
			printf("error!\n");
	}
	
	for(i=0; i<row_size; i++)
	{
		for(j=0; j<column_size; j++)
			g[i][j] = matrix[i][j];
	}
	
	(*start).x = xpoint;
	(*start).y = ypoint;
	switch(direction)
	{
		case 0:(*start).direct = North;
		case 1:(*start).direct = South;
		case 2:(*start).direct = West;
		case 3:(*start).direct = East;
	}	
}

void PaintGraph(int g[][17])
{
	int i, j;
	for(i=0; i<row_size; i++)
	{
		for(j=0; j<column_size; j++)
		{
			if(g[i][j] == 0)
				printf(".");
			if(g[i][j] == 1)
				printf("#");
			if(g[i][j] == 2)
				printf("*");
		}
		if(i != row_size - 1)
			printf("\n");
	}
}

Status Pass(ElemType e, int g[][17])
{
	int x = e.x;
	int y = e.y;
	
	if(g[x][y] == 2)
		return TRUE;
	else
		return FALSE;
}

void Mark(ElemType *e, int g[][17])
{
	int x = (*e).x;
	int y = (*e).y;
	
	switch(direction)
	{
		case 0:(*start).direct = North;
		case 1:(*start).direct = South;
		case 2:(*start).direct = West;
		case 3:(*start).direct = East;
	}
	
	g[x][y] = 2;	
}

Status NextPos(ElemType *e)
{
	ElemType tmp;
	tmp = *e;
	
	switch(tmp.direct)
	{
		case East:
			(tmp.y)++;
		case South:
			(tmp.x)++;
		case West:
			(tmp.y)--;
		case North:
			(tmp.x)--;
		default:
			return FALSE;
	}
	
	if(IsCross(tmp))
	{
		++(*e).direct;
		NextPos(e);
	}else
		*e = tmp;
		
	return TRUE;
}

Status IsCross(ElemType e)
{
	int x = e.x;
	int y = e.y;
	
	if(x<0 || y<0 || x>row_size || y>column_size)
		return TRUE;
	else
		return FALSE;
}
