#include<stdio.h>   
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
	struct node* prior;
}Node;

int a[2];

Node *link_create(int n)
{//½¨Á¢Á´±í´ø×ÅÍ·½áµã£¬»òÕß³õÊ¼»¯Íê³ÉµÚÒ»¸ö£¬so taht ´úÂëÆÕÊÊÐÔ¡£ 
	Node *q, *head;
	int i;
	head = (Node*)malloc(sizeof(Node));
	head->data = -1;
	head->next = NULL;
	head->prior = NULL;
	Node *p = head ;
	
	for(i = 1;i<=n;i++){
		//ÕýÏò´´½¨Á´±í £¬Î²Ö¸ÕëÒ»Ö±Áô×Å£¬½¨Á¢Íê³Éºó¸³Öµ 
		q = (Node*)malloc(sizeof(Node));
		q->prior = p;
		q->next = NULL;
		q->data = i;
		
		p->next = q;
		p = p->next ;
	}
	q->next = head->next ;
	head->next->prior = q;//½¨Á¢Íê³É 
	
	return head;
}

void deleteNode(Node**p) //Ö¸ÕëµÄÖ¸Õë£¬*pÊÇÒ»¸öÖ¸Õë 
{
	    (*p)->prior->next=(*p)->next;  
        (*p)->next->prior=(*p)->prior;  
}

void output( Node * head )
{
    while ( head->next != NULL )
    {   head = head->next;
        printf("%d ", head->data );
    }
    printf("\n");
}

int main()
{
	int n,k,m;
	scanf("%d,%d,%d",&n,&k,&m);
	if(n == 0 || k == 0 || m == 0){
		printf("n,m,k must bigger than 0.\n");
		return 0;
	}
	
	if(k >n){
		printf("k should not bigger than n.\n");
		return 0;
	}
	Node* head = link_create(n);
	Node* p = head->next;
	for(int i = 1;i < k;i++){
		p = p->next;
	}
	Node *q = p;
	
	while(n>0){
		
		for(int i = 1;i < m;i++) {
		p = p->next;
		q = q->prior ;
	    }   
	
    	if(p == q){
    		printf("%d,",p->data );
    		n--;
    		a[0] = p->data ;
    		a[1] = q->data ;
    		(p)->prior->next=(p)->next;  
            (p)->next->prior=(p)->prior;
            
    		p = p->next ;
    		q = q->prior ;
    		
		
	    }else{
	    	printf("%d-%d,",p->data,q->data  );
	    	n--;n--;
	    	a[0] = p->data ;
	    	a[1] = q->data ;
	    	
	    	(p)->prior->next=(p)->next;  
            (p)->next->prior=(p)->prior;
            
            (q)->prior->next=(q)->next;  
            (q)->next->prior=(q)->prior;
	    	
	    	
	    	if(p->next == q){
	    		p = p->next ->next;
	    		q = q->prior ;
			}else {
				p = p->next ;
				q = q->prior ;
			}
  			
		}
	
	} 
	//if(!(a[0] == p->data || a[1] == p->data) )
    //	printf("%d,\n",p->data );
    printf("\n");
	return 0;
	
 }