#include"iostream"
using namespace std;
int main() 
{
	long long int n,s[2002],dp[2002];
	cin >> n;
	for(long long int i = 0;i <= n;i ++)
		cin>>s[i];
	dp[0] = 1;dp[1] = 1;

	long long int left,right;
	for(long long int i = 2;i <= n;i ++)
	{
		left = -1,right = -1;
		for(long long int j = i;j >= 0;j--)
			if(s[j] < s[i])		{left = j;	break;} 
		for(long long int j = i;j >= 0;j--)
			if(s[j] > s[i])		{right = j;	break;} 

		if(left>=0 && right >= 0)dp[i] = (dp[left] + dp[right]) % 2147483647;
		else  dp[i] = dp[i-1];
	}
	cout <<dp[n] % 2147483647<<endl;
	return 0;
}
