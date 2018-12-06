
#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m,w[3000],u[3000],v[3000],r[3000],p[1000],ans = 0;
int cmp(int i,int j){
	return w[i] < w[j];
}
int find(int x){
	return p[x] == x ? x:p[x] = find(p[x]);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i = 0;i < m;i ++){
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
		u[i]--;v[i]--;
		r[i] = i;
	}
	sort(r,r+m,cmp);
	for(int i = 0;i < n;i ++)p[i] = i;
	for(int i = 0;i < m;i ++){
		int e = r[i]; int x = find(u[e]);int y = find(v[e]);
		if(x!=y){
			ans+=w[e]; 	p[x] = y;
		} 
	}
	int t = find(0);
	for(int i = 0;i < n;i ++)if(t != find(i)){ans = -1;break;}
	printf("%d\n",ans);
	return 0;
 }