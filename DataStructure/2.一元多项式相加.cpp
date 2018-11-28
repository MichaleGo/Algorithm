/*
编写一元多项式加法运算程序。要求用线性链表存储一元多项式（参照课本）。该程序有以下几个功能：

1. 多项式求和

输入：输入三个多项式，建立三个多项式链表Pa、Pb、Pc

（提示：调用CreatePolyn(polynomial &P,int m)。

输出：显示三个输入多项式Pa、Pb、Pc、和多项式Pa+Pb、多项式Pa+Pb+Pc

（提示：调用AddPolyn(polynomial &Pa, polynomial Pb), 调用PrintPolyn(polynomial P))。

0. 退出

输入：
根据所选功能的不同，输入格式要求如下所示（第一个数据是功能选择编号，参见测试用例）：

1
多项式A包含的项数，以指数递增的顺序输入多项式A各项的系数（整数）、指数（整数）

多项式B包含的项数，以指数递增的顺序输入多项式B各项的系数（整数）、指数（整数）

多项式C包含的项数，以指数递增的顺序输入多项式C各项的系数（整数）、指数（整数）

0 －－－操作终止，退出。
输出：
对应一组输入，输出一次操作的结果（参见测试用例）。

1 多项式输出格式：以指数递增的顺序输出: <系数,指数>,<系数,指数>,<系数,指数>,参见测试用例。零多项式的输出格式为<0,0>
0 无输出
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN sizeof(struct node)
typedef struct node{
	int k;
	int e;
	struct node *next;
}Node;
struct node *in(int num){
	int i;
	struct node *head,*p,*p1;
	p1 = (Node *)malloc(LEN);
	scanf("%d%d", &p1->k, &p1->e);
	head = p1;
	for (i = 1; i < num; i++){
		p = (Node *)malloc(LEN);
		scanf("%d%d", &p->k, &p->e);
		p1->next = p;
		p1 = p;
	}
	p1->next = NULL;
	return head;
}
struct node *add1(struct node *a, struct node *b)
{
	struct node *head,*p,*p1;
	if (a->k == 0)
		return b;
	if (b->k == 0)
		return a;
	p = (Node *)malloc(LEN);
	while (1){
		if (a == NULL || b == NULL){
			p->k = 0;
			p->e = 0;
			p->next = NULL;
			return p;
		}
		if (a->e < b->e){
			p->e = a->e;
			p->k = a->k;
			a = a->next;
			break;
		}
		else{
			if (a->e>b->e){
				p->e = b->e;
				p->k = b->k;
				b = b->next;
				break;
			}
			else{
				int tt;
				tt = a->k + b->k;
				if (tt != 0){
					p->e = a->e;
					p->k = tt;
					a = a->next;
					b = b->next;
					break;
				}
				else{
					a = a->next;
					b = b->next;
				}
			}
		}
	}
	head = p1 = p;
	while (a != NULL&&b != NULL){
		p = (Node *)malloc(LEN);
		if (a->e < b->e){
			p->e = a->e;
			p->k = a->k;
			a = a->next;
			p1->next = p;
			p1 = p;
		}
		else{
			if (a->e>b->e){
				p->e = b->e;
				p->k = b->k;
				b = b->next;
				p1->next = p;
				p1 = p;
			}
			else{
				int tt;
				tt = a->k + b->k;
				if (tt != 0){
					p->e = a->e;
					p->k = tt;
					a = a->next;
					b = b->next;
					p1->next = p;
					p1 = p;
				}
				else{
					a = a->next;
					b = b->next;
				}
			}
		}
	}
	while (a != NULL){
		p = (Node *)malloc(LEN);
		p->e = a->e;
		p->k = a->k;
		p1->next = p;
		p1 = p;
		a = a->next;
	}
	while (b != NULL){
		p = (Node *)malloc(LEN);
		p->e = b->e;
		p->k = b->k;
		p1->next = p;
		p1 = p;
		b = b->next;
	}
	p1->next = NULL;
	return head;
}
void prt(struct node *head)
{
	if (head->k==0)
		printf("<0,0>\n");
	else{
		while (head->next != NULL){
			printf("<%d,%d>,", head->k, head->e);
			head = head->next;
		}
		printf("<%d,%d>\n", head->k, head->e);
	}
}
int main()
{
	int cmd;
	int i;
	int a, b, c;
	struct node *head_a, *head_b, *head_c;
	struct node *temp;
	struct node *add_1, *add_2;
	while (scanf("%d", &cmd) != EOF){
		if (cmd == 0)
			break;
		scanf("%d", &a);
		head_a = in(a);
		scanf("%d", &b);
		head_b = in(b);
		scanf("%d", &c);
		head_c = in(c);
		temp = head_a;
		for (i = 1; i < a; i++){
			printf("<%d,%d>,", temp->k, temp->e);
			temp = temp->next;
		}
		printf("<%d,%d>\n", temp->k, temp->e);
		temp = head_b;
		for (i = 1; i < b; i++){
			printf("<%d,%d>,", temp->k, temp->e);
			temp = temp->next;
		}
		printf("<%d,%d>\n", temp->k, temp->e);
		temp = head_c;
		for (i = 1; i < c; i++){
			printf("<%d,%d>,", temp->k, temp->e);
			temp = temp->next;
		}
		printf("<%d,%d>\n", temp->k, temp->e);
		add_1 = add1(head_a, head_b);
		prt(add_1);

		add_2 = add1(add_1, head_c);
		prt(add_2);
	}
	return 0;
}