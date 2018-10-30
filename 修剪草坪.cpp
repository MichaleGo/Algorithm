#include"iostream"
#include"stdio.h" 
#include"string.h"
#define N 100
using namespace std;

int main() 
{
    int m,n,num[N][N];
    //每次找到输入数组num的行列最大，直接判断数组里的每一个数是否是该行最大和该列最大的最小值。
	//（可以证明每个数不是是该行最大就是该列最大，且为这两个最大的较小那个值) 
    while(scanf("%d%d",&n,&m)!=EOF){ 
        int i , j;
        int maxC[N],maxR[N],num2[N][N];
	    memset(maxC,0,sizeof(maxC));
	    memset(maxR,0,sizeof(maxR));
	    
	    int flag = 1;
	    
	    for (i = 0; i < n; i ++) {
	        for (j = 0; j < m; j++) {
	            cin>>num[i][j];
	            if (num[i][j] > 100) {
	                flag = 0;
	            }
	            num2[i][j] = 100;
	            maxC[j] = maxC[j] > num[i][j]?maxC[j]:num[i][j];
	            maxR[i] = maxR[i] > num[i][j]?maxR[i]:num[i][j];
	        }
	    }
	    
	    for (i = 0; i < n; i++) {
	        for (j = 0;j < m; j++) {
	        	//列（行）锄草，高于列（行）最大的变为列（行）最大，低于的不变
	            num2[i][j] = num2[i][j] > maxC[j]?maxC[j]:num2[i][j];
	            num2[i][j] = num2[i][j] > maxR[i]?maxR[i]:num2[i][j];
	        }
	    }
	    //判断锄草后的草是否和要求的草相等，这个地方有一个充要条件，每行每列的最大值，唯一确定一个修建后的草坪
		
	    for (i = 0; i < n; i++) {
	        for (j = 0;j < m; j++) {
	            if(num[i][j] != num2[i][j]){
	                flag = 0;
	            }
	        }
	    }
	    
	    if (flag == 1) {
	        printf("YES\n");
	    }else{
	        printf("NO\n");
	    }
	    
	    int k = 0;
	    for(i = 0;i < n;i ++)
	    {
	    	if(maxR[i] < 100) 
	    	{
	    		k++;
			}
		}
		
		int max = 0;
		for( i = 0;i < n;i ++)
		{
			max = max > maxR[i] ? max : maxR[i];
		}
		
		for(j = 0;j < m;j ++)
		{
			if(maxC[j] < max) 
			{
				k++;
			}
		}
	    
	    
	    printf("%d\n",k);
	    
	    
	    
	    
	    for(i = 0;i < n;i ++)
	    {
	    	if(maxR[i] < 100) 
	    	{
	    		for(j = 0;j < m;j ++)
	    		{
	    			num[i][j] = maxR[i];
				}
				
				printf("%d %d %c\n",i+1,maxR[i],'R');
			}
		}
		
		for(j = 0;j < m;j ++)
		{
			if(maxC[j] < max) 
			{
				for(i = 0;i < n;i ++)
	    		{
	    			num[i][j] = maxC[j];
				}
				printf("%d %d %c\n",j+1,maxC[j],'C');
			}
		}
		
    }
    return 0;
}

