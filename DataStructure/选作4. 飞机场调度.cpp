#include<iostream>
#include<cstdio>  
#include<queue>  
#include<algorithm>  
#include<string.h>
using namespace std;  


typedef struct Node{  
    char data;  
    struct Node *lchild;  
    struct Node *rchild;  
}Node, *BiTree;   
queue<Node*> Q;

char ins[1000], posts[1000];

Node* CreateTree(int s1,int e1,int s2,int e2)
{
	//ºóÐòÈ·¶¨¸ù£¬Ç°ÐòºóÐòÈ·¶¨×óÓÒ×ÓÊ÷
	Node* T = (Node*)malloc(sizeof(Node)) ;
	if( e1 - s1 == 0){
		T->data = ins[s1];
		T->lchild = NULL;
		T->rchild = NULL;
		return T;
	}
	if(e1 < s1 || e2 < s2){
		return NULL;
	}
	
	T->data = posts[e2];
	int r;
	for(int i = s1;i <= e1;i ++){
		if(posts[e2] == ins[i]){
			r = i;
			break;
		}
	}
	T->lchild = CreateTree(s1,r-1,s2,s2-1+r-s1);
	T->rchild = CreateTree(r+1,e1,s2+r-s1,e2-1);
	return T;
	
}

void bfs(Node *T)
{
	Q.push(T);
	while(!Q.empty()){
		Node *N = Q.front() ;
		Q.pop() ;
		if(N)
		printf("%c",N->data );
		if((N->lchild))
		Q.push(N->lchild );
		if((N->rchild))
		Q.push(N->rchild );
	}
	printf("\n");
}

int main()
{
	gets(ins);
	int len1 = strlen(ins);
	gets(posts);
	int len2 = strlen(posts);
	Node * root = CreateTree(0,len1-1,0,len2-1);
	bfs(root);
	return 0;
}
#include<stdio.h>
struct node{  
   int num;
   int time;
   struct node *next;
 };
