
#include <stdio.h>
#include<string.h> 
#define MAXN 1000
int main()
{
	int a[MAXN],N,t;memset(a,0,sizeof(a));
	scanf("%d",&N);
	for(int i = 0;i < N;i ++){
		scanf("%d",&t);
		a[t]++;
	}
	for(int i = 0;i < MAXN;i ++){
		if(a[i]){
			printf("%d:%d\n",i,a[i]);
		}
	}
 }