#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *firstchild;
	struct node *next_sib;
}BinTree;

BinTree * ptr_array[1000];
char s[1000];
int front = 0, rear = 0;
int num = 0;
int ptr = 0;
BinTree* CreateBiTree(void)
{
    int n = num;
    int d, d1, d2;
    BinTree *t, *bt, *q;
    d = s[ptr++];
    if(d != 'n'){
        bt = (BinTree*)malloc(sizeof(BinTree));
        bt->data = d;
        bt->next_sib = bt->firstchild = NULL;
        ptr_array[rear++] = bt;
        n--;
    }else
        return NULL;
        
    while(n > 0 && ptr < num){
        t = ptr_array[front];
        front++;
        d1 = s[ptr++];
        if(d1 == 'n')
            t->firstchild = NULL;
        else{
            q = (BinTree*)malloc(sizeof(BinTree));
            q->data = d1;
            t->firstchild = q;
            q->next_sib = q->firstchild = NULL;
            ptr_array[rear++] = q;
            n--;
        }

        d2 = s[ptr++];
        if(d2 == 'n')
            t->next_sib = NULL;
        else{
            q = (BinTree*)malloc(sizeof(BinTree));
            q->data = d2;
            t->next_sib = q;
            q->next_sib = q->firstchild = NULL;
            ptr_array[rear++] = q;
            n--;
        }            
    }
    
    return bt;
}

int printstate = 0;
int count = 0;
void PrintBTree(BinTree *bt)
{
	int i = 0;
    if(bt != NULL && bt->data != 'n'){
    	if(printstate == 0){
    		for(i=0; i<count; i++)
    			printf(" ");
    		if(bt->data >= 'A' && bt->data <= 'Z')
    			printf("%c", bt->data);
    		else
    			printf("%d", bt->data);
    		printstate = 1;
		}else{
			printf("\n");
			for(i=0; i<count; i++)
				printf(" ");
			if(bt->data >= 'A' && bt->data <= 'Z')
    			printf("%c", bt->data);
    		else
    			printf("%d", bt->data);
		}
		if(bt->firstchild != NULL)
			count++;
			
	    PrintBTree(bt->firstchild);
	        
		if(bt->next_sib == NULL)
			count--;
				
        PrintBTree(bt->next_sib);
        	
				
		
    }
}

int main(void)
{
    BinTree *root;
    int i;
    int target;
    char c = getchar();
    while(c != '\n'){
    	if(c >= '0' && c <= '9')
    	{
	    	target = c - '0';
				while((c = getchar()) >= '0' && c <='9')
				{
					target = target * 10 + c - '0';
				}
	    	s[num] = target;
	        num++;
		}else if(c >= 'A' && c <= 'Z')
    	{
			s[num] = c;	
	        num++;
	        c = getchar();
		}else if(c == 'n'){
			s[num] = 'n';
			num++;
			c = getchar();
		}else{
			c = getchar();
		}	
    }
    root = CreateBiTree();
    PrintBTree(root);
    return 0;
}
