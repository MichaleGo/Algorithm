#include"stdlib.h"
#include"string.h"
#include"stdio.h"
#include"iostream"
#include"queue"
#include"stack"

using namespace std;
priority_queue<int,vector<int>,greater<int> > qued;
priority_queue<int,vector<int>,greater<int> > quex;
int n;
int main()
{
	char c;
	cin>>n;
 	for(int i = 1;i <= n;i ++)
 	{
 		cin>>c;
 		if(c=='D')qued.push(i);
 		else quex.push(i);
	}getchar();
 	
 	int a,b;
 	while(!quex.empty() && !qued.empty())
 	{
 		a = qued.top(); b = quex.top();
 		if(a < b)
 		{
 			quex.pop();qued.pop();
 			a += n;
 			qued.push(a);
 		}
 		else
 		{
 			qued.pop();quex.pop();
 			b += n;
 			quex.push(b);
 		}
 	}

 	if(quex.empty())cout<<'D'<<endl;
 	else cout<<'X'<<endl;
 	return 0;	
} 
