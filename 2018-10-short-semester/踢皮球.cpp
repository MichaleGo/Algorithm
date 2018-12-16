#include"stdlib.h"
#include"string.h"
#include"stdio.h"
#include"iostream"
using namespace std;

int n,guo[1000],mark[1000];

int dfs(int s)
{
	if(mark[s])return s;
	mark[s] = 1;
	return dfs(guo[s]);
}

int main()
{
	memset(guo,0,sizeof(guo));
	cin>>n;
	for(int i = 1;i <= n;i ++)
	{
		cin>>guo[i];
	}
	
	for(int i = 1;i <= n;i ++)
	{
		memset(mark,0,sizeof(mark));
		if(i != n)cout << dfs(i)<<" ";
		else cout<<dfs(n)<<endl;
	}
	return 0;
} 
