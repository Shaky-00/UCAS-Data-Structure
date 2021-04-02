#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXNum 200

typedef struct Chunk{
    char a[MAXNum];
    struct Chunk * next;
}chunk;


chunk * Createchunk(chunk * head, char * str)
{
    int length = strlen(str);

    int num = length/MAXNum;
    if (length % MAXNum) {
        num++;
    }
    head = (chunk*)malloc(sizeof(chunk));
    head->next = NULL;
    chunk *temp = head;
	int i=0, j=0;
    for (i=0; i<num; i++)
    {
        for (j=0; j<MAXNum; j++)
        {
            if (i * MAXNum + j < length) {
                temp->a[j] = str[i * MAXNum + j];
            }          
        }
        if (i*MAXNum + j < length)
        {
            chunk * newlink = (chunk*)malloc(sizeof(chunk));
            newlink->next = NULL;
            temp->next = newlink;
            temp = newlink;
        }
    }
    return head;
}

int main()
{
    chunk * head = NULL;
    char c;
    char s[10];
    int i, j, k;
    while((c = getchar()) != '\n')
	{
		s[i] = c;
		i++;
	}
	head = Createchunk(head, s);
	char t[i];
	for(k=0; k<i; k++)
	{
		t[k] = s[k];
	}
	
	int state = 0;
	for(j=0; j<i/2+1; j++)
	{
		if(t[j] == t[i-j-1])
			;
		else
		{
			state = 1;
			printf("No");
			break;
		}
	}
	if(state == 0)
		printf("Yes");
 
    return 0;
}

