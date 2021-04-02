#include<stdio.h>


int a[10][17] ={{0,0,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0},
		{0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
		{0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0},
		{0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0}};
	
int b[8][17] ={{0,0,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0},
		{0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
		{0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0},
		{0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0}};
		
int c[6][17] ={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
		{0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0},
		{0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0}};
		
int d[7][17] ={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
		{0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0},
		{0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0}};
	
int e[5][17] ={{0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
		{0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0},
		{0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0}, 
		{0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0}};

int row_size;
int column_size;
int direction;
int category;


void PaintGraph(int g[][17]);
void change_color(int g[][17], int row_size, int column_size, int x, int y, int direction);

int main()
{
	int x, y;
	int i, j;
	scanf("%d %d %d %d %d %d", &row_size, &column_size, &x, &y, &direction, &category);
	int matrix[row_size][17];
	int mark[row_size][17];
	switch(row_size)
	{
		case 10: 
			for(i=0; i<row_size; i++)
			{
				for(j=0; j<column_size; j++)
					matrix[i][j] = a[i][j];
			}
			break;																		                
		case 8: 
			for(i=0; i<row_size; i++)
			{
				for(j=0; j<column_size; j++)
					matrix[i][j] = b[i][j];
			}
			break;
	
		case 6: 
			for(i=0; i<row_size; i++)
			{
				for(j=0; j<column_size; j++)
					matrix[i][j] = c[i][j];
			}
			break;
		case 7: 
			for(i=0; i<row_size; i++)
			{
				for(j=0; j<column_size; j++)
					matrix[i][j] = d[i][j];
			}
			break;
		
		case 5: 
			for(i=0; i<row_size; i++)
			{
				for(j=0; j<column_size; j++)
					matrix[i][j] = e[i][j];
			}
			break;
		default:
			;
	}
	change_color(matrix, row_size, column_size, x, y, direction);
	PaintGraph(matrix);
	
	return 0;
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


int range = 0;
void change_color(int g[][17], int row_size, int column_size, int x, int y, int direction)
{
	int color;
	int i = 0, count = 0;
	color = g[x][y];
	g[x][y] = 2;
	int dir[4];
	for(i=0; i<4; i++)
	{
		dir[i] = (direction+i) % 4;
	}
	
	while(count < 4)
	{
		switch (dir[count])
		{
			case 0:
				if(x-1 >= 0)
					if(g[x-1][y] == color)
						change_color(g, row_size, column_size, x-1, y, direction);
				count++;
				break;
			case 1:
				if(x+1 <= row_size)
					if(g[x+1][y] == color)
						change_color(g, row_size, column_size, x+1, y, direction);
				count++;
				break;
			case 2:
				if(y-1 >= 0)
					if(g[x][y-1] == color)
						change_color(g, row_size, column_size, x, y-1, direction);
				count++;
				break;
			case 3:
				if(y+1 <= column_size)
					if(g[x][y+1] == color)
						change_color(g, row_size, column_size, x, y+1, direction);
				count++;
				break;
		}
	 } 		
}
