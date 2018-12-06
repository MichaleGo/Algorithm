
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

typedef struct Arc{
	int e;
	struct Arc *next; 
}Arc;

typedef struct Node{
	char data;
	Arc *firstlink;
}Node; 

Node node[1000];
int vis[1000];
Node que[1000];
int front = 0, rear = 0;

void Insert(int s,int e){
	Arc *head = node[s].firstlink ;
	while(head && head->e > e){
		head = head->next ;
	}
	Arc *p = (Arc*) malloc(sizeof(Arc));
	p->e = e;
	p->next = head->next ;
	head->next = p;
}

void BFS(int index){
	
	vis[index] = 1;
	que[rear++] = node[index];
	int i = 1;
	while(front < rear){
		Node t = que[front++];
		cout<<t.data ;
		Arc* p = t.firstlink->next ;
		while(p&&!vis[p->e ]){
			vis[p->e] = 1;
			que[rear++] = node[p->e];
			p = p->next ;
		}	
	}
}

void output(int n){
	cout<<"the ALGraph is"<<endl;
	int i = 0;
	while(n){
		n--;
		cout<<node[i].data ;
		Arc* p = node[i].firstlink->next ;
		while(p){
			cout<<" "<<p->e ;
			p = p->next ;
		}
		cout<<endl;
		i++;
	}
}
int main(){
	for(int i = 0;i < 1000;i ++){
		node[i].data = '\0';
		node[i].firstlink =(Arc*) malloc(sizeof(Arc));
		node[i].firstlink->next = NULL;
		node[i].firstlink->e = -1;
	}
	int n = 0,s,e;
	char c;
	while(scanf("%c",&c)&&c!='*'){
		getchar();
		node[n++].data = c;
	}
	getchar();
	while(scanf("%d,%d",&s,&e)&&(s!=-1)){
		Insert(s,e);
		Insert(e,s);	
	}
	output(n);
	memset(vis,0,sizeof(vis));
	memset(que,0,sizeof(que)); 
	cout<<"the Breadth-First-Seacrh list:";
	for(int i = 0;i < n;i ++){
		if(!vis[i]){
			front = 0,rear = 0;
			BFS(i);
		}
	}
	cout<<endl;
	return 0;
}