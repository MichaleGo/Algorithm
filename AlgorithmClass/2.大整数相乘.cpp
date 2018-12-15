#include<iostream>
#include<string>
using namespace std;
#define MAX 20050
int X[MAX];
int Y[MAX];
int ans[2*MAX];//ans[0]用来存储答案的位数
int main()
{
	int i = 1; int j = 1;
	string str1,s,str2;
	cin >> str1; cin >> str2;
	int lenX = str1.length();
	int lenY = str2.length();
	
	//string to int array
	for (i = 1; i <= lenX; i++)
		X[i] = str1[lenX - i]-'0';
	for (j = 1; j <= lenY; j++)
		Y[j] = str2[lenY - j]-'0';
	
	//calculate
	for (int i = 1; i <= lenX; i++)
	{
		for ( j = 1; j <= lenY; j++)
			ans[i + j-1] += X[i] * Y[j];
	}
	
	for (int i = 1; i <= lenX+lenY; i++)
	{
		ans[i + 1] += ans[i] / 10; ans[i] %= 10;
	}
	
	//Output
	for (int k = lenX + lenY ; k >= 1; k--){
		if(!ans[k] && k == lenX + lenY )
				   continue;
         printf("%d", ans[k]);
	}
	printf("\n");
	return 0;
}