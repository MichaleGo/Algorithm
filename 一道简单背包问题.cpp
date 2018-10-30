//https://blog.csdn.net/yoer77/article/details/70943462		±³°ü¾Å½² 
#include"stdio.h"
#include"string.h" 
int num[2003],n,v;
long long int dp[2003][2003];

int main()
{
	memset(num,0,sizeof(num));
	memset(dp,0,sizeof(dp));
	scanf("%d %d",&n,&v);
	for(int i = 1;i <= n;i ++)
	{
		scanf("%d",&num[i]);
		if(num[i] >= v) num[i] = num[i]%v;

	}

	dp[1][num[1]] = 1;
					
	for(int i = 2;i <= n;i ++)
	{
		for(int j = 0;j < v;j ++)
		{
			
			dp[i][j] = dp[i-1][j];
			dp[i][j] += dp[i-1][(j-num[i]+v)%v];
			if(num[i] == j) dp[i][j]++;
		}
	}

	printf("%lld\n",dp[n][0]%10000000);
	return 0;
}

