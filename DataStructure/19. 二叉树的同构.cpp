#include<iostream>
#include<string.h>
using namespace std;
typedef struct Node{
	char data;
	char left;
	char right;
}Node;
int n,m;
Node T1[30],T2[30];
 
int findRoot(Node T[])
{
	int vis[30];
	memset(vis,0,sizeof(vis));
	for(int i = 0;i < n;i ++){
		if(T[i].left  != '-')vis[T[i].left - '0'] = 1;
		if(T[i].right  != '-')vis[T[i].right  - '0'] = 1;
	}
	
	for(int i = 0;i < n;i ++){
		if(!vis[i])return i;
	}
}

int isLike(int n1, int n2){
	if(n1 < 0 && n2 < 0){
		return 1;
	}
	if(n1 < 0 && n1 >= 0){
		return 0;
	}
	if(n1 >= 0 && n1 < 0){
		return 0;
	}
	if(T1[n1].data != T2[n2].data )return 0;
	
	if(T1[n1].data == T2[n2].data){
		int left1 = T1[n1].left - '0';
		int left2 = T1[n2].left - '0';
		int right1 = T2[n1].right -'0';
		int right2 = T2[n2].right -'0';
		if(isLike(left1,right1)) return 1;
		else if(isLike(left1,right2)) return 1;
		else if(isLike(left2,right1)) return 1;
		else if(isLike(left2,right2)) return 1;
		else return 0;
	}
	return 0;
}

int main()
{
	cin>>n;
	for(int i = 0;i < n;i ++)
	{
		getchar();
		cin>>T1[i].data ;
		cin>>T1[i].left ;
		cin>>T1[i].right ;
	}
	cin>>m;
	if(m!=n){
		cout<<"No."<<endl;
		return 0;
	}
	for(int i = 0;i < n;i ++)
	{
		getchar();
		cin>>T2[i].data ;
		cin>>T2[i].left ;
		cin>>T2[i].right ;
	}
	
	int root1 = findRoot(T1);
	int root2 = findRoot(T2);
	if(isLike(root1,root2)){
		cout<<"Yes."<<endl;
	}
	else cout<<"No."<<endl;
 }