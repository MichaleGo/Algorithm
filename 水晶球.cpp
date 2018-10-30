#include"stdlib.h"
#include"string.h"
#include"stdio.h"
#include"iostream"
using namespace std;

typedef struct node
{
	long long int a;
	long long int b;
	long long int c;
	long long int ID;//a>b>c
}node;

node stone[100001];

int cmpfunc( const void *a , const void *b ) 
{ 
	node *c = (node *)a; 
	node *d = (node *)b; 
	if(c->b != d->b) return d->b - c->b; 
	else if(c->a != d->a) return d->a - c->a;
	else return d->c - c->c;
} 

void swap(long long int &A,long long int &B)
{
	long long int t;t = A;A = B;B = t;
	return;
}

int main()
{
	memset(stone,0,sizeof(stone));
	long long int n,A,B,C,max1 = 0,max2 = 0,tempID = 0;
	cin>>n;
	for(int i = 0;i < n;i ++)
	{
		cin>>A>>B>>C;
		if(A<B)swap(A,B);if(A<C)swap(A,C); stone[i].a = A;
		if(B<C)swap(B,C);stone[i].b = B;stone[i].c = C;stone[i].ID = i + 1;
		if(C>max1)
		{
			max1 = C;
			tempID = i + 1;
		}
	}

	qsort(stone,n,sizeof(node),cmpfunc);
	
	long long int p1 = 0, p2 = 0,t = 0;
	for(int i = 0;i < n-1;i ++)
	{
		if(stone[i].a == stone[i+1].a && stone[i].b == stone[i+1].b && stone[i+1].b > max1)
		{
			if(stone[i].b < (stone[i].c + stone[i+1].c)) max2 = stone[i].b;
			else max2 = (stone[i].c + stone[i+1].c);
			if(t <= max2)
			{
				 t = max2;
				 p1 = stone[i].ID;
				 p2 = stone[i + 1].ID;
		    }		
		}
		
	}
	
	
	 	 	if(t > max1)
			{
				cout <<2<<endl;
				cout<<p1<<" "<<p2<<endl;
			}	
			else 
			{
			cout<<1<<endl;
			cout<<tempID<<endl;
			}
			return 0;
			
}
