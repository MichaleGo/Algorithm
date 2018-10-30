#include"stdlib.h"
#include"string.h"
#include"stdio.h"

int cmpfunc (const void * a, const void * b)
{
   return ( *(long long int*)a - *(long long int*)b );
}

int main(){
	long long int n,i,x[100001],y[110001];
	scanf("%lld",&n); 
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	
	for(i=0;i<n;i++)
	{
		scanf("%lld",x+i);
		scanf("%lld",y+i);
	}
	
	qsort(x,n,sizeof(long long int),cmpfunc);
	qsort(y,n,sizeof(long long int),cmpfunc);
	//sort(x,x+n);sort(y,y+n);
	
	for(i=0;i<n;i++)		//列成一个水平队列，即排列(x,y),(x+1,y),…,(x+n-1,y)
	    x[i]-=i;
	
	qsort(x,n,sizeof(long long int),cmpfunc);
	//sort(x,x+n);
		
	long long int sumx = 0,sumy = 0;
	for(i=0;i<n;i++){	
	    sumx+=abs(x[i]-x[n/2]);
		sumy+=abs(y[i]-y[n/2]);
		}
			
	printf("%lld\n",sumx+sumy);
}

