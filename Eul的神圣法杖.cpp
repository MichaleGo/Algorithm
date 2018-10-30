#include"stdlib.h"
#include"string.h"
#include"stdio.h"
#include"iostream"
using namespace std;
typedef struct node
{
	long long int time;
	long long int blood;
}node;
node person[5001];
node a[5001];

int cmpfunc( const void *a , const void *b ) 
{ 
	node *c = (node *)a; 
	node *d = (node *)b; 
	if(c->time != d->time) return c->time - d->time; 
	else return c->blood - d->blood; 
} 

int main()
{
	long long int total = 0,k;int p = 0;
	int n,q;
	memset(person,0,sizeof(person));
	memset(a,0,sizeof(a));
	cin>>n>>q;
	for(int i = 0;i < n;i ++)
	{
		cin>>a[i].time>>a[i].blood;
		total += a[i].blood;
	}
	
	qsort(a,n,sizeof(node),cmpfunc);
		
	for(int i = 0;i < n;i ++)
	{
		if(a[i].time!=a[i+1].time)
		{
			person[p].time=a[i].time;
			person[p++].blood = a[i].blood;
			continue;
		}
		else
		{
			person[p].time=a[i].time;
			person[p].blood = a[i].blood;
			while(a[i].time==a[i+1].time&& i < n)
			{
				person[p].blood += a[i+1].blood;
				i++;
			}
			p++;
		}
	}

	n = p;
	for(int i = 0;i < q;i ++)
	{
		cin>>k;
		if(k >= (person[n-1].time - person[0].time + 1))
		{
			cout<<0<<endl;
			continue;
		}

		int j = 0;
		long long int maxx = 0,ans = 0;
		while(!(person[j+1].time-person[0].time>k-1) && j<n)
		{
			ans += person[j].blood;
			j ++;
			
			if(j >= n)
			{
				cout<<0<<endl;
			    return 0;
			}
		} ans += person[j].blood;
		maxx = ans;
		
		int flag = 0;
		for(int i  = 1;i < n;i ++)
		{
			ans -= person[i-1].blood;
			while(!(person[j+1].time-person[i].time>k-1))
			{
				j ++;
				if(j >= n)
				{
					flag = 1;break;
				} 
				ans += person[j].blood;
			}
			if (ans > maxx)
			{
				maxx = ans;
			}
			if(flag)break;
		}
		cout<<total-maxx<<endl;
	}
	return 0;
} 
/*
2 1
1111 1111
1 1
1
*/

