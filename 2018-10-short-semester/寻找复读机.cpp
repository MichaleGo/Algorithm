#include"string.h"
#include"stdio.h" 
#include"stdlib.h"

int usr[2200];
char msg[2100][210];
int nofuduji[2100];

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int judge(int t,int np)
{
	//返回1，一定不是复读机 
	for(int i = 0;i < np+1;i ++)
	{
		if(nofuduji[i] == t) return 1;
	}	
	return 0;
}

int main()
{
	memset(usr,0,sizeof(usr));
	memset(msg,0,sizeof(msg));
	//memset(fuduji,0,sizeof(fuduji));
	memset(nofuduji,0,sizeof(nofuduji));
	int n,m;
	scanf("%d %d",&n,&m);
	int np = 0;
	
	//第一个一定不是复读机，相同的可能是复读机，不同的一定不是复读机 
	for(int i = 0;i < m;i ++)
	{
		scanf("%d",&usr[i]);
		scanf("%s",msg[i]) ;
		if(i == 0)
		{
			nofuduji[np++] = usr[0];
			continue;
		}
		if(strcmp(msg[i], msg[i-1])!=0) nofuduji[np++] = usr[i];
	}
		
	//将不可能的复读机从可能的里面去掉， 输出可能的 
	int count = 0;
	for(int i = 1;i <= n;i ++)
	{ 
		if(   judge(i,np)  )continue;//返回一，一定不是复读机 
		else {
			if(count)printf(" %d",i);
			else{
				printf("%d",i);
				count++;
			}
		}
	}
	if(count == 0)
		  return 0;
    printf("\n");
	return 0;
}
