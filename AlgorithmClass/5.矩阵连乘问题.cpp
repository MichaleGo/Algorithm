
#include<iostream>
#include<algorithm>
#include<string.h> 
using namespace std;

int m[110][110];
int s[110][110];
int q[110];

void traceback(int i,int j)
{
	if(i == j){
		cout<<"A"<<i;
		return;
	}
	cout<<"(";
	traceback(i,s[i][j]);
	traceback(s[i][j]+1, j);
	cout<<")";
}

int main()
{
	int N;
	cin>>N;
	memset(m,0,sizeof(m)); 
	for(int i = 0; i<=N;i++)
	{
		cin>>q[i];
	}
	
	//³õÊ¼»¯m¶Ô½ÇÏß£¬¹¹Ôìm[1][N],²¢ÇÒÉèÖÃ±ê¼Çs[i][j]
	
	for(int i = 1;i <= N;i ++)
	{
		m[i][i] = 0;
	 } 
	 
    for(int r = 1;r < N; r++)
    {
    	for(int i = 1;i <= N-r; i ++)
    	{
    		int j =i +r;s[i][j] = i;
			m[i][j] = m[i][i] +m[i+1][j] + q[i-1]*q[i]*q[j];
			for(int k = i+1;k <= j-1;k++)
			{
 		        int t = m[i][k] + m[k+1][j] + q[i-1]*q[k]*q[j];
				if(t < m[i][j]) {
					m[i][j] = t;
					s[i][j] = k;
				}
			 } 
		}
	}
	cout<<m[1][N]<<endl;
	if(N == 1){
		cout<<"(A1)"<<endl;
		return 0;
	}
	traceback(1,N);
	cout<<endl;
	
}