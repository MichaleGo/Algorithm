
#include<stdio.h>
#include<string.h>

int N,M;
int maze[100][100];
const int INF = 1000; 

typedef struct pos{
	int x;
	int y;
	int f;
}pos;
pos que[100];
int visited[100][100];

pos output_array[100];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main()
{	
	int i,j;
	scanf("%d %d",&N,&M);
	for(i = 0;i < 100;i++){
		output_array[i].x = INF;
		for(j = 0;j < 100;j++){
			maze[i][j] = INF;
			visited[i][j] = INF; //all initiaed INF
		}
	}
	for(i = 1;i <= N;i++){
		for(j = 1;j <= N;j++){
			scanf("%d",&maze[i][j]) ; //input 1~N
		}
	}
	
	
	pos s;//队列初始化 
	s.x = 1;
	s.y = 1;
	s.f = -1;
	int head = 0, nail = 1;
	que[head] = s;
	visited[1][1] = 0;
	
	
	int x,y,tmp;
	while(head!=nail){//还未遍历结束 
		s = que[head];
		if(s.x == N && s.y == N) {//找到出口，提起前结束。 
			//head 指向 出口
			while(s.f!=(-1)) {
				tmp = visited[s.x][s.y];
				output_array[tmp] = s;
				head = s.f;
				s=que[head];
			}
			output_array[0] = s;
			i = 0;
			while(output_array[i].x != INF){
				printf("<%d,%d> ",output_array[i].x,output_array[i].y);
				i++;
			}
			printf("\n");
			return 0;
		}else{//遍历，符合条件入队，nail++，visited，完成后head++ 
			for(i = 0;i < 4;i ++){
				x = s.x +dx[i];
				y = s.y +dy[i];
		        if(0<x && x<=100 && 0<y && y<=100 && visited[x][y] == INF &&maze[x][y] == 0){
		        	que[nail].x = x ;
		        	que[nail].y = y ;
		        	que[nail].f = head;
		        	nail ++;
		        	visited[x][y] = visited[s.x][s.y] + 1;
				}
			}
			head++;
			//遍历当前节点符合要求的四周结点，入队nail++，head++
		}
		 
		
	}
	printf("There is no solution!\n");
	return 0;
	
	
}/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{   int         data;
    struct node * next;
} NODE;

NODE * find( NODE * , int * );
void outputring( NODE * );
void change( int , int , NODE * );

void outputring( NODE * pring )
{	NODE * p;
	p = pring;
	if ( p == NULL )
		printf("NULL");
	else
		do
		{	printf("%d", p->data);
			p = p->next;
		} while ( p != pring );
	printf("\n");
	return;

}

void output( NODE * head )
{   int k=0;

	printf("0.");
	while ( head->next != NULL && k<50 )
	{   printf("%d", head->next->data );
		head = head->next;
		k ++;
	}
	printf("\n");
}

int main()
{   int n, m;
	NODE * head, * pring;

	scanf("%d%d", &n, &m);
	head = (NODE *)malloc( sizeof(NODE) );
	head->next = NULL;
	head->data = -1;

	change( n, m, head );
	//output( head );
	pring = find( head, &n );
	printf("ring=%d\n", n);
	outputring( pring );

	return 0;
}


void change( int n, int m, NODE* head )
{
	NODE *p = head ;
	int i = 0, len = 0;
	long long int a[50000];
	for(i = 0;i < 50000;i ++){
		a[i] = 0;
	}
	memset(a,0,sizeof(a));
	int count = 0;
	n = n*10;//万一n溢出怎么办？ 
	while(1)
	{
		//余数为0 
		if(n == 0)break;
		
		//余数重复出现 
		int flag = 0;
		if(a[n] != 0)
		{
			flag = a[n];
		 } 
		if(flag>0)
		{
			int j = 1;
			NODE *q = head->next ;//变量需要使用的时候再定义 
			while(j<flag){
				q = q->next ;
				j++;
			}
			p->next = q ; 
			q->data = q->data + 15;
			break;
		} 
		
		//余数不重复出现，除数入链，继续循环 
		int t = n/m;// t 是除数
		NODE *temp  = (NODE *)malloc( sizeof(NODE) );
		temp->data = t;
		temp->next = NULL;
		p -> next = temp;
		p = p->next ;
		//更新 余数n 
		a[n] = ++count;
		n = (n%m)*10; //n 是 余数* 10 

	}	
}


NODE* find( NODE* head, int * n )
{
	//n 表示循环节的个数 和 被除数 
	NODE *p = head->next; NODE *q = p;
	(*n) = 0;
	while(p!=NULL)
	{
		if(p->data >= 10)
		{
			break;
		}
		p = p->next ;
	}
	
	if(p==NULL)
	{
		(*n) = 0;
		return NULL; 
	}
	else
	{
		*(n) = 1;
		p->data = p->data - 15;
		q = p->next ;
		while(q!=p){
			q = q->next ;
			(*n)++;
		}
		return p;
	}
}