
#include"stdio.h" 
#include"string.h"
#include"stdlib.h" 
#include"math.h"
#define MAX_N 110000 

long long int heap[MAX_N],sz = 0;

void push(long long int x)
{
	long long int i = sz++;
	while(i > 0)
	{
		long long int p = (i-1)/2;
		if(heap[p]<=x) break;
		heap[i] = heap[p];
		i = p;
	}

	heap[i] = x;
	return;
}


long long int pop()
{
	long long int ret = heap[0];
	long long int x = heap[--sz];
	long long int i = 0;
	while(i*2+1<sz)
	{
		long long int a = i*2+1,b = i*2 + 2;
		if(b < sz && heap[b] < heap[a]) a= b;
		if(heap[a] >= x)break;
		heap[i] = heap[a];
		i = a;
	}
	heap[i] = x;
	return ret;
}

int main()
{
	long long int T,n,t,a,b;
	long long int total = 0;
	scanf("%lld",&T);
	for(long long int i = 0;i < T;i ++)
	{
		total = 0;sz = 0;
		scanf("%lld",&n);
		 
		for(long long int j = 0;j < n;j ++)
		{
			scanf("%lld",&t);
			push(t);
		}
		
		if(n == 1)
		{
			printf("0\n");
			continue;
	    }
		
		while(sz>1)
		{
			a = pop();
			b = pop();
			total += (a+b);
			push(a+b);
		}
		printf("%lld\n",total);
	}
	return 0;
}
