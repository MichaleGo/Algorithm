#include"stdlib.h"
#include"string.h"
#include"stdio.h"
char fathpy[11] = "fattyhappy";

int main()
{
    int T,len,diff,left,right,k,i;
    char s[1010];
    scanf("%d",&T);//getchar();
    while(T--)
    {
        memset(s,0,sizeof(0));
        scanf("%s",s);
        //gets(s);
        len = strlen(s);
        
        for(i = 0;i <= len - 10;i ++)
        {
            diff = 0;left = -1;right = -1;
            for(int j = 0;j < 10;j ++)
            {
                if(fathpy[j]!=s[i+j])
                {
                    diff++; 
                    if(diff == 1)left = i + j;
                    if(diff == 2)right = i + j;
                }
            }
            if(diff == 0){left = i + 2;right = i + 3;break;}
            else if(diff == 2)  
				 		 if(!(s[left] == fathpy[right-i] && s[right]==fathpy[left-i]) )continue;
						  else break;
            else if(diff == 1)
            {
                int flag = 0;
                for( k = 0;k < len;k++)
                {
                	if(k>=i && k <= i+9)continue;
                	if(s[k] == fathpy[left-i])
                    {
                         flag = 1;break;
                    }
				}
                    
                if(flag)//????
                    {if(k > left){right = k;} else{right = left;left = k;}
                    break;}
                else
                   continue;
            }
            else continue;
            
            left = -1;right = -1;
        }
        
        if(i > len -10)printf("-1\n");
        else printf("%d %d\n",left + 1 ,right + 1);
    }
    return 0;
}
