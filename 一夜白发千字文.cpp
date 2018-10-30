
#include<stdio.h>
#include<string.h>

//参考链接：https://blog.csdn.net/kaiyang_shao/article/details/51317665
 
int main()
{
 	char c,c1,c2;
	int t,t1,t2,m1,m2,m3,m=0;
	long b[65536];//2^16 = 65536
	long n,i;
	
	memset(b,0,sizeof(b));
	
	while((c=getchar())!=255)//读取到文件结束符 
	{
		t=c;
		if(t<128)
		{
		}
		
		/*
		t < 128 即是题目中要求的一个字节表示的ASCII字符， 但是ASCII码有256个字符0~255. 
		两个字节表示的字符其表示方式是110×××××  10××××××,
		如果在192~223之间就表示是用两个字节表示的 
		*/
		else if(t>191&&t<224)//两个字节 
		{
			c1=getchar();
			 t1=c1;
			 n=64*t+t1-12416;//将字符的二进制编码转化成10进制编码 
			 b[n]++;//Unicode值得十进制当做数组下标，这是处理 
		}	
		else//三个字节 
		{
			c1=getchar();
			t1=c1;
			c2=getchar();
			t2=c2;
			n=4096*t+64*t1+t2-925824;
			b[n]++;	
		}
		
	}
	for(i=0;i<65536;i++)
	{
		if(b[i]>1)
		{
			m=1;
			break;
		}
	}
	
	if(m==1)
	{
		for(i=128;i<65536;i++)
		{
			if(i>=128&&i<=2047) //2^11 = 2048 , 两个字节的Unicode编码 
			{
				if(b[i]>1)
				{
					m2=i%64+128;
					m1=i/64+192;
					printf("%c%c",m1,m2);//显示UTF-8编码 
					printf(" 0x%04x",i);//格式化输出，四位显示，不够补0 
					printf(" %ld\n",b[i]);//显示重复的次数 
				}
				
			}
			else		//2^1 6= 65536 , 三个字节的Unicode编码 
			{
				if(b[i]>1)
				{
					m3=i%64+128;
					m2=(i/64)%64+128;
					m1=i/4096+224;
					printf("%c%c%c",m1,m2,m3);
					printf(" 0x%04x",i);
					printf(" %ld\n",b[i]);
				}
			}
		}
	}
    else
	{
		printf("No repeat!\n");
	}
	return 0;
}
