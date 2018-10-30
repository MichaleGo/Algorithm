#include"stdio.h" 
#include"string.h"
#include"stdlib.h" 
#include"math.h"

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
    int T,n,c;
	int v0[100001];
	double v;
	scanf("%d",&T);//cin ²»ÒªÓÃ cin 
	while(T--)
	{
		memset(v0,0,sizeof(v0));
		scanf("%d %d",&n,&c); 
		int a,b;
		for(int i = 0;i < n;i ++)
		{
			scanf("%d %d %d",v0+i,&a,&b);
		}
		qsort(v0, n, sizeof(int), cmpfunc);

		int q; 	scanf("%d",&q);
		while(q--)
		{
			int t=0 , k=0;
			scanf("%d %d",&t,&k);
   			v = sqrt(((double)v0[k-1]*v0[k-1] + (double)2*c*t));
			printf("%.3f\n",v);
			
		}
	}

	return 0;
}
