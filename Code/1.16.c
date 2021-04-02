#include<stdio.h>

void swap(int *a, int *b);
 
int main()
{
    int x=0,y=0,z=0;
    int *n = &x;
    int *p = &y;
    int *q = &z;
    int tmp;
    scanf("%d %d %d", &x,&y,&z);
    if(x < y){
        swap(n, p);
    }
    if(z >= x){
        swap(p, q);
        swap(n, p);
    }else if(z > y && z < x){
        swap(p, q);
    }else{
        ;
    }
    
    printf("%d %d %d", x, y, z);
    
    return 0;
}

void swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
