#include<stdio.h>
#include<stdlib.h>

typedef struct Space{
    int tag;
    int start_ad;
    int size;
    struct Space *next;
}Space, *Spaceptr;

void CreateSpace(Spaceptr *L)
{
    Spaceptr p, q;
    *L = (Spaceptr)malloc(sizeof(Space));
    q = *L;
    char c;
    while((c = getchar()) != '1')
    {
    	c = getchar();
    	if(c == '\n')
    		break;
        p = (Spaceptr)malloc(sizeof(Space));
        p->tag = 0;
        scanf("%d %d", &p->start_ad, &p->size);
        q->next = p;
        q = p;
    }
    q->next = NULL;
}

void InsertSpace(Spaceptr *L)
{
    Spaceptr m, pre, n;
    m = (*L)->next;
    pre = *L;
    char c; 
    int start, size;
    while((c = getchar()) != EOF)
    {
    	c = getchar();
    	if(c == EOF)
    		break;
        scanf("%d %d", &start, &size);
        //新分配内存地址小于目前p地址区间
        while(m->start_ad+m->size < start){
            pre = m;
            m = m->next;
        }           
        if(m->start_ad <= start)//加个等于 
            m->size = m->size + size;
        else if(m->start_ad > start)
        {
            if(m->start_ad <= start + size)
            {
                m->size = m->start_ad - start + m->size;
                m->start_ad = start;
            }else{
                n = (Spaceptr)malloc(sizeof(Space));
                n->start_ad = start;
                n->size = size;
                n->tag = 0;
                pre->next = n;
                n->next = m;
            }
        }
    }
}

void PrintSpace(Spaceptr *L)
{
    Spaceptr p = (*L)->next;
    int state = 0;
    while(p != NULL)
    {
    	if(state == 0){
    		printf("%d %d %d", p->tag, p->start_ad, p->size);
    		state = 1;
		}else
    		printf("\n%d %d %d", p->tag, p->start_ad, p->size);
        p = p->next;
    }
}

void Together(Spaceptr *L)
{
	Spaceptr p = (*L)->next;
	while(p->next != NULL)
	{
		
			if(p->start_ad + p->size == p->next->start_ad)
			{
				p->size = p->size + p->next->size;
				p->next = p->next->next;
			}else
				p = p->next;
	}
}

int main()
{
    Spaceptr L;
    CreateSpace(&L);
    InsertSpace(&L);
    Together(&L);
    PrintSpace(&L);
    return 0;
}
