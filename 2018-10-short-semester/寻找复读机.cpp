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
	//����1��һ�����Ǹ����� 
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
	
	//��һ��һ�����Ǹ���������ͬ�Ŀ����Ǹ���������ͬ��һ�����Ǹ����� 
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
		
	//�������ܵĸ������ӿ��ܵ�����ȥ���� ������ܵ� 
	int count = 0;
	for(int i = 1;i <= n;i ++)
	{ 
		if(   judge(i,np)  )continue;//����һ��һ�����Ǹ����� 
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
