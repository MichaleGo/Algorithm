#include"stdlib.h"
#include"string.h"
#include"stdio.h"
#include"algorithm"
#include"queue"
#include"iostream"
using namespace std;
typedef struct node
{
	int x;
	int y;
}node;
char map[1010][1010];
int dis[1010][1010];
int vis[1010][1010];
int n,m,k;
int sx,sy,gx,gy;
int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};

int bfs()
{
	queue<node> que;
	node t,a;t.x = sx;t.y = sy;
	que.push(t);
	vis[sx][sy] ++;
	dis[sx][sy] = 0;

	while(que.size())
	{
		t = que.front();que.pop();
		if(t.x == gx && t.y == gy) return dis[gx][gy];

		for(int i = 0;i < 4;i ++)
		{
			int nx = t.x + dx[i], ny = t.y + dy[i];
			if(map[nx][ny] != '#' )// && (!vis[nx][ny] || dis[nx][ny] == dis[t.x][t.y] + 1)
			{
				for(int j = 0;j < k;j ++)
				{
					if(i == 0)
					{	
						if(nx+j>n || map[nx+j][ny] == '#')break;
						if(!vis[nx+j][ny] || (vis[nx+j][ny] == 1 && dis[nx+j][ny] == (dis[t.x][t.y] + 1) ))
						{
							a.x = nx+j;a.y = ny;
							que.push(a);
							vis[a.x][a.y] ++;
							dis[a.x][a.y] = dis[t.x][t.y] + 1;
						}
						else continue;

					}
					else if(i == 1)
					{
						if(ny+j>m || map[nx][ny+j] == '#')break;
						if(!vis[nx][ny+j] || (vis[nx][ny+j] == 1 && dis[nx][ny+j] == (dis[t.x][t.y] + 1) ))
						{
							a.x = nx;a.y = ny+j;
							que.push(a);
							vis[a.x][a.y] ++;
							dis[a.x][a.y] = dis[t.x][t.y] + 1;
						}
						else continue;
					}
					else if(i == 2)
					{
						if(nx-j < 1 || map[nx-j][ny] == '#')break;
						if(!vis[nx-j][ny] || (vis[nx-j][ny] == 1 && dis[nx-j][ny] == (dis[t.x][t.y] + 1) ))
						{
							a.x = nx - j;a.y = ny;
							que.push(a);
							vis[a.x][a.y] ++;
							dis[a.x][a.y] = dis[t.x][t.y] + 1;
						}
						else continue;
					}
					else
					{
						if(ny-j < 1 || map[nx][ny-j] == '#')break;
						if(!vis[nx][ny-j] || (vis[nx][ny-j] == 1 && dis[nx][ny-j] == (dis[t.x][t.y] + 1) ))
						{
							a.x = nx;a.y = ny - j;
							que.push(a);
							vis[a.x][a.y] ++;
							dis[a.x][a.y] = dis[t.x][t.y] + 1;
						}
						else continue;
					}

					if(a.x == gx&&a.y == gy) return dis[gx][gy];		
				}
			}
		}
	}
	return dis[gx][gy];	
}
int main()
{
	cin>>n>>m>>k;
 	memset(map,0,sizeof(map));
 	memset(vis,0,sizeof(vis));
 	memset(dis,0x3f,sizeof(dis));
 	for(int i = 0;i <= n+1;i ++)
 	{
 		for(int j = 0;j <= m+1;j ++)
 		{
 			if(i == 0 || i == n+1 || j == 0 || j == m+1)map[i][j] = '#';
 			else cin>>map[i][j];
		}
	}
	cin>>sx>>sy>>gx>>gy;

	int tempNum = bfs();
	if(tempNum >= 0x3f3f3f) cout<<-1<<endl; 
	else cout<<tempNum<<endl;
	
	return 0;
}

