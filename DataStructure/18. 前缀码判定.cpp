
#include <stdio.h>
#define MAXN 1000

int heap[MAXN], sz = 0;//小顶堆 

void push (int x)
{
	int temp = sz++;//队尾指针,heap[sz]为空 ，摆放好尾指针的位置，不需要管尾指针以后的赋值。 
	
	while(temp > 0){
		int p = (temp-1)/2;
		if(heap[p] <= x)break;
		heap[temp] = heap[p];//the smaller move down 
		temp = p;//the temp move up 
	} 
	heap[temp] = x;
}

int pop()
{
	int ret = heap[0];
	int x = heap[--sz];
	int temp = 0;
	
	while(2*temp + 1 < sz){
		int p;
		if(heap[2*temp+1] < heap[2*temp+2]){
			p = 2*temp +1;
		}
		else p = 2*temp +2;
		
		if(x <= heap[p])
   		    break;
		
		heap[temp] = heap[p];
		temp = p;
		
	}
	heap[temp] = x;
	
	return ret;
 } 
 
void output()
{
	for(int i = 0;i < sz;i ++){
		printf("%d ",heap[i]);
	}
	printf("\n");
}
 
int main(){
	int i, N,sum = 0;
	scanf("%d",&N);
	for(i = 0;i < N;i ++){
		int x;
		scanf("%d",&x);
		push(x);
	}

	for(i = 0;i < N-1;i ++){//出队n-2次。 
		int n,m;
		n = pop();
		m = pop();
		push(n + m);
		sum += n + m;
	}
	
	printf("WPL=%d\n",sum);
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{  
    int flag;  
    struct Node *lchild;  
    struct Node *rchild;  
}BITNode;   
char map[100000];

int main()
{
	int n,flag = 1;
	BITNode *Tree, *p;
	scanf("%d",&n);
	getchar();
	
	Tree =(BITNode*) malloc(sizeof(BITNode));
		Tree->flag = 0;
		Tree->lchild = NULL;
		Tree->rchild = NULL;
		
	for(int j = 0;j < n;j ++){//when the string not matched, the program ends before it reads all input data;
		gets(map);
		p = Tree;
		for(int i = 0;i < strlen(map);i ++){
			if(!p)break; 
			if(map[i] == '1'){// map[i] = 1, ÓÒ×ÓÊ÷ 
			
	  		    if(p->flag == 1){
	  		    	flag = 0;
	  		    	break;
				  }
				  
				if(p->rchild == NULL){//resonable,create now tree node
			  	    BITNode* t = (BITNode*) malloc(sizeof(BITNode));
			  	    t->lchild = NULL;
			  	    t->rchild = NULL;
			  	    p->rchild = t;
			  	    p = p->rchild ;
	
    				if(i == strlen(map) - 1)
					    p->flag = 1;// flag = 1 ±íÊ¾Ò¶×Ó½áµã 
    				else 
			 		    p->flag = 0;
    				
				}
				else{//p->rchild !=NULL
					
					if(i == strlen(map)-1 ){// ½áÊøÔÚÒÑ¾­´æÔÚµÄ½áµã 
						flag = 0;
						break;
					}else{
						p = p->rchild ;
					}//easy to understand but a little long and inefficient		
								
				}
			}else{//map[i] == '0'
				
				if(p->flag == 1){
					flag = 0;
					break;
				}
				if(p->lchild == NULL){
			  	    BITNode* t = (BITNode*) malloc(sizeof(BITNode));
			  	    t->lchild = NULL;
			  	    t->rchild = NULL;
			  	    p->lchild = t;
			  	    p = p->lchild ;
	
    				if(i == strlen(map) - 1)
					    p->flag = 1;// flag = 1 ±íÊ¾Ò¶×Ó½áµã 
    				else 
			 		    p->flag = 0;
	
				}
				else{
					
					if(i == strlen(map)-1){
						flag = 0;
						break;
					}else{
						p = p->lchild ;
					}					
				}
			}
		}
		if(flag == 0){
			puts(map);
			return 0;
		}
	}
	
	if(flag){
		printf("YES\n");
	}
	
	return 0; 
 }