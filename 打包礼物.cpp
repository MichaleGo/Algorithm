#include"stdlib.h"
#include"string.h"
#include"stdio.h"
#include"iostream"
using namespace std;

typedef struct node
{
	int v;
	int index;
}node;

node gift[100001];
int p[100001][3];
int k;

int cmpfunc( const void *a , const void *b ) 
{ 
	node *c = (node *)a; 
	node *d = (node *)b; 
	return d->v - c->v; 
} 

void printIndex(int t)
{
	if(t == -1 ) return;
	printIndex(p[t][0]);
	cout<<" "<<gift[t].index + 1;
	return;
}

int main()
{
	cin>>k;
	memset(gift,0,sizeof(gift));
	for(int i = 0;i < 100001;i ++)
	{
		p[i][0] = -1;
		p[i][1] = 0;
		p[i][2] = -1;
	}
	for(int i = 0;i < k;i ++)
	{	
		cin>>gift[i].v;
		gift[i].index = i;
	}

	qsort(gift,k,sizeof(node),cmpfunc);

	int m = k - 1,flag = 0,pack = 0;
	for(int i = k - 1;i >= 0;i --)
	{
		if(m < 0)break;
		while( gift[m].v<gift[i].v*2 )
		{
			m--;
			if(m < 0)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 1) break;

		p[m][0] = i;
		pack++;
		p[m][1] = p[i][1] + 1;
		p[i][2] = 0;
		m--;
	}

	pack = k - pack;
	cout<<pack<<endl;

	int t = 0;
	for(int i = 0;i < k;i ++)
	{
		if(p[i][1] == 0 && p[i][2] == -1)
		{
			cout<<1<<" "<<gift[i].index + 1<<endl;
			continue;
		}

		if(p[i][1]!=0 && p[i][2] == -1)
		{
			cout<<p[i][1] + 1;
			printIndex(i);
//			t = i;
//			while(t!=-1)
//			{
//				cout<<" "<<gift[t].index + 1;
//				t = p[t][0];
//			}
			cout<<endl;
			continue;
		}
	}

	return 0;
}

