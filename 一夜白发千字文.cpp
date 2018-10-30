
#include<stdio.h>
#include<string.h>

//�ο����ӣ�https://blog.csdn.net/kaiyang_shao/article/details/51317665
 
int main()
{
 	char c,c1,c2;
	int t,t1,t2,m1,m2,m3,m=0;
	long b[65536];//2^16 = 65536
	long n,i;
	
	memset(b,0,sizeof(b));
	
	while((c=getchar())!=255)//��ȡ���ļ������� 
	{
		t=c;
		if(t<128)
		{
		}
		
		/*
		t < 128 ������Ŀ��Ҫ���һ���ֽڱ�ʾ��ASCII�ַ��� ����ASCII����256���ַ�0~255. 
		�����ֽڱ�ʾ���ַ����ʾ��ʽ��110����������  10������������,
		�����192~223֮��ͱ�ʾ���������ֽڱ�ʾ�� 
		*/
		else if(t>191&&t<224)//�����ֽ� 
		{
			c1=getchar();
			 t1=c1;
			 n=64*t+t1-12416;//���ַ��Ķ����Ʊ���ת����10���Ʊ��� 
			 b[n]++;//Unicodeֵ��ʮ���Ƶ��������±꣬���Ǵ��� 
		}	
		else//�����ֽ� 
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
			if(i>=128&&i<=2047) //2^11 = 2048 , �����ֽڵ�Unicode���� 
			{
				if(b[i]>1)
				{
					m2=i%64+128;
					m1=i/64+192;
					printf("%c%c",m1,m2);//��ʾUTF-8���� 
					printf(" 0x%04x",i);//��ʽ���������λ��ʾ��������0 
					printf(" %ld\n",b[i]);//��ʾ�ظ��Ĵ��� 
				}
				
			}
			else		//2^1 6= 65536 , �����ֽڵ�Unicode���� 
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
