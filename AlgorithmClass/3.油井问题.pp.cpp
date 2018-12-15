#include<iostream> 
#include<queue>
#include<algorithm> 
using namespace std;

priority_queue <int> q;
int temp[2000000];

int main()
{
	int a,b;
	int i = 1;//Èç¹û·ÅÔÚÀïÃæ»áÔõÃ´Ñù£¿ 
	while((scanf("%d,%d",&a,&b)) != EOF){
		temp[i++] = b;
	}
	
	int sum = i-1;
	
	for(int i =1;i <= (sum+1)/2;i ++){
		q.push(temp[i]);
	} 
	
	for(i = (sum+1)/2 + 1;i <= sum;i++ )
	{
		if(temp[i] >=q.top()){
			continue;
		}
		
		if(temp[i] < q.top()){
			q.pop();
			q.push(temp[i]);
		}
	}
	
	printf("%d\n",q.top());
	
	return 0; 
}