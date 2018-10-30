#include"stdlib.h"
#include"string.h"
#include"stdio.h"
#include"iostream"
using namespace std;

typedef struct node
{
	long long int s;
	long long int e;
	long long int ID;
}node;

node mall [200001];

int cmpfunc( const void *a , const void *b ) 
{ 
	node *c = (node *)a; 
	node *d = (node *)b; 
	if(c->s != d->s) return c->s - d->s; 
	else return c->e - d->e; 
} 

int main()
{
	memset(mall,0,sizeof(mall));
	
	long long int n;
	cin>>n;
	
	for(int i = 0;i < n;i ++)
	{
		cin>>mall[i].s>>mall[i].e;
		mall[i].ID = i+1;
	}
	
	qsort(mall,n,sizeof(node),cmpfunc);
	
	//第一遍遍历
	for(int i = 0;i < n-1;i ++)
	{
		if(mall[i].s == mall[i+1].s)
		{
			cout<<mall[i].ID<<endl;
			return 0;
		}
	} 
	
	//第二遍遍历 
	for(int i = 0;i < n - 2;i ++)
	{
		if(mall[i+1].e <= mall[i].e){
			cout<<mall[i+1].ID<<endl;
			return 0;
		}
		
		if(mall[i+2].e > mall[i+1].e && (mall[i+2].s-1) <= mall[i].e)//
		{
			cout<<mall[i+1].ID<<endl;
			return 0;
		}
		
		if(mall[i+2].e <= mall[i].e){
			cout<<mall[i+2].ID<<endl;
			return 0;
		}
		
		if(mall[i+2].e <= mall[i+1].e )
		{
			cout<<mall[i+2].ID<<endl;
			return 0;
		}
	}
	
	cout<<-1<<endl;
 	return 0;
}
