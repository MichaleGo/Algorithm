#include<string.h>
#include<stdio.h>
#include<stack>
using namespace std; 
stack <int> s;
//Ä£ÄâÕ»µÄÈëÕ»³öÕ»¹ý³Ì£¬À´ÅÐ¶ÏÊÇ·ñÒ»¸öºÏ·¨µÄ³öÕ»ÐòÁÐ¡£
int main()
{
	int n,m;int flag2 = 1;
	while(scanf("%d %d",&n,&m) && n && m)
	{
		
		if(flag2)flag2--;
		else printf("\n");
		for(int i = 0;i < m;i ++)
		{
			int a[1000],in = 1,flag = 1;
			memset(a,0,sizeof(a));
			while(!s.empty())s.pop();
			
			for(int i = 0 ;i < n;i ++)
			{
				scanf("%d",&a[i]);
			}
			
			for(int p = 0; p < n;p ++)
			{
				if(s.empty() ||a[p] > s.top() ){
					while(in <= a[p]) s.push(in++);
					s.pop();
				}
				else if(a[p] == s.top()){
					s.pop();
				}
				else {
					flag = 0;
					break;
				}
				
			}
			
			if(flag) printf("Yes\n");
			else printf("No\n");
		}
	}
 }