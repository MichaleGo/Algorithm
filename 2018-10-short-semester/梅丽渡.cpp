
//https://blog.csdn.net/winter2121/article/details/72848482
//??m???
#include"stdio.h"
#include"string.h" 
long long int a[500003],n;
long long int dp[4][500003];
long long int max[4][500003];
int main()
{
	memset(dp,0,sizeof(dp));
	memset(a,0,sizeof(0));
	memset(max,0,sizeof(max));
	scanf("%lld",&n);
	for(long long int i = 1;i <= n;i ++)	
		scanf("%lld",&a[i]);

	dp[1][1] =  a[1];
	max[1][1] = a[1];
	for(long long int i = 2;i <= n;i ++)
	{
		if(dp[1][i-1] < 0)dp[1][i] = a[i];
		else dp[1][i] = dp[1][i-1] + a[i];	
		max[1][i] = max[1][i-1] > dp[1][i] ? max[1][i-1]:dp[1][i];
	}
	
	dp[2][2] = a[1] + a[2];    max[2][2] = dp[2][2];
	dp[3][3] = a[1] + a[2] + a[3];	max[3][3] = dp[3][3];	
	for(long long int i = 2;i < 4;i ++)
	{
		for(long long int j = i + 1;j<= n;j ++)
		{
			dp[i][j] = dp[ i ] [ j-1 ] + a[ j ] ;
			if(dp[i][j] < max[i-1][j] + a[j]) dp[i][j] = max[i-1][j-1] + a[j];
			
			max[i][j] = max[i][j-1] > dp[i][j] ? max[i][j-1]:dp[i][j];
		}
	}

	long long int max = -10000000000;
	for(long long int i = 3;i <= n;i ++)
	{
		max = max > dp[3][i] ? max:dp[3][i];
	}

	printf("%lld\n",max);
	return 0;
}
