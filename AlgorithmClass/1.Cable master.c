#include<stdio.h>
#include<math.h>
#include<stdlib.h> 
#define MAX 10000
#define EPS 1e-6
double a[MAX];


int divide(double mid,int N,int K)
{
	int sum = 0,i;
	for(i = 0;i < N;i++){
		sum += (int)(a[i]/mid);
	}
	return sum >= K ? 1 : 0;
}

int main()
{
	int N,K,i;
	double len,maxlen = 0;
	scanf("%d %d",&N,&K);
	 
	double right = 0,left = 0;

	for(i = 0;i < N;i ++){
		scanf("%lf",&len);
		a[i] = len;
		if(right < a[i]) right = a[i];
	}
	
	while(right > left ||fabs(right - left) < EPS){
		double mid = (left + right) / 2.0;
		int flag = divide(mid, N, K);
		if(flag){
			//temp length is availble, look for the bigger 
			maxlen = mid;
			left = mid + EPS;
		}
		else{
			//temp length is too long
			right = mid - EPS;
		}
	}
	//maxlen = right;
	//ËÄÉáÎåÈë 
	if((maxlen > 0.01) || (abs(maxlen - 0.01) < EPS)){
		double temp = ((int)(maxlen * 100))/100.0;
		if(fabs(maxlen - temp - 0.01) < EPS) 
  		    temp+=0.01;
		printf("%.2lf\n",temp);
	}
	else{
		printf("0.00\n");
	}
	
	return 0;
	
}