#include"stdlib.h"
#include"string.h"
#include"stdio.h"
#include"iostream"
#include"queue"
#include"stack"

using namespace std;

priority_queue<int,vector<int>,greater<int> > sml;
priority_queue<int>big;
queue<int> que;
stack<int> stk;
char name[4][100] = {"small priority queue","big priority queue","queue","stack"};

int a[10] = {1,2,3,4,5,6,7,8,9,0}; 

int main()
{
	int n,op,x,f1 = 1,f2 = 1,f3 = 1,f4 = 1;
 	while(scanf("%d",&n)!=EOF)
 	{
 		f1 = 1,f2 = 1,f3 = 1,f4 = 1;
 		while (!sml.empty()) sml.pop();
 		while(!big.empty())big.pop();
 		while (!que.empty()) que.pop();
 		while (!stk.empty()) stk.pop();
 		
 		for(int i = 0;i < n;i ++)
 		{
 			cin>>op>>x;
 			if(op == 1)
 			{
 				if(f1)sml.push(x);
 				if(f2)big.push(x);
 				if(f3)que.push(x);
 				if(f4)stk.push(x);
 			}
 			else
 			{
 				if(f1)
 					if(!sml.empty() && sml.top() == x)	sml.pop();
 					else	f1 = 0;
 				if(f2)
 					if(!big.empty() && big.top() == x)	big.pop();
 					else	f2 = 0;
 				if(f3)
 					if(!que.empty() && que.front() == x)	que.pop();
 					else	f3 = 0;
 				if(f4)
 					if(!stk.empty() && stk.top() == x)	stk.pop();
 					else	f4 = 0;
 			}
 			//cout << f1 <<f2<<f3<<f4<<endl;
 		}
 		if(!f1 && !f2 && !f3 && !f4) cout<<"pool zls"<<endl;
 		else if(f1 + f2 + f3 + f4 > 1) cout <<"not sure"<<endl;
 		else
 		{
 			if(f1)cout<<name[0]<<endl;
 			else if(f2) cout<<name[1]<<endl;
 			else if(f3) cout<<name[2]<<endl;
 			else cout<<name[3]<<endl;
 		}
 		//system("pause");
 	}
	
	
	return 0;
} 
