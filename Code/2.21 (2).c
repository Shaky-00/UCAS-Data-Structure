#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define SIZE 30
#define STACKINCREMENT 10
#define MAXBUFFER 10

typedef char ElemType;

typedef struct
{
    ElemType *base;
    ElemType *top;
    int StackSize;
}SqStack;

void InitStack(SqStack *s)
{
    s->base=(ElemType *)malloc(SIZE*sizeof(ElemType));
    if(!s->base)
        exit(0);
    s->top=s->base;
    s->StackSize=SIZE;
}

void Push(SqStack *s,ElemType e)
{
    if(s->top - s->base == s->StackSize)
    {
        s->base=(ElemType *)realloc(s->base,(s->StackSize+STACKINCREMENT)*sizeof(ElemType));
        if(!s->base)
            exit(0);
        s->top = s->base + s->StackSize;
        s->StackSize = s->StackSize + STACKINCREMENT;
    }
    *(s->top)=e;
    s->top++;
}

void Pop(SqStack *s,ElemType *e)
{
    if(s->top==s->base)
        return;
    *e=*(--(s->top));
}

int StackLength(SqStack s)//测试传数据，修改传指针
{
    return(s.top-s.base);
}

int main()
{
    SqStack s;
    char c, x;
    InitStack(&s);
    scanf("%c",&c);
    while(c!='\n')
    {
        while((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            printf("%c",c);
            scanf("%c",&c);
        }
        
        if(c==')')
        {
            Pop(&s, &x);
            while(x!='(')
            {
                printf("%c",x);
                Pop(&s, &x);
            }
        }else if(c=='+' || c=='-'){
            if(!StackLength(s))
            {
                Push(&s, c);
            }else{
                do{
                    Pop(&s, &x);
                    if(x == '(')
                    {
                        Push(&s, x);
                    }else{
                        printf("%c", x);
                    }
                }while(StackLength(s) && '('!=x);
                
				Push(&s, c);
            }
        }else if(c=='*' || c=='/'){
        	while(StackLength(s) && x != '(')
        	{
			Pop(&s, &x);
        		if(x != '+' && x != '-'){
        			printf("%c", x);
				}else{
        			Push(&s, x);
        			break;
				}
			}
        	
            Push(&s, c);
        }else if(c == '(')
        	Push(&s, c);
		else if(c == '\n')
        	break;
        else{
            printf("error!\n");
            return -1;
        }
        
        scanf("%c", &c);
    }
    
    while(StackLength(s) != 0)
    {
        Pop(&s, &x);
        printf("%c", x);
    }
    
    return 0;
}
