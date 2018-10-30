#include"stdlib.h"
#include"string.h"
#include"stdio.h"
#include"iostream"
using namespace std;

typedef struct node
{
	int x;
	int y;
	int d;
	int f;
}node;

node que[1000001];
char map[1010][1010];
int vis[1010][1010];
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int n, m, a, b, h, t;

void path(int n)
{
	int path[100001],p = 0;
	path[p++] = n;
	while(que[n].f!=0)
	{
		n = que[n].f;
		path[p++] = n;
	}

	for(int i = 0;i < p;i++)
	{
		cout<<que[path[i]].x<<" "<<que[path[i]].y<<endl;
	}
	
	return;
}

int main()
{
	memset(map, 0, sizeof(map));
	memset(vis, 0, sizeof(vis));
	memset(que, 0, sizeof(que));
	scanf("%d %d",&n,&m);
	for (int i = 0; i <= n + 1; i++)
	{
		for (int j = 0; j <= m + 1; j++)
		{
			if (i == 0 || i == n + 1 || j == 0 || j == m + 1)map[i][j] = '#';
			else cin >> map[i][j];
		}
	}

	cin >> a >> b;	// a person 	b button 

	int x, y, count = 0;
	for (int i = 0; i < a; i++)
	{
		cin >> x >> y;
		if (map[x][y] == '#') count++;
		else map[x][y] = 'p';
	}
	if (count == a)
	{
		cout << "Cruel game" << endl;
		return 0;
	}

	//将所有button放到队列里面，地图是 . # p 的组合， button落在点里面 
	que[0].x = 0, que[0].y = 0, que[0].f = -1, que[0].d = -1;
	count = 1;
	for (int i = 1; i <= b; i++)
	{

		cin >> x >> y;
		if (map[x][y] == '#')continue;
		else if (map[x][y] == 'p')
		{
			cout << 0 << endl;
			cout << x << " " << y << endl;
			return 0;
		}
		else
		{
			que[count].x = x;
			que[count].y = y;
			que[count].f = 0;
			que[count++].d = 0;
		}
	}
	
	//一遍bfs
	h = 1, t = count;
	while (h != t)
	{
		node Node = que[h++];
//		if (map[Node.x][Node.y] == 'p')
//		{
//			cout<<Node.d<<endl;
//			return 0;
//		}

		for(int i = 0;i < 4;i ++)
		{
			int nx = Node.x + dx[i], ny = Node.y + dy[i];
			if(map[nx][ny]!='#' && !vis[nx][ny])
			{
				que[t].x = nx;
				que[t].y = ny;
				que[t].f = h-1;
				que[t++].d = Node.d + 1;
				vis[nx][ny] = 1;
				if(map[nx][ny] == 'p')
				{
					cout<<Node.d + 1<<endl;
					path(t-1);
					return 0;
				}
				
			}
		}
	}
	//system("pause");
	cout<<"Peaceful world"<<endl;
	return 0;
	
}
