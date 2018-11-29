#include<stdio.h>
#include<string.h>
#include<math.h>
#define CHAR 1
#define NUM 0
int check(char s)
{
	if (s == '+' || s == '-' || s == '*' || s == '/' || s == '^' || s == '%')
		return CHAR;
	else
		return NUM;
}
int cmp(char a, char b){
	if (a == b&&a == '^')
		return -1;
	if (a == b)
		return 1;
	if ((a == '*' || a == '/') && (b == '+' || b == '-'))
		return 1;
	if ((a == '+' || a == '-') && (b == '*' || b == '/'))
		return -1;
	if (a != '^'&&b == '^')
		return -1;
	if (a == '^'&&b != '^')
		return 1;
	if ((a == '+' || a == '-') && (b == '+' || b == '-'))
		return 1;
	if ((a == '*' || a == '/') && (b == '*' || b == '/'))
		return 1;
	if (a == '\0'&&check(b))
		return -1;
	if (a == '('&&check(b))
		return -1;
}
int Operator(int a, int b, char s)
{
	if (s == '+')
		return a + b;
	if (s == '-')
		return a - b;
	if (s == '*')
		return a*b;
	if (s == '/')
		return a / b;
	if (s == '%')
		return a%b;
	if (s == '^')
		return pow(a,b);
}
int main()
{
	int N;
	int i;
	char StackOperator[1000];
	int NumOperator[1000];
	char map[1000];
	int len;
	int flag_Stack;
	int flag_Num;
	int flag_temp = 1;
	int flag;
	scanf("%d", &N);
	while (N--){
		memset(StackOperator, 0, sizeof(StackOperator));
		memset(NumOperator, 0, sizeof(NumOperator));
		memset(map, 0, sizeof(map));
		StackOperator[0] = '\0';
		flag = 0;
		flag_Stack = 1;
		flag_Num = 0;
		scanf("%s", map);
		len = strlen(map);
		for (i = 0; i < len; i++){
			flag_temp = 1;
			if (i == 0 && map[i + 1] >= '0'&&map[i + 1] <= '9'&&map[0]=='-'){
				flag_temp = -1;
				i++;
				goto k;
			}
			if (i == 0 && map[i + 1] >= '0'&&map[i + 1] <= '9'&&map[0] == '+'){
				i++;
				goto k;
			}
			if (map[i] == '('){
				if (map[i - 1] == ')'){
					printf("error.\n");
					goto h;
				}
				if (map[i - 1] >= '0'&&map[i - 1] <= '9'){
					printf("error.\n");
					goto h;
				}
				if (check(map[i + 1]) && map[i + 1] != '+'&&map[i + 1] != '-'){
					printf("error.\n");
					goto h;
				}
				StackOperator[flag_Stack] = map[i];
				flag_Stack++;
				if ((map[i + 1] == '+' || map[i + 1] == '-') && map[i + 2] >= '0'&&map[i + 2] <= '9')
					i++;
			}
			else{
				if (map[i] >= '0' && map[i] <= '9'){
					if (map[i - 1] == '-'&&(check(map[i - 2])||map[i-2]=='('))
						flag_temp = -1;
				k:;
					while (1){
						if (map[i] >= '0'&&map[i] <= '9'){
							NumOperator[flag_Num] = NumOperator[flag_Num] * 10 + map[i] - '0';
							i++;
						}
						else
							break;
					}
					if (flag_temp == -1)
						NumOperator[flag_Num] *= -1;
					flag_Num++;
					i--;
				}
				else{
					if (check(map[i]) == 1){
						if (cmp(StackOperator[flag_Stack - 1], map[i]) < 0){
							StackOperator[flag_Stack] = map[i];
							flag_Stack++;
							if ((map[i + 1] == '+' || map[i + 1] == '-') && map[i + 2] >= '0'&&map[i + 2] <= '9')
								i++;
						}
						else{
							while (1){
								if (cmp(StackOperator[flag_Stack - 1], map[i])>0){
									if (NumOperator[flag_Num - 1] == 0 && StackOperator[flag_Stack - 1] == '/'){
										printf("Divide 0.\n");
										goto h;
									}
									if (NumOperator[flag_Num - 1] < 0 && StackOperator[flag_Stack - 1] == '^'){
										printf("error.\n");
										goto h;
									}
									NumOperator[flag_Num - 2] = Operator(NumOperator[flag_Num - 2], NumOperator[flag_Num - 1], StackOperator[flag_Stack - 1]);
									NumOperator[flag_Num - 1] = 0;
									flag_Num--;
									flag_Stack--;
								}
								else
									break;
							}
							StackOperator[flag_Stack] = map[i];
							flag_Stack++;
							if ((map[i + 1] == '+' || map[i + 1] == '-') && map[i + 2] >= '0'&&map[i + 2] <= '9')
								i++;
						}
					}
					else{
						if (map[i] == ')'){
							if (map[i + 1] >= '0' && map[i + 1] <= '9'){
								printf("error.\n");
								goto h;
							}
							if (map[i + 1] == '('){
								printf("error.\n");
								goto h;
							}
							while (1){
								if (StackOperator[flag_Stack - 1] != '('){
									if (NumOperator[flag_Num - 1] == 0 && StackOperator[flag_Stack - 1] == '/'){
										printf("Divide 0.\n");
										goto h;
									}
									if (NumOperator[flag_Num - 1] < 0 && StackOperator[flag_Stack - 1] == '^'){
										printf("error.\n");
										goto h;
									}
									if (StackOperator[flag_Stack - 1] == '\0'){
										printf("error.\n");
										goto h;
									}
									NumOperator[flag_Num - 2] = Operator(NumOperator[flag_Num - 2], NumOperator[flag_Num - 1], StackOperator[flag_Stack - 1]);
									NumOperator[flag_Num - 1] = 0;
									flag_Num--;
									flag_Stack--;
								}
								else{
									flag_Stack--;
									break;
								}
							}
						}
					}
				}
			}
		}
		while (1){
			if (StackOperator[flag_Stack - 1] != '\0'&&StackOperator[flag_Stack - 1] !='(' ){
				if (NumOperator[flag_Num - 1] == 0 && StackOperator[flag_Stack - 1] == '/'){
					printf("Divide 0.\n");
					goto h;
				}
				if (NumOperator[flag_Num - 1]<0 && StackOperator[flag_Stack - 1] == '^'){
					printf("error.\n");
					goto h;
				}
				NumOperator[flag_Num - 2] = Operator(NumOperator[flag_Num - 2], NumOperator[flag_Num - 1], StackOperator[flag_Stack - 1]);
				NumOperator[flag_Num-1] = 0;
				flag_Num--;
				flag_Stack--;
			}
			else{
				if (StackOperator[flag_Stack - 1] == '('){
					printf("error.\n");
					goto h;
				}
				else
					break;
			}
		}
		printf("%d\n", NumOperator[0]);
	h:;
	}
	return 0;
}