
#include<iostream>
#include<cmath>
#include<algorithm> 
using namespace std;
const int MAX_N= 1000000;
int N;
long long S[MAX_N], E[MAX_N] ;

void input(){
	cin>>N;
	for(int i=0; i<N; i++){
		cin>>S[i];
		cin>>E[i];
	}
	return;
}

void solve(){
	sort(S,S+N);
	sort(E,E+N);
	int s = 1, e = 0,max = 1;
	int count = 1;
	while(s<N)
	{
		if(S[s] < E[e])
		{// now start time ahead of fast nd time 
			count ++;
			s++;
			if(count> max) max = count; 
		}
		else{
			count--;e ++;
		}
		
	}
	cout << max<<endl;
	return;
}

int main(){
	input();
	solve(); 
	return 0;
}