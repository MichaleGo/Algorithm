#include"stdlib.h"
#include"string.h"
#include"stdio.h"

int main()
{
    int n;
    char s[200001];
    char evenc[128];
    char oddc[128];
    int num[128];
    int even = 0,odd = 0;
    memset(s,0,sizeof(s));
    memset(num,0,sizeof(num));
    memset(evenc,0,sizeof(evenc));
    memset(oddc,0,sizeof(oddc));
    scanf("%d",&n);
    scanf("%s",s);
    for(int i = 0;i < n;i ++)
        num[s[i]]++;
    for(int i = 0;i < 128;i ++)
    {
        if(num[i]%2 == 1)oddc[odd++] = i;
        if(num[i] > 0  && num[i]%2 == 0) evenc[even++] = i;
    }
    if(odd==0){
    	printf("0\n");
	}
    else printf("%d\n",odd-1);
    
    for(int i = 0;i < even;i ++)
    {
    	for(int j = 0;j  < num[evenc[i]]/2;j++)
    	printf("%c",evenc[i]);
	}
	for(int i = 0;i < num[oddc[0]] && odd > 0;i ++)
    		printf("%c",oddc[0]);
    for(int i = even - 1;i >= 0;i --)
    {
    	for(int j = 0;j  < num[evenc[i]]/2;j++)
    			printf("%c",evenc[i]);
	}
    printf("\n");
    
    for(int i = 1;i < odd ;i ++)
    {
    	for(int j = 0;odd > 0 && j < num[oddc[i]];j ++)
    		printf("%c",oddc[i]);
   		printf("\n");
	}
    return 0;
}
