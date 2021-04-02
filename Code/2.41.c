#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<malloc.h>

typedef int status;
typedef int ElemType;
typedef struct NodeType
{
    int coef;
    int expn;
    NodeType *next;
}*Polynomial, *LinkType;

char a[50];
int i = 0;
int makenum(int j)
{
	int sum = 0;
	i = j;
	while(a[i] >= '0' && a[i] <= '9')
	{
		sum = sum * 10 + a[i] - '0';
		i++;
	}
	
	return sum;
}

int cut = 0;
void CreatePolyn(Polynomial &L)  
{    
    int sign = 1;
    
    L=(Polynomial)malloc(sizeof(NodeType));
    L->next = NULL;
    Polynomial p, q;
    q = L;
	char c;	
    p = (Polynomial)malloc(sizeof(NodeType));  
    while ((c = getchar()) != '\n')
    {
        a[i++] = c;
    }
    a[i] = '\0';
    
    i = 0;
    p->coef = 1;
    p->expn = 0; 
    if(a[i] == '-'){
    	p->coef *= -1;
    	i = i+2;
	}
    	
    if(a[i] >= '0' && a[i] <= '9')
		p->coef *= makenum(i);
	
	if(a[i] == 'x'){
		cut = 1;
		p->expn = 1;
		i += 1;
		if(a[i] == '^'){
			p->expn = makenum(++i);
		}
	}	 
	q->next = p;
	q = q->next;

	while(a[i] != '\0')
	{
		if(a[i] == ' ')
			i++;
		p = (Polynomial)malloc(sizeof(NodeType));
		p->coef = 1;
		p->expn = 0;
		if(a[i] == '-'){
	    	p->coef *= -1;
	    	i++;
		}else if(a[i] == '+'){
			p->coef *= 1;
			i++;
		}
		if(a[i] == ' ')
			i++;
		if(a[i] >= '0' && a[i] <= '9')
		p->coef *= makenum(i);
	
		if(a[i] == 'x'){
			cut = 1;
			p->expn = 1;
			i += 1;
			if(a[i] == '^'){
				p->expn = makenum(++i);
			}
		}
		q->next = p;
		q = q->next;
	}
	p->next = NULL;
} 

void SortPolyn(Polynomial &P)
{
    LinkType p, q, r;
    q = P->next;
    P->next = NULL;
    
    while(q!=NULL)        
    {
    	p = P;
        while(p->next != NULL && p->next->expn > q->expn)
            p = p->next;
        r = q->next;
        q->next = p->next;
        p->next = q;
        q = r;
    }
}

void Delexpn0Node(Polynomial &P)
{
    LinkType p,q;
    q = P;
    p = q->next;
    while(p != NULL)
    {
        if(p->expn == 0)
        {
            q->next = p->next;
            free(p);
            p = q->next;
        }else{
        q = p;
        p = q->next;
		}   
    }
}

void Delcoef0Node(Polynomial &P)
{
    LinkType p,q;
    q = P;
    p = q->next;
    while(p != NULL)
    {
        if(p->coef == 0)
        {
            q->next = p->next;
            free(p);
            p = q->next;
        }else{
        q = p;
        p = q->next;
		}   
    }
}

void PolynTraverse(Polynomial L)
{
	Polynomial p = L->next;
	if(p->coef < 0)
		printf("- ");
	printf("%dx^%d", abs(p->coef), p->expn);
	p = p->next;
	while(p)
	{
		if(p->coef >= 0 && p->coef != 1 && p->expn != 0 && p->expn != 1)
			printf(" + %dx^%d", abs(p->coef), p->expn);
		else if(p->coef == 1 && p->expn != 0)
			printf(" + x^%d", abs(p->expn));
		else if(p->coef > 0 && p->expn == 0)
			printf(" + %d", abs(p->coef));
		else if(p->coef > 0 && p->expn == 1)
			printf(" + %dx", abs(p->coef));
		else if(p->coef == 1 && p->expn == 1)
			printf(" + x");
		else if(p->coef < 0 && p->coef != -1 && p->expn != 0 && p->expn != 1)
			printf(" - %dx^%d", abs(p->coef), p->expn);
		else if(p->coef == -1 && p->expn != 0)
			printf(" - x^%d", abs(p->expn));
		else if(p->coef < 0 && p->expn == 0)
			printf(" - %d", abs(p->coef));
		else if(p->coef < 0 && p->expn == 1)
			printf(" - %dx", abs(p->coef));
		else if(p->coef == -1 && p->expn == 1)
			printf(" - x");
		
		p = p->next;
	}
}

void Central(Polynomial P)
{
    LinkType p, q;
    int coef = 1;
    int expn = 0;
    p = P->next;

    while(p != NULL)
    {
        if(p->expn == 0)
            p = p->next;
        else{
            coef = p->coef * p->expn;
            expn = p->expn - 1;
            
            p->coef = coef;
            p->expn = expn;
            p = p->next;
        }
    }
}
 
 void MergePolyn(Polynomial &P)
{
    LinkType p, q, r;
    p = P->next;
    while(p!=NULL)
    {
        q = p;
		r = p->next;
        while(r!=NULL)
        {
            if(p->expn == r->expn)
            {
                p->coef = p->coef + r->coef;
                q->next = r->next;
                free(r);
            	r = q->next;
            }else{
                q = r;
                r = q->next;
            }
        }
        p = p->next;
  	}
	Delcoef0Node(P);
}
int main()
{
	Polynomial L;
	
	CreatePolyn(L);
	Delexpn0Node(L);
	MergePolyn(L);	
	if(L->next)
	{
		SortPolyn(L);
		Central(L);	
		PolynTraverse(L);
	}else{
		printf("0");
	}
	
	
	return 0;
}
