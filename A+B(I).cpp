#include"string"
#include"iostream"
#include"stdio.h" 
#include"string.h"
using namespace std;

int main()
{
	char  a[100010],b[100101],c[101001];
	int n,len_a,len_b;
	cin>>n;
	
	for(int i = 0;i < n;i ++)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		scanf("%s",a);len_a = strlen(a);  int pa = len_a - 1;
		scanf("%s",b);len_b = strlen(b);  int pb = len_b - 1;
		
		int big = len_a > len_b ? len_a : len_b; 
		int pc = big;
		int small = len_a > len_b ? len_b : len_a;
		int t = 0;
		while(small)
		{
			c[pc] = a[pa]-'0' + b[pb] + t;
			if(c[pc] == '2')
			{
				t = 1;
				c[pc] = '0';
			}
			else if(c[pc] == '3')
			{
				t = 1;
				c[pc] = '1';
			} 		
			else t = 0;
			pa--;pb--;pc--;small--;
		}
		
		if(pa >= pb)
		{
			while(pa>=0)
			{
				c[pc] = a[pa] + t;
				if(c[pc] == ('2'))
				{
					t = 1;
					c[pc] = '0';
				}else if(c[pc] == '3')
				{
					t = 1;
					c[pc] = '1';
				} 		
				else t = 0;		
				pa--;pc--;
			}
			
		}else{
			
			while(pb>=0)
			{
				c[pc] = b[pb] + t;
				if(c[pc] == '2')
				{
					t = 1;
					c[pc] = '0';
				}else if(c[pc] == '3')
				{
					t = 1;
					c[pc] = '1';
				} 		
				else t = 0;		
				pb--;pc--;
			}
		}
		c[pc] = t + '0';

		int len_c;
		if(c[0] == '0')  len_c = big;
		else  len_c = big + 1;
		
		int temp = len_c-len_a;
		for(int i = 0;i < temp;i ++)
		{
			cout<<" ";
		}
		cout<<"  "<<a<<endl;
		cout<<"+ ";
		temp = len_c-len_b;
		for(int i = 0;i < temp;i ++)
		{
			cout<<" ";
		}
		cout<<b<<endl;
		for(int i = 0;i < len_c + 2;i ++)
		{
			cout<<"-";
		}
		cout<<endl;
		cout<<"  ";
		
		pc = 1;if(c[0] == '1')cout<<'1';
		while(c[pc])
		{
			cout<<c[pc++];
		}cout<<endl;
		
	}
}
