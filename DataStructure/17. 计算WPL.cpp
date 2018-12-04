
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