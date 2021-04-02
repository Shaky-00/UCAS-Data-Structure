#include<stdio.h>
#include<stdlib.h>
int s[50];
int fst[50];
int lst[50];
int main()
{
	int judge_result[50];
	int n;
	scanf("%d", &n);
	int i;
	char c;
	for(i=0; i<50; i++)
		judge_result[i] = 0;
	c = getchar();
	i=0;
	while((c = getchar()) != '\n')
	{
		if(c != ' ')
			s[i] = s[i] * 10 + c - '0';
		else
			i++;
	}
	i=0;
	while((c = getchar()) != '\n')
	{
		if(c != ' ')
			fst[i] = fst[i] * 10 + c - '0';
		else{
			i++;
		}		
	}
	i=0;
	while((c = getchar()) != '\n')
	{
		if(c != ' ')
			lst[i] = lst[i] * 10 + c - '0';
		else{
			i++;
		}
	}
	
	for(i=1; i<=n; i++)
	{
		Judge(i, i, judge_result);
		if(judge_result[i] == 1){
			printf("yes");
			return 0;
		}
	}
	printf("no");
	
	return 0;
}

int Judge(int start, int i, int judge_result[])
{
	int j;
	int x = fst[i];
	int y = lst[i];
	if(x > y)
		return 0;
	else{
		for(j=x; j<y; j++)
		{
			if(s[j] != start)
				Judge(start, s[j], judge_result);	
			else{
				judge_result[start] = 1;
				return 1;
			}	
		}
	}
	return 0;
}
