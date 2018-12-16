#include"iostream"
#include"stdio.h" 
#include"string.h"
using namespace std;

char map[5][13]=
	{
	"############",
	"############",
	"#...........",
	"############",
	"############"};

void print(int k)
{
	if(k == 49)
	{
		cout<<"no"<<endl;
		return;
	 } 
    cout<< "yes"<<endl<<"+--------------------------+"<<endl;
    
    for(int i = 0;i < 5;i ++)
	{
		cout<<'|';
		for(int j = 0;j< 12;j ++)
		{
			cout<<map[i][j]<<'.';
		}
		
		if(i == 2)cout<<'.';
		else cout<<'|';
		
		if(i == 0)cout<<'D';
		else cout<<'.';
		
		cout<<'|';
		
		if(i == 0 || i == 4) cout<<')';
		
		cout<<endl;
	 } 
    
    cout<<"+--------------------------+"<<endl;
}


int main()
{
	int k,temp;
	cin >> k;
	temp = k;

	for(int j = 11;j >= 0 && temp>=0;j --)
	{
		for(int i = 0;i < 5 && temp>=0 ;i ++)
		{
			if(i == 2 && j != 0) continue;
			if(temp)	map[i][j] = 'O';
			else 	map[i][j] = 'X';
			temp--;
		}
	}

	print(k);
	return 0;
} 
