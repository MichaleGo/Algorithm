#include"stdlib.h"
#include"string.h"
#include"stdio.h"
#include"algorithm"
#include"queue"
#include"iostream"
using namespace std;

//const int INF = 0x3f3f3f;
typedef pair<int ,int> P;

char maze[51][111][111];
int vis[51][111][111];
int n,m,k;
int sx,sy,gx,gy;
int d[111][111];

int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};//¡ý¡ú¡ü¡û 

int bfs()
{
	queue<P> que;

	que.push(P(sx,sy));
	d[sx][sy] = 0;
	vis[0][sx][sy] = 1;

	while(que.size())
	{
		P p = que.front(); que.pop();
		if(p.first == gx && p.second == gy) break;

		for(int i = 0;i < 4;i ++)
		{
			int nx = p.first + dx[i], ny = p.second +dy[i];
			if(0<=nx && nx<n && 0<=ny && ny<m &&  maze[(d[p.first][p.second]+1)%k][nx][ny] != '#' 
		      && maze[(d[p.first][p.second]+1)%k][nx][ny] != '*' && !vis[(d[p.first][p.second]+1) % k][nx][ny] 
			  && vis[(d[p.first][p.second]+1) % k][nx][ny]<k)
			{
				que.push(P(nx,ny));
				vis[(d[p.first][p.second]+1) % k][nx][ny] = 1;
				d[nx][ny] = d[p.first][p.second] + 1;
				
				if(nx == gx&&ny == gy) return d[gx][gy];	//////
			}
		}
	}
	return d[gx][gy];
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		memset(maze,0,sizeof(maze));
		memset(vis,0,sizeof(vis));
		memset(d,0x3f,sizeof(d));
		cin>>n>>m>>k;
		for(int i = 0;i < n;i ++)
		{
			for(int j = 0;j < m;j ++)
			{
				cin>>maze[0][i][j];
				if(maze[0][i][j] == 'S'){
					sx = i;sy = j;
					maze[0][i][j] = '.';
				}
				if(maze[0][i][j] == 'E'){
					gx = i;gy = j;
					maze[0][i][j] = '.';
				} 

				if(maze[0][i][j] == '*')
					for(int t = 0;t < k;t ++)
					{
						if(t == 0) maze[t][i][j] = '.';
						else maze[t][i][j] = '*' ;
					}
				else
					for(int t = 0;t < k;t ++)
						maze[t][i][j] = maze[0][i][j];
			}
		}

		int time = bfs();
		if(time >= 0x3f3f3f) cout<<-1<<endl;
		else cout<<time<<endl;
	}
	return 0;
}

