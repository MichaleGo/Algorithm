#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct GLNode{
	int tag;
	union{
		struct{
			char atom;
			int depth;
		}Atom;
		struct{
			struct GLNode *hp, *tp;
		}ptr;
	};
} * GList;
int a[1000],degree[1000];
int GListDepth(GList L)
{
	//²ÉÓÃÍ·Î²Á´±í´æ´¢½á¹¹£¬Çó¹ãÒå±íLµÄÉî¶È¡£ÖÕ½á×´Ì¬£¬empty list and atom 
	if(!L) return 1;
	if(L->tag == 0) return 0;
	int max = 0,dep;GList pp;
	
	for(pp = L;pp; pp = pp ->ptr.tp ) {
		dep = GListDepth(pp->ptr.hp);
		if(max < dep)max = dep;
	}
	
	return max + 1;
}


void SubString(char *s , char *sub , int start , int len)
{//µÚ start ¸ö×Ö·û£¨²»ÊÇÏÂ±ê£© ¿ªÊ¼£¬¸´ÖÆlen ¸ö×Ö·ûµ½ sub£¬sÖ¸µ½ µÚ start ¸ö×Ö·û
   int i ;
   for(i = 1 ; i < start ; s++ , i++) ;
   for(i = 0 ; i < len ; i++)//£¿£¿£¿sÖ¸ÕëÒ²ÒÆ¶¯ÁË£¬ Ã÷ÏÔ²»¶Ô £¬µ«Êµ¼ÊÉÏ²¢Ã»ÓÐÒ»ÒÆ¶¯¡£ 
   {
       sub[i] = s[i] ;
   }
   sub[len] = '\0' ;
}

/*
 *½«×Ö·û´®·ÖÎª±íÍ·ºÍ±íÎ²×Ö·û´®
 */
void sever(char *hsub , char *sub)
{//½«´«µÝ¹ýÀ´µÄsub£¬·Ö³Éhsub£¬sub  
   int i , k ;
   for(i = 0 , k = 0 ; i < strlen(sub) ; i++)
   {
       if(sub[i] == '(')
       {
           k++;
       }
       if(sub[i] == ')')
       {
           k--;
       }
       if(sub[i] == ',' && k == 0)
       {
           break ;
       }
   }
   if(i < strlen(sub))
   {//¼ÈÓÐ±íÎ²£¬Ò²ÓÐ±íÍ· ¡£ 
   SubString(sub, hsub, 1, i);
   SubString(sub, sub, i+2, strlen(sub)-i-1);
   }
   else
   {//Ö»ÓÐ±íÎ² ¡£ 
       SubString(sub , hsub , 1 ,strlen(sub)) ;
       sub[0] = '\0' ;
   }
}




GList CreateGList(GList &L, char* s)//Èç¹û²»ÓÃÒýÓÃ£¬Ó¦¸ÃÔõÃ´°ì 
{
	if(strcmp(s, "()") == 0) L = NULL;
	else{
		L= (GList)malloc(sizeof(GLNode));
		if(strlen(s) == 1) {
			L->tag = 0;
			L->Atom.atom =*s;
		}
		else{
			L->tag = 1;GList p = L;
			char *hsub = (char*)malloc(sizeof(char)*(strlen(s) + 1));
			char *sub = (char*)malloc(sizeof(char)*(strlen(s) + 1));
			
			SubString(s, sub, 2, strlen(s)-2);//s:get rid of (),transform to sub
			while(strlen(sub) != 0){
				sever(hsub,sub);//sub divided into hsub and sub
				CreateGList(p->ptr .hp, hsub);//for hsub :recurse createlist
				
				if(strlen(sub) != 0){
					GList q = (GList)malloc(sizeof(GLNode));//for sub :continue to divide until sub=0
				    q->tag = 1;
	        	    p->ptr .tp = q;
	                p = q;
				}
				else{
					p->ptr .tp =NULL;
				}
			}
		}
	}
}


void Traverse(GList &ls){
	static int depth = -1;
	static int i = 0;
	if(ls != NULL)
    {
        if(ls->tag == 0)
        {	ls->Atom .depth = depth;
            a[i++] = depth;
        	return;
        }
        else
        {	
        	depth++;
            Traverse(ls->ptr.hp) ;
            
            depth--;
            Traverse(ls->ptr.tp) ;
        }
    }
}
void printGList(GList ls)
{
    if(ls != NULL)
    {
        if(ls->tag == 0)
        {	
        	for(int i = 0;i < ls->Atom .depth;i ++){
        		printf("    ");
			}
        	
            printf("%c\n" , ls->Atom.atom) ;
        }
        else
        {
            printGList(ls->ptr.hp) ;
            printGList(ls->ptr.tp) ;
        }
    }
}

int main()
{
	
  GList ls1;
  int i,k,j,nd;
  for(i = 0;i < 1000;i ++){
  	a[i] = 1000;
  }
  char s1[MAXSIZE] ;
  char *s;
  scanf("%s" , s1) ;
  s=s1;
  if(!strcmp(s1,"()")){
  	printf("Degree of tree: 0\nNumber of nodes of degree 0: 0\n");
  	return 0;
  }
  CreateGList(ls1 , s) ;
  Traverse(ls1);//ÓÃÖ¸Õë¿ÉÒÔ£¬ÓÃÊý×éÃû¿ÉÒÔÂð £¿ 
  printGList(ls1) ;
  
  i = 0;
  while(a[i] != 1000)
  i++;
  
  for(j =0;j < i;j++){
	 nd =0;
  	if(a[j]>=a[j+1]){
  		degree[0]++;
  		continue;
	  }
	  
    for(k = j+1;k < i;k ++){
    	if(a[k] == a[j]){
    		break;
		}
		else{
			if(a[k] == a[j]+1){
				nd++;
			}
		}
	}
 	degree[nd]++;
    
  }
  
  int max = 999;
  while(degree[max] == 0)max--;
  
  printf("Degree of tree: %d\n",max);
  for(int nd = 0;nd <= max;nd++ ){
  		  printf("Number of nodes of degree %d: %d\n",nd,degree[nd]);
  }
  
  return 0;
}