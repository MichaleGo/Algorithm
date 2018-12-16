#include<stdio.h>
#include<math.h>
#include<stdlib.h> 
#include <iostream>
#define MAX 10000
#define EPS 1e-6
using namespace std;
int main()
{
	int n,v,total = 0,timeLength = 0,temp,flag;
	int time[MAX],num[MAX];
	
	cin>>n>>v;
	for(int i = 0;i < n;i ++)
	{
		cin>>time[i]>>num[i];
		if(timeLength < time[i])
		{
			timeLength = time[i];
		}
	}

	for(int i = 1;i <= timeLength + 1;i ++)
	{
		temp = v;flag = 1;
		for(int j = 0;j < n && flag ;j ++)
		{

			if(time[j] == (i - 1))
			{
				if(num[j] >= temp)
				{
					num[j] -= temp;
					temp = 0;
					flag = 0;
					break;
				}else{
					temp -=num[j];
					num[j] = 0;
					
				}
			}
		}

		for(int j = 0;j < n && flag ;j ++)
		{

			if(time[j] == i)
			{
				if(num[j] >= temp)
				{
					num[j] -= temp;
					temp = 0;
					flag = 0;
					break;
				}else{
					temp -=num[j];
					num[j] = 0;
					
				}
			}
		}

		total += (v-temp);
		
	}
	
	cout << total<<endl;	
	return 0;
}
