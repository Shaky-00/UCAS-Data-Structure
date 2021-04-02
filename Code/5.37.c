#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;
typedef struct lnode
{
    int tag;//结点类型，0为原子，1为表
    union{
        ElemType data;
        struct lnode * sublist;
    }val;
    struct lnode * link;//指向下一个元素
}GLNode, *GList;//广义表结点类型定义


//合法输入：((a,2,3,v),a,(b,c,d),(a))
void CreateGList(GLNode *L)
{
	int data;
	char c;
	c = getchar();
	if(c != '\n')
	{
		if(c == '(')
		{
			L->tag = 1;
			L->val.sublist = (GLNode*)malloc(sizeof(GLNode));
			CreateGList(L->val.sublist); 
			scanf("%c", &c);
		}else if(c >= 'a' && c <= 'z')
		{
			data = c;
			L->tag = 0;
			L->val.data = data;
			scanf("%c", &c);
		}else{
			data = c - '0';
			while((c = getchar()) >= '0' && c <='9')
			{
				data = data*10 + c - '0';
			}	
			L->tag = 0;
			L->val.data = data;		
		}
	}else{
		L = NULL;
		scanf("%c", &c);
	}
	
	
	if(L != NULL)
	{
		if(c == ',')
		{
			L->link = (GLNode*)malloc(sizeof(GLNode));
			CreateGList(L->link);
		}else{
			L->link = NULL;
		}
	}
	
}

void printGList(GLNode *L)
{
	if(L != NULL)
	{
		if(L->tag == 1)
		{
			printf("(");
			printGList(L->val.sublist);
			printf(")");
		}else{
			if(L->val.data >= 'a' && L->val.data <= 'z')	
				printf("%c", L->val.data);
			else
				printf("%d", L->val.data);
		}
		
		if(L->link != NULL)
		{
			printf(",");
			printGList(L->link);
		}
	}	
}

GLNode* Del_elem(GLNode *L, char x)
{
	GLNode *p, *head;
	head = L;
	if(L != NULL)
	{
		if(L->tag == 0)
		{
			if(L->val.data == x)
			{
				p = L;
				L = L->link;
				free(p);
				L = Del_elem(L, x);
			}else{
				L->link = Del_elem(L->link, x);
			}			
		}else{
			L->val.sublist = Del_elem(L->val.sublist, x);
			L->link = Del_elem(L->link, x);
		}
	}	
	return L;
}

int main()
{
    GLNode *gl;
    gl = (GLNode*)malloc(sizeof(GLNode));
    
    int target;
	char c;
	c = getchar();
	if(c >= 'a' && c <= 'z')
	{
		target = c;
		c = getchar();
	}else{
		target = c - '0';
		while((c = getchar()) >= '0' && c <='9')
		{
			target = target * 10 + c - '0';
		}
	}
	
    CreateGList(gl);
    gl = Del_elem(gl, target);
    printGList(gl);
    
    return 0;
}
