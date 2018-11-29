
#include<stdio.h>
#include<stdlib.h>
struct t {
	char dat[200];
	int top;
}prt;//·ûºÅÕ»
void pusht(char a)
{
	prt.dat[prt.top++] = a;
}//·ûºÅÈëÕ»
char popt()
{
	return prt.dat[--prt.top];
}//·ûºÅ³öÕ»

char PRI[10][10] =
{
{ '>','>','<','<','<','<','<','>','>' },
{ '>','>','<','<','<','<','<','>','>' },
{ '>','>','>','>','<','<','<','>','>' },
{ '>','>','>','>','<','<','<','>','>' },
{ '>','>','>','>','>','<','<','>','>' },
{ '>','>','>','>','>','<','<','>','>' },
{ '<','<','<','<','<','<','<','=','0' },
{ '>','>','>','>','>','>','0','>','>' },
{ '<','<','<','<','<','<','<','0','=' }
};

int signswitch(char a)
{
	//±íÊ¾ÐòºÅ 
	switch (a)
	{
	case'+':return 0; case'-':return 1;
	case '*': return 2;   case '/': return 3;
	case '%': return 4;   case '^': return 5;
	case '(': return 6;   case ')': return 7;
	case '#': return 8;
		}
}//·ûºÅ×ª»»
char refusal(char a, char b)
{
    //aÇ°bºó ,ÅÐ¶¨ÓÅÏÈ¼¶
	return PRI[signswitch(a)][signswitch(b)];
}
int main()
{
	int n;
	char chinput[2000], b;
	char *p; 
	scanf("%d", &n);
	char c;
	scanf("%c", &c);
	while (n--) {
		scanf("%s", &chinput);
		prt.dat[0] = '#';
		prt.top = 1;
		p = chinput;
		while (*p != '#' || prt.dat[prt.top - 1] != '#') {
			//×Ö·û´®Î´±éÀúÍê±Ï   ||  ×Ö·ûÕ»Îª¿Õ 
			if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z') ) {
				printf("%c", *p);
				 p++;
				 if(*(p-1) >= '1' && *(p-1)<='9'){
				 	while((*p>='0' && *p <= '9')){
				 		printf("%c",*p);
				 		p++;
					 }
				 }
			}
			else {
				switch (refusal(prt.dat[prt.top - 1], *p))
				{
				case'<':pusht(*p++); break;//¸ßÔòÈëÕ»
				case'=':
					popt();
					p++; break;//ÍÑÀ¨ºÅ
				case'>':b = popt();
					printf("%c", b); break;
				}
			}
		}
	  printf("\n");
	}
	return 0;
}