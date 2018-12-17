#include<stdio.h>
#include<string.h> 
#define min(x,y)(x>y ? y:x)
#define MAX 1510
int DP[MAX][2], f[MAX], visited[MAX];

void DFS(int r,int n)
{
	if(visited[r] == 1) return;
	visited[r] = 1;
	
	for(int i = 0;i < n;i++)
	{
		if(!visited[i] && f[i] == r)
		{
			DFS(i,n);
			DP[r][1] += min (DP[i][0],DP[i][1]);
			DP[r][0] += DP[i][1];
		}
	}
	DP[r][1]++;
 } 

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		//input->f[]
		int r = 0,fa,num,son;
		memset(DP,0,sizeof(DP));
		memset(f,0,sizeof(f));
		memset(visited,0,sizeof(visited));
		for(int i = 0;i < n;i ++){
			scanf("%d:(%d)",&fa,&num);
			if(i == 0) r = fa;
			for(int i = 0;i <num;i ++)
			{
			    scanf("%d",&son);
			    f[son] = fa;
			}
		}
		
		//DFS(root)->DP
		DFS(r,n);
		//output->DP
		printf("%d\n",min(DP[r][0],DP[r][1]));
	}
	
}