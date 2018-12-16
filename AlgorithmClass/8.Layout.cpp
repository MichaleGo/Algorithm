#include<iostream>
#include<stdio.h>
#include<string.h>
#define INF 0x3f3f3f3f
using namespace std;
int dist[1010];
struct edge{
	int u;
	int v;
	int w;
}Edge[20020];
int N,ML,MD;

void Input()
{
	for(int i = 1;i <= ML;i++){
		scanf("%d %d %d",&Edge[i].u, &Edge[i].v, &Edge[i].w);
	}
	for(int i = ML+1;i <= ML + MD;i++){
		int temp;
		scanf("%d %d %d",&Edge[i].v ,&Edge[i].u ,&temp);
		Edge[i].w = temp*(-1);
	}
}

int  BellmanFord()
{
	memset(dist,INF,sizeof(dist));
	dist[1] = 0;
	for(int i=1;i<N;i++)
	{
		for(int j=1;j<=ML+MD;j++)
		{
			if(dist[Edge[j].v]>dist[Edge[j].u] + Edge[j].w)
			{
				dist[Edge[j].v] = dist[Edge[j].u] + Edge[j].w;
			}
		}
	}
	for(int i=1;i <= ML+MD;i++)
	{
		if(dist[Edge[i].v]>dist[Edge[i].u ]+Edge[i].w)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	while(scanf("%d%d%d",&N,&ML,&MD)!=EOF){
		Input();
		if(!BellmanFord())
		{
			printf("-1\n");
		}
		else if(dist[N]==INF)
		{
			printf("-2\n");
		}
		else
		{
			printf("%d\n",dist[N]);
		}
	}
}