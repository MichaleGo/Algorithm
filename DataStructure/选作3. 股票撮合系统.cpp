#include<stdio.h>
#include<iostream>
#include <stdlib.h>
#include<string.h>
#define MAX 1000
typedef struct node{
int code;
float price;
int number;
char order;
int xuhao;
struct node *next;
}NODE;//node
int main(){
	NODE *buyer,*seller;//从队头指针开始，买队列从大到小，卖队列从小到大排列
	NODE *p,*q,*r,*b,*s,*b1,*s1,*r1,*q1;
	int x,code1,number1,xuhao1;
	float price1;
	char order1;
	int k=1,bi=0,si=0;
	int i,a[2];
	int flag,flag1,flag2;
	p=(NODE*)malloc(sizeof(NODE));
	p->next=NULL;
	buyer=p;
	b=buyer;
	p=(NODE*)malloc(sizeof(NODE));
	p->next=NULL;
	seller=p;
	s=seller;
	while(1){//while大循环
	scanf("%d",&x);
	if(x==0)break;
	b=buyer;
	b1=b->next;
	s=seller;
	s1=s->next;
	if(x==1){//输入1命令
	scanf("%d %f %d %c",&code1,&price1,&number1,&order1);
	printf("orderid: %04d\n",k++);
	if(order1=='b'){//输入的是buy
	    while(s1!=NULL){//在seller队列中查找符合要求的股票
		   if(price1>=s1->price){//价格合适
		      if(code1==s1->code){//编码相同，可以交易
			     if(number1==s1->number){//判断数量,数量相等
				    printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d  sellorder:%04d\n",(price1+s1->price)/2
			       ,number1,k-1,s1->xuhao);
				    number1=0;
					s->next=s1->next;
					free(s1);
					si--;
					break;
				 }
				 else if(number1>s1->number){//买大于卖
				    printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d  sellorder:%04d\n",(price1+s1->price)/2
			       ,s1->number,k-1,s1->xuhao);
	                number1=number1-s1->number;
	                s->next=s1->next;
					free(s1);
					s1=s->next;
					i--;
					si--;
	                continue;				
				 }
				 else if(number1<s1->number){//买小于卖
				    printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d  sellorder:%04d\n",(price1+s1->price)/2
			       ,number1,k-1,s1->xuhao);
					s1->number=s1->number-number1;
				    number1=0;
					break;
				 }
			  }
			  else {s=s->next;s1=s->next;continue;}
		   }
		   else  break;
		}
		if(number1!=0){//交易有剩余
		   q=buyer;q1=q->next;flag=0;
		  while(q1!=NULL){//插入股票
		     if(price1>q1->price){
			   p=(NODE*)malloc(sizeof(NODE));
			   p->code=code1;
			   p->price=price1;
			   p->number=number1;
			   p->order=order1;
			   p->xuhao=k-1;
			   p->next=q1;
			   q->next=p;
			   flag=1;
			   bi++;
			   if(flag==1)break;
			 }//if
			 else {q=q->next;q1=q->next;}
		  }
		  if(flag==0){//插入到最后位置
			p=(NODE*)malloc(sizeof(NODE));
			p->code=code1;
			p->price=price1;
			p->number=number1;
			p->order=order1;
			p->xuhao=k-1;
			p->next=NULL;
			q->next=p;
			bi++;
		  }
		}
	}//输入的是buy
	if(order1=='s'){//输入的是sell
	    while(b1!=NULL){//在buy队列中查找符合要求的股票
		   if(price1<=b1->price){//价格合适
		      if(code1==b1->code){//编码相同，可以交易
			     if(number1==b1->number){//判断数量,数量相等
				    printf("deal--price:%6.1f  quantity:%4d  sellorder:%04d  buyorder:%04d\n",(price1+b1->price)/2
			       ,number1,k-1,b1->xuhao);
				    number1=0;
					b->next=b1->next;
					free(b1);
					bi--;
					break;
				 }
				 else if(number1>b1->number){
				    printf("deal--price:%6.1f  quantity:%4d  sellorder:%04d  buyorder:%04d\n",(price1+b1->price)/2
			       ,b1->number,k-1,b1->xuhao);
	                number1=number1-b1->number;
	                b->next=b1->next;
					free(b1);
					b1=b->next;
					i--;
					bi--;
	                continue;				
				 }
				 else if(number1<b1->number){
				    printf("deal--price:%6.1f  quantity:%4d  sellorder:%04d  buyorder:%04d\n",(price1+b1->price)/2
			       ,number1,k-1,b1->xuhao);
					b1->number=b1->number-number1;
				    number1=0;
					break;
				 }
			  }
			  else {b=b->next;b1=b->next;continue;}
		   }
		   else break;
		}
		if(number1!=0){//交易有剩余
		   q=seller;q1=q->next;flag=0;
		  while(q1!=NULL){//插入股票
		     if(price1<q1->price){
			   p=(NODE*)malloc(sizeof(NODE));
			   p->code=code1;
			   p->price=price1;
			   p->number=number1;
			   p->order=order1;
			   p->xuhao=k-1;
			   p->next=q1;
			   q->next=p;
			   flag=1;
			   si++;
			   if(flag==1)break;
			 }//if
			 else {q=q->next;q1=q->next;}
		  }
		  if(flag==0){//插入到最后位置
			p=(NODE*)malloc(sizeof(NODE));
			p->code=code1;
			p->price=price1;
			p->number=number1;
			p->order=order1;
			p->xuhao=k-1;
			p->next=NULL;
			q->next=p;
			si++;
		  }
		}
	}//输入的是sell
	}//输入1命令
	else if(x==2){//输入2命令
	        scanf("%d",&code1);
	        printf("buy orders:\n");
			r=buyer;r1=r->next;
			while(r1!=NULL){
			   if(code1==r1->code)printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n",
			                           r1->xuhao,r1->code,r1->price,r1->number,r1->order);
			   r=r->next;r1=r->next;}
			printf("sell orders:\n");
			r=seller;r1=r->next;
			while(r1!=NULL)
			{if(code1==r1->code)printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n",
			                           r1->xuhao,r1->code,r1->price,r1->number,r1->order);
			 r=r->next;r1=r->next;
			}
			   
	}//输入2命令
	else if(x==3){
				  scanf("%d",&a[1]);
				  b1=buyer;
				  b=b1->next==NULL?NULL:b1->next;
				  flag1=0;
				  flag2=0;
				  while(b!=NULL){
				    if(b->xuhao==a[1]){
					 flag1=1;
					 b1->next=b->next;
					 printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n",a[1],b->code,b->price,b->number,b->order);
					 free(b);
					 b=NULL;
					 }//if
					else{
						b=b->next;
						b1=b1->next;
					}//else
	              }//while
				  s1=seller;
				  s=seller->next==NULL?NULL:seller->next;
				  while(s!=NULL&&flag1==0){
				  if(s->xuhao==a[1]){
				     flag2=1;
					 s1->next=s->next;
					 printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n",a[1],s->code,s->price,s->number,s->order);
					 free(s);
					 s=NULL;
					 }//if
					else{
						s=s->next;
					    s1=s1->next;
					}//else
				  }//while
				  if(flag1==0&&flag2==0)
					  printf("not found\n");
				  
			  
	
			  }
	}//while大循环
}//main