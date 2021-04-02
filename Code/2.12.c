#include<stdio.h>
#define ARR1 1
#define ARR2 2

int getline(char s[],int lim){
    int c,i;
    i=0;
    while((c=getchar())!=EOF&&c!='\n'&&i<lim-1)
        s[i++]=c;
    s[i]='\0';
    return i;
}

int main()
{
	char arr[100];
	int len;
	len = getline(arr, 100);
	int i, j, k, m;
	char temp1[len];
	char temp2[len];
	int state = ARR1;
	j = 0;
	k = 0;
	for(i=0; i<len; i++)
	{
		if(arr[i] >= 'a' && arr[i] <= 'z')
		{
			if(state == ARR1)
			{
				temp1[j] = arr[i];
				j++;
			}else{
				temp2[k] = arr[i];
				k++;
			}		
		}else if(arr[i] == ','){
			continue;
		}else if(arr[i] == ';'){
			state = ARR2;
		}else{
			break;
		}
	}
	int l1, l2;
	
	int equal;
	if(j > k)
	{
		for(i=0; i<k; i++)
		{
			if(temp1[i] > temp2[i])
			{
				equal = 0;
				printf("2");
				break;
			}else if(temp1[i] < temp2[i]){
				equal = 0;
				printf("1");
				break;
			}else{
				equal = 1;
				continue;
			}
		}
		if(equal == 1)	
			printf("2");
	}else if(j < k){
		for(i=0; i<j; i++)
		{
			if(temp1[i] > temp2[i])
			{
				equal = 0;
				printf("2");
				break;
			}else if(temp1[i] < temp2[i]){
				equal = 0;
				printf("1");
				break;
			}else{
				equal = 1;
				continue;
			}
		}
		if(equal == 1)	
			printf("1");
	}else{
		for(i=0; i<j; i++)
		{
			if(temp1[i] > temp2[i])
			{
				equal = 0;
				printf("2");
				break;
			}else if(temp1[i] < temp2[i]){
				equal = 0;
				printf("1");
				break;
			}else{
				equal = 1;
				continue;
			}
		}
		if(equal == 1)
			printf("0");	
	}
	
	return 0;
}
