#include<stdio.h>
#include <stdlib.h>

void HeapAdjust(int *s, int head, int tail){
	int rc;
	int i;
	rc = s[head];
	for(i=2*head; i<tail; i*=2){
		if(i < tail && s[i] > s[i+1]){
			i++;
		}
		if(rc <= s[i]){
			break;
		}
		s[head] = s[i];
		head = i;
	}
	s[head] = rc;
}

int main(){
	int s[100];
	int i;
	char c;
	int data;
	int count;
	for(i = 0; i < 100; i++)
		s[i] = -1;
	
	i = 1;
	data = 0;
	while((c = getchar()) != '\n'){
		if(c >= '0' && c <= '9'){
			data = data * 10 + c - '0';
		}else if(c == ','){
			s[i] = data;
			data = 0;
			i++;
		} 
	}	
	s[i] = data;
	count = i;

	for(i=1; i<=count; i++)
		printf("%d ", s[i]);
	printf("\nlength=%d\n", count); 
	for(i = count/2; i > 0; --i)
		HeapAdjust(s, i, count);
		
	for(i = count; i>1;--i){
		printf("%d,", s[1]);
		s[1] = s[i];
		HeapAdjust(s, 1, i); 
	}
	printf("%d",s[i]);
	return 0;
}

