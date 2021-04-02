#include <iostream>
#include<stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 10
using namespace std; 
typedef int Status;
typedef enum{LEAF,BRANCH} NodeKind;
typedef struct TrieNode{
	NodeKind kind;//结点类型
	int height;
	int data[27];//记录每个结点的单词个数 
	//叶子结点
	char *lf[27];//深度达到时用于记录单词 
	//分支节点
	TrieNode *ptr[27];
}TrieNode, *TrieTree;

Status Add(TrieNode *t, char *item); 
void Ini(char *data);
Status Initial(TrieNode *t);
Status Output(TrieNode *t);
void Delete(TrieNode *t, char *item);
int result[MAXSIZE];

int main(){
	char item;
	int depth;
	int *m;
	TrieNode t;//根节点 
	TrieNode *pre;//用于指向父母结点 
	int i,j;
	char data[MAXSIZE];
	m = &i;
	cin >> item;
	depth = item - '0';
	cin >> item;
	Initial(&t);
	Ini(data);
	t.height = depth;
	i = 0;
	j = 0;
	for(i = 0; i < MAXSIZE; i++){
		result[i] = -1;
	}
	while((cin >> item) && item != '\n' && item != EOF){
		if(item >= 'a' && item <= 'z'){
			data[j++] =  item;
		}else if(item == ';'){
			data[j++] = '#';
			Add(&t, data);
			Ini(data);
			j = 0;
		}
	}
	data[j++] = '#';
	//Delete(&t, data);
	Ini(data);
	j = 0;
	i = 0;
	Output(&t);
	for(i = 0; i < MAXSIZE && result[i] != -1; i++){
		printf("%d",result[i]);
		if(result[i+1]!= -1){
			printf(",");
		}
	}
	return 0;
} 

void Ini(char *data){
	int i;
	for(i = 0; i < MAXSIZE;i++){
		data[MAXSIZE] = '#';
	}
}
Status Initial(TrieNode *t){
	int i;
	for(i = 0; i< 27; i++){
		t->ptr[i] = NULL;
		t->data[i] = 0;
		t->lf[i] = NULL; 
	}
	t->height = 0;
	t->kind = BRANCH;
	return OK;
}
Status Add(TrieNode *t, char *item){
	TrieNode *cur;//当前结点
	TrieNode *p;
	cur = t;
	int i;
	for(i = 0; i< t->height;i++){
		if(item[i] == '#'){
		//	cur->kind = LEAF;
			cur->lf[0] = item;
			break;
		}
		if(cur->ptr[item[i] - 'a'+1]){
			cur->data[item[i] - 'a' + 1] += 1;
			cur = cur->ptr[item[i] -'a'+1];
		}else{
			p = (TrieNode *)malloc(sizeof(TrieNode));
			Initial(p);
			cur->data[item[i] - 'a' + 1] += 1;
			p->height = cur->height - 1;
			cur->ptr[item[i] - 'a'+1] = p;
			cur = p;
		}
	}
	//cur->kind = LEAF;
	if(item[i] != '#')
		cur->lf[item[i] - 'a' + 1] = item;
	else
		cur->lf[0] = item;
	//叶子结点存储 
}
void Delete(TrieNode *t, char *item){
	TrieNode *cur;//当前结点
	TrieNode *p;
	cur = t;
	int i;
	for(i = 0; i< t->height;i++){
		if(item[i] == '#'){
		//	cur->kind = LEAF;
			cur->lf[0] = NULL;
			break;
		}
		if(cur->ptr[item[i] - 'a'+1]){
			cur->data[item[i] - 'a' + 1] -= 1;
			cur = cur->ptr[item[i] -'a'+1];
		}
	}
	//cur->kind = LEAF;
	if(item[i] != '#')
		cur->lf[item[i] - 'a' + 1] = NULL;
	else
		cur->lf[0] = NULL;
	//叶子结点存储 
}
Status Output(TrieNode *t){
	int i;
	static int k;
	if(!t){
		return ERROR;
	}
	if(t->kind == LEAF){
		return OK;
	}else{
		for(i = 1; i < 27; i++){
			if(t->ptr[i]){
			//	printf("%d,",t->data[i]);
				result[k++] = t->data[i];
				Output(t->ptr[i]);
			}
		}
		return OK;
	}
	return OK;
}
