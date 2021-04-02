#include <iostream>
#include<stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
using namespace std; 
void HeapAdjust(int *s, int head, int tail);
void HeapSort(int *s,int count);
int main(){
	int s[100];
	int i;
	int k;
	int temp;
	char item;
	int data;
	int count;
	for(i = 0; i < 100; i++){
		s[i] = -100;
	}
	i = 1;
	data = 0;
	while(cin >> item && item != '\n' && item != EOF){
		if(item == '[' || item == ']'){
			continue;
		}else if(item >= '0' && item <= '9'){
			data = data *10 + (item - '0');
		}else if(item == ',' || item == ';'){
			s[i] = data;
			data = 0;
			i++;
		} 
	}	
	s[i] = data;
	count = i;

	HeapSort(s,count);
	return 0;
}

void HeapAdjust(int *s, int head, int tail){
	int rc;
	int j;
	rc = s[head];
	for(j = 2*head; j< tail; j*=2){
		if(j<tail&&s[j]>s[j+1]){
			j++;
		}
		if(rc <= s[j]){
			break;
		}
		s[head] = s[j];
		head = j;
	}
	s[head] = rc;
}

void HeapSort(int *s,int count){
	int i;
	for(i = count/2; i > 0; --i){
		HeapAdjust(s, i, count);
	}
	for(i = count; i>1;--i){
		printf("%d,",s[1]);
		s[1] = s[i];
		HeapAdjust(s,1,i); 
	}
	printf("%d",s[i]);
}

