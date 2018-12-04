#include<iostream>
#include<cstdio>  
#include<queue>  
#include<algorithm>  
#include<string.h>
using namespace std;  


typedef struct Node{  
    char data;  
    struct Node *lchild;  
    struct Node *rchild;  
}Node, *BiTree;   
queue<Node*> Q;

char ins[1000], posts[1000];

Node* CreateTree(int s1,int e1,int s2,int e2)
{
	//ºóÐòÈ·¶¨¸ù£¬Ç°ÐòºóÐòÈ·¶¨×óÓÒ×ÓÊ÷
	Node* T = (Node*)malloc(sizeof(Node)) ;
	if( e1 - s1 == 0){
		T->data = ins[s1];
		T->lchild = NULL;
		T->rchild = NULL;
		return T;
	}
	if(e1 < s1 || e2 < s2){
		return NULL;
	}
	
	T->data = posts[e2];
	int r;
	for(int i = s1;i <= e1;i ++){
		if(posts[e2] == ins[i]){
			r = i;
			break;
		}
	}
	T->lchild = CreateTree(s1,r-1,s2,s2-1+r-s1);
	T->rchild = CreateTree(r+1,e1,s2+r-s1,e2-1);
	return T;
	
}

void bfs(Node *T)
{
	Q.push(T);
	while(!Q.empty()){
		Node *N = Q.front() ;
		Q.pop() ;
		if(N)
		printf("%c",N->data );
		if((N->lchild))
		Q.push(N->lchild );
		if((N->rchild))
		Q.push(N->rchild );
	}
	printf("\n");
}

int main()
{
	gets(ins);
	int len1 = strlen(ins);
	gets(posts);
	int len2 = strlen(posts);
	Node * root = CreateTree(0,len1-1,0,len2-1);
	bfs(root);
	return 0;
}