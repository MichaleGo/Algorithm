
#include<stdio.h>
#include<string.h>
#define min(a,b)(a>b?b:a)
#define N 1000
#define inf 100000
int w[N][N],v[N],d[N]; 
int main(){
	int n,e,s,weight;char c,c1,c2;
	scanf("%d,%d,%c",&n,&e,&c);getchar();
	s = c - 'a';
	memset(v,0,sizeof(v));
	for(int i = 0;i < n;i ++)
		for(int j = 0;j < n;j ++)w[i][j] = (i == j ? 0:inf);
	for(int i = 0;i < e;i ++){
		scanf("<%c,%c,%d>",&c1,&c2,&weight);getchar();
		w[c1-'a'][c2-'a'] = weight;
	}
	for(int i = 0;i < n;i ++)d[i] = (i==s?0:w[s][i]);
	for(int i = 0;i < n;i ++){
		int x,m = inf;
		for(int y = 0;y < n;y ++)if(!v[y] && d[y]<m)m = d[x = y];
		v[x] = 1;
		for(int y = 0;y < n;y ++)if(w[x][y] < inf) d[y] = min(d[y] , d[x] + w[x][y]);
	}
	for(int i = 0;i < n;i ++){
		if(d[i] < inf)printf("%c:%d\n",i+'a',d[i]);
	}
	return 0;
}