/*--------------------È«¾Ö±äÁ¿£¬·½±ãµ÷ÓÃº¯Êý----------------------------------------------------------------*/ 
struct node *takeoff,*landon,*p,*q,*r,*s,*runway[20];
int times=0,i,num_t=1,num_l=5001,m,n,way,take,land,whole=0;
int total_time1=0,total_time2=0;
/*--------------------¼ÆÊý1,¼ÇÂ¼½µÂäµÄ×ÜÊ±¼ä--------------------------------------------------------------*/
count1(){
r=landon->next;
while(r!=NULL){
    total_time1++;
    r=r->next;
           }
}
/*---------------------¼ÆÊý2£¬¼ÇÂ¼Æð·ÉµÄ×ÜÊ±¼ä-----------------------------------------------------------*/
count2(){
	 r=takeoff->next;
        while(r!=NULL){
       		total_time2++;
            r=r->next;
           }
}
/*----------------------ÅÜµ½Õ¼ÓÃÊ±¼ä--------------------------------------------------------------------*/
count3(){
      for(i=1;i<=way;i++)            
          if(runway[i]->next!=NULL)
            runway[i]->time++;
}
/*---------------------·É»úµ¹¼ÆÊ±-----------------------------------------------------------------------*/
count4(){
     for(i=1;i<=way;i++)          
          if(runway[i]->next!=NULL)
              runway[i]->next->time--;		 
}
/*---------------------²éÑ¯¶ÓÁÐÖÐµÄ·É»ú×´Ì¬£¬ÔÚÅÜµÀÎª¿ÕµÄÊ±ºò·ÅÈë·É»ú----------------------------------*/
find(){
for(i=1;i<=way;i++){
  if(runway[i]->next==NULL){//iÅÜµÀÊÇ¿ÕµÄ
  if(landon->next!=NULL){//½µÂä¶ÓÁÐÖÐÓÐ·É»úÊ£Óà
       r=landon->next;
	   
       landon->next=r->next;//´Ó½µÂä¶ÓÁÐÖÐÉ¾³ýrÖ¸ÏòµÄ·É»ú
	   
       if(landon->next==NULL)//½µÂä¶ÓÁÐÖÐÃ»ÓÐ·É»ú
          q=landon;
		  
          r->next=NULL;
          runway[i]->next=r;//½«·É»ú·Åµ½ÅÜµÀÉÏ£¬»òÕßrÖ¸ÏòNULL¾Í¸³ÖµÎªNULL£»
		  
          printf("airplane %04d is ready to land on runway %02d\n",r->num,i);
                     }
        else if(takeoff->next!=NULL){//Æð·É¶ÓÁÐÖÐÓÐ·É»ú
		r=takeoff->next;
		
        takeoff->next=r->next;
		
        if(takeoff->next==NULL)
        s=takeoff;
		
        r->next=NULL;
		
        runway[i]->next=r;
        printf("airplane %04d is ready to takeoff on runway %02d\n",r->num,i);
                     }
                }
           }
}//find()
/*-------------------------------------Ö÷º¯Êý£¬¸ºÔð²éÑ¯ÅÜµÀÊÇ·ñÎª¿Õ--------------------------------------*/
int main()
{  int t=0;
   scanf("%d %d %d",&way,&land,&take);
   p=(struct node*)malloc(sizeof(struct node));
   p->next=NULL;
   p->time=0;
   takeoff=p;
   p=(struct node*)malloc(sizeof(struct node));
   p->next=NULL;
   p->time=0;
   landon=p;
   for(i=1;i<=way;i++){
   runway[i]=(struct node*)malloc(sizeof(struct node));
   runway[i]->next=NULL;
   runway[i]->time=0;
      }
   s=takeoff;
   q=landon;
   while(1){//Ã¿Ñ­»·Ò»´Î´ú±íÒ»·ÖÖÓ
          printf("Current Time: %4d\n",times++);
          for(i=1;i<=way;i++){//²éÑ¯¿ÕÏÐÅÜµÀ          
          if(runway[i]->next!=NULL){
               if(runway[i]->next->time==0){
       			   runway[i]->next=NULL;
                    whole--;
                    printf("runway %02d is free\n",i);
                  }
             } 
           }          
        scanf("%d %d",&m,&n);
        if(m!=-1&&n!=-1)
          whole=whole+m+n;//¼ÇÂ¼·É»ú×ÜÊý
      for(i=0;i<m;i++){//½¨Á¢½µÂä¶ÓÁÐ
         	 p=(struct node*)malloc(sizeof(struct node));
             p->num=num_l++;
             p->time=land;
			 p->next=NULL;
             q->next=p;
             q=q->next;
           }
       for(i=0;i<n;i++){//½¨Á¢Æð·É¶ÓÁÐ  
		     p=(struct node*)malloc(sizeof(struct node));
             p->num=num_t++;
             p->time=take;
			 p->next=NULL;
             s->next=p;
             s=s->next;
           }
         find();
         count1();                            
         count2();
         count3();
         count4();                
		  if(m==-1&&n==-1)break;
     }
/*---------------------------------------ÓÐÊ£ÓàµÄ·É»úÊ±£¬¼ÌÐø¶¯×÷----------------------------------------*/                                          
   while(whole>0){
         printf("Current Time: %4d\n",times++);
         for(i=1;i<=way;i++){               
          if(runway[i]->next!=NULL){
               if(runway[i]->next->time==0){
        			runway[i]->next=NULL;
                    whole--;
                    printf("runway %02d is free\n",i);
                  }
             } 
		}
        find();                            
		count1();
        count2();  
        count3();
        count4();		                                       
      }
   /*------------------Êä³öÌâÄ¿ÖÐÒªÇóµÄ¸÷ÖÖ±äÁ¿--------------------------------------------------------------*/  
   for(i=1;i<=way;i++)
     t=t+runway[i]->time;
   printf("simulation finished\n");
   printf("simulation time: %4d\n",times-1);
   printf("average waiting time of landing: %4.1f\n",(double)total_time1/(num_l-5001));
   printf("average waiting time of takeoff: %4.1f\n",(double)total_time2/(num_t-1));
   for(i=1;i<=way;i++)
     printf("runway %02d busy time: %4d\n",i,runway[i]->time);
   printf("runway average busy time percentage: %4.1f%\n",(double)t/way/(times-1)*100); 
   return(0);
 }