#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    long long int a[35];
    memset(a,0,sizeof(a));
    a[0] = 1;a[1] = 0; a[2] = 3;
    for(int i = 3;i < 31;i ++)
    {
    	if(i%2 == 0) a[i] = 4*a[i-2] - a[i-4];
		else a[i] =0; 
	}
	
	while(scanf("%d",&n)!=EOF && n!=-1)
	{
		printf("%lld\n",a[n]);
	}
	
	return 0;
}