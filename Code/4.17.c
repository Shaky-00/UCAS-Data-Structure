#include<stdio.h>
#include<stdlib.h>
#define INITSTRLEN 50
#define ERROR 0
#define OK 1
typedef struct{
	char * ch;
	int length;
	int strsize;
}HString;
typedef int Status;

int replace = 0;

Status StrInit(HString * s)
{
	s->ch = (char*)malloc(INITSTRLEN * sizeof(char));
	if(!s->ch)
		return ERROR;
	s->ch[0] = '\0';
	s->length = 0;
	s->strsize = INITSTRLEN;
	return OK;
 } 
 
Status CreateStr(HString * s)
{
	char c;
	int i = 0;
	if(StrInit(s))
	{
		while((c = getchar()) != ' ' && c != '\n')
		{
			s->ch[i] = c;
			i++;
			s->length++;
		}	
	}	 
}

void Replace(HString *a, HString *m, HString *n)
{
	int i=0, j=0;
	int state = 1;
	while(i <= a->length - m->length)
	{
		j = 0;
		if(a->ch[i] == m->ch[j])
		{
			for(j=0; j<m->length; j++)
			{
				if(a->ch[i+j] == m->ch[j])
					state = 0;
				else{
					state = 1;
					break;
				}
			 } 
			if(state == 0)
			{
				for(j=0; j<n->length; j++)
				{
					a->ch[i] = n->ch[j];
				}
				a->length = a->length + n->length - m->length;
				
				for(j=i+n->length; j<a->length; j++)
				{
					a->ch[j] = a->ch[j+m->length-n->length];
				}
			}
		}
		if(state == 0)
		{
			i = i+m->length;
			replace = 1;
		}else
			i = i+1;
	}
}


int main()
{
	HString *a, *m, *n;
	int i = 0;
	a = (HString*)malloc(sizeof(HString));
	m = (HString*)malloc(sizeof(HString));
	n = (HString*)malloc(sizeof(HString));
	int lengthA = 0, lengthM = 0, lengthN = 0;

	CreateStr(a);
	CreateStr(m);
	CreateStr(n);
	Replace(a, m, n);
	if(replace == 1)
		for(i=0; i<a->length; i++)
		{
			printf("%c", a->ch[i]);
		}
	
	return 0;
}
