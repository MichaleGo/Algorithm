//http://online.bit.edu.cn/moodle/mod/forum/discuss.php?d=61180
#include"stdio.h"
#include"string.h" 
long long int dp[2003];
long long int dpw[2003];
long long int sumdp[2003];
long long int sumdpw[2003];

int main()
{
	int T,n,m,k;
	scanf("%d",&T);
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		memset(dpw,0,sizeof(dpw));
		memset(sumdp,0,sizeof(sumdp));
		memset(sumdpw,0,sizeof(sumdpw));
		scanf("%d %d %d",&n,&m,&k);
		for(int i = 1;i < k;i ++)
		{
			dp[i] = 0; dpw[i] = 1;
			sumdp[i] = 0;sumdpw[i] = i;
		}

		for(int i = k;i <= n;i ++)
		{
			dp[i] = (sumdp[i-k]*(m-1) + sumdpw[i-k] + 1) % 998244353;
			dpw[i] = (sumdp[i-1]*m + 1) % 998244353;
			sumdp[i] = (sumdp[i-1] + dp[i]) % 998244353;
			sumdpw[i] = (sumdpw[i-1] + dpw[i]) % 998244353;
		}
		printf("%lld\n",( dp[n]*m + dpw[n] ) % 998244353);
	}
	return 0;
}
