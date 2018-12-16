#include<stdio.h>
#define M 10010
int c[M],y[M];
int N;
int s;
long long int sum = 0;

int main()
{
	scanf("%d %d",&N,&s);
	for(int i = 0; i<N;i++)
	{
		scanf("%d %d",&c[i],&y[i]);
	}
	
	int i = 0;
	while(i<N)//i µÚÒ»¸öÎ´±»Ê¹ÓÃ 
	{
		sum+=c[i]*y[i];
		int j = i+1;
		while((c[j] - c[i]) >= (j - i)*s )
		{
			sum += c[i]*y[j] + s*(j-i)*y[j];
			j++;
		}
		i = j;
	}
	
	printf("%lld\n",sum);
	return 0;
}