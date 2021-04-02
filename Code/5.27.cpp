#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;
typedef struct lnode
{
    int tag;//������ͣ�0Ϊԭ�ӣ�1Ϊ��
    union{
        ElemType data;
        struct lnode * sublist;
    }val;
    struct lnode * link;//ָ����һ��Ԫ��
}GLNode, *GList;//�����������Ͷ���

//�Ϸ����룺((a,2,3,v),a,(b,c,d),(a))
void CreateGList(struct GLNode **L)
{
    char c;
    scanf("%c", &c);
    
	if (c == '(')
    {
        *L = malloc(sizeof(GList));
        (*L)->tag = 1;
        CreateGList(&((*L)->sublist)); //�ݹ�
    }else{
        *L = malloc(sizeof(GList));
        (*L)->tag = 0;
        (*L)->data = ch;
    }
    scanf("%c", &c); 
    
    if(c == ',' && *L != NULL)
        CreateGList_char(&((*L)->link));
    else if(*L != NULL && c == ')' || c == ';')
        (*L)->link = NULL;
}


void PrintGList(struct GLNode *L)
{
    if(L->tag == 1)
    {
        printf("("); 
        if(GL->sublist == NULL)
            printf("%c", ' ');
        else
            PrintGList(L->sublist);
        
		printf(")");
    }else if(L->tag == 0)
        printf("%c", L->data);
    
	if (L->next != NULL) //����㻹�к�̱�����ݹ����
    {
        printf("%c", ','); //��������ŷָ���
        PrintfGList_char(L->link); //�ݹ�
    }
}
