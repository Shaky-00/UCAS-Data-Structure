#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;
typedef struct LString
{
	ElemType chdata;
	int order;
	struct LString * succ;
	struct LString * next;
}LString;

int lengthS = 0;
int lengthT = 0;

LString *Create_nextval(LString * head)
{
	LString *p, *q;
	ElemType n;
	head = p = (LString *)malloc(sizeof(LString));
	head->next = NULL;
	head->order = 0;
	char c;
	
	while((c = getchar()) != '\n')
	{
		lengthT++;
		q = (LString *)malloc(sizeof(LString));
		p->succ = q;
		q->chdata = c;
		q->order = lengthT;
		p = q;	
	}
	q->succ = NULL;
	
	LString *i, *j;
	i = head->succ;
	j = head;
	i->next = head;

	while(i->succ != NULL)
	{
		if(j == head || i->chdata == j->chdata)
		{
			i = i->succ;
			j = j->succ;
			if(i->chdata != j->chdata)
				i->next = j;
			else
				i->next = j->next;
		}else
			j = j->next;
	}
	return head;
}

int Index_KMP(LString *S, LString *T, int pos)
{
	LString *i, *j;
	int k;
	i = S->succ;
	for(k=1; k<pos; k++)
	{
		i = i->succ;
	}
	j = T->succ;
	int count = pos, jval = 1;
	while(count <= lengthS && jval <= lengthT)
	{
		if(j == T || i->chdata == j->chdata)
		{
			i = i->succ;
			j = j->succ;
			++count;
			++jval;
		}else{
			j = j->next;
			jval = j->order;
		}
			
	}

	if(jval > lengthT)
		return count - lengthT;
	else
		return 0;
}

LString *Create_String(LString *head)
{
	LString *p, *q;
	ElemType n;
	head = p = (LString *)malloc(sizeof(LString));
	head->next = NULL;
	char c;
	while((c = getchar()) != '\n')
	{
		q = (LString *)malloc(sizeof(LString));
		p->succ = q;
		q->next = p;
		q->chdata = c;
		p = q;
		lengthS++;
	}
	q->succ = NULL;

	return head;
}

void printNext(LString *p)
{
	int i = 0;
	int state = 0;
	p = p->succ;
	while(i < lengthT)
	{
		if(state == 0)
		{
			printf("%d", p->next->order);
			state = 1;
		}else
			printf(" %d", p->next->order);
		
		p = p->succ;
		i++;
	}
}

int main()
{
	LString * T, * S;
	int i = 1;
	char c;	
	S = Create_String(S);
	T = Create_nextval(T);
	int state = 0;
	while(Index_KMP(S, T, i) <= lengthS && Index_KMP(S, T, i) != 0)
	{
		if(state == 0){
			printf("%d", Index_KMP(S, T, i));
			state = 1;
		}else
			printf(" %d", Index_KMP(S, T, i));
			
		i = Index_KMP(S, T, i) + 1;
	}
	printf("\n");
	printNext(T);
	
	return 0;
}
