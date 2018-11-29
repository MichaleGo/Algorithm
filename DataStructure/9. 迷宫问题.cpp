
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
	
	
}