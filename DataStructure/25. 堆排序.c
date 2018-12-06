
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
{//大顶堆 
	int ret = heap[0];
	int x = heap[--sz];
	int temp = 0;
	
	while(2*temp + 1 < sz){
		int p;
		if(heap[2*temp+1] > heap[2*temp+2]){
			p = 2*temp +1;
		}
		else p = 2*temp +2;
		if(x >= heap[p])
   		    break;
		heap[temp] = heap[p];
		temp = p;
		
	}
	heap[temp] = x;
	
	return ret;
 } 
 
void sort(int t)//筛选，使得 No.t 是一个大顶堆。 
{
	int temp = t, p;
	int x = heap[t];
	while( 2*temp+1 < sz){//判断条件：已经筛选到leaf node ,      距离leaf 最近 非leaf node sz/2取整; 
		if(heap[2*temp + 1] > heap[2*temp +2]) p = 2*temp +1;
		else p = 2*temp +2;
		
		if(x > heap[p]) break;
		
		heap[temp] = heap[p];
		temp = p;
	} 
	heap[temp] = x; 	
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
	sz = N;
	for(i = 0;i < N;i ++){
		scanf("%d",&heap[i]);	
	}
	
	for(i = N/2;i >=0;i --){
		sort(i);
	}
	
	output();
	pop();
	output();
	pop();
	output();
}