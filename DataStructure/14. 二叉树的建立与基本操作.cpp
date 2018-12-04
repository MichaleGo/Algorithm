#include<iostream>
#include<cstdio>  
#include<queue>  
#include<algorithm>  
using namespace std;  

typedef struct Node{  
    char data;  
    struct Node *lchild;  
    struct Node *rchild;  
}Node, *BiTree;   

void CreateTree();
void PreOrderTravel(BiTree T) ;
void InOrderTravel(BiTree T)  ;
void PostOrderTravel(BiTree T)  ;
queue<Node*>Q;
int num = 0;

void CreateTree()
{
	//层序序列 建立二叉树，一个队列，一个二叉树。
	char ch;
	Node *T;
	while (!Q.empty()){
		T = Q.front() ;
		Q.pop();
		scanf("%c",&ch);
		if(ch == '\n') break;
		T->data = ch;
		
		Node* N = (Node*)malloc(sizeof(Node));
		N->data = '\0';
		N->lchild = NULL;
		N->rchild = NULL;
		T->lchild = N;
		Q.push(N);  
		
		N = (Node*)malloc(sizeof(Node));
		N->data = '\0';
		N->lchild = NULL;
		N->rchild = NULL;
		T->rchild = N;
		Q.push(N);  
		
	}
}

void Visit(BiTree T)  
{  
    if (T->data!='#'&&T->data != '\0')  
        printf("%c", T->data);  
}  

void PreOrderTravel(BiTree T)
{
	if(T)
	{
		if(T->data != '\0' && T->data != '#'){
			Visit(T);
			PreOrderTravel(T->lchild );
			PreOrderTravel(T->rchild );
		}
	}
}

void PostOrderTravel(BiTree T)  
{  
    if(T)
	{
		if(T->data != '\0' && T->data != '#'){
			PostOrderTravel(T->lchild );
			PostOrderTravel(T->rchild );
			Visit(T);
		}
	}  
} 

void InOrderTravel(BiTree T)  
{  
    if (T->data != '#'&&T->data != '\0'){  
        InOrderTravel(T->lchild);  
        if ((T->lchild->data == '#' || T->lchild->data == '\0') &&
		 (T->rchild->data == '#' || T->rchild->data == '\0'))  
            num++;  
        Visit(T);  
        InOrderTravel(T->rchild);  
    }  
    return;  
} 

void PrintAoru(BiTree T,int i)
{
	if(T->data != '#'&&T->data != '\0'){
		for(int j = 1;j <= i; j ++){
			printf("    ");
		}
		Visit(T);
		printf("\n");
		PrintAoru(T->lchild ,i+1);
		PrintAoru(T->rchild ,i+1);
		
	}
}

void AntiPrintAoru(BiTree T, int i){  
  
    if (T->data != '#'&&T->data != '\0'){  
        int j;  
        for (j = 1; j <= i; j++)  
            printf("    ");  
        Visit(T);  
        printf("\n");  
        i++;  
        AntiPrintAoru(T->rchild, i);  
        AntiPrintAoru(T->lchild, i);  
    }  
}  
void AntiPreOrderTravel(BiTree T)  
{  
    if (T->data != '#'&&T->data != '\0'){  
        Visit(T);  
        AntiPreOrderTravel(T->rchild);  
        AntiPreOrderTravel(T->lchild);  
    }  
    return;  
}  

void AntiInOrderTravel(BiTree T)  
{  
    if (T->data != '#'&&T->data != '\0'){  
        AntiInOrderTravel(T->rchild);  
        Visit(T);  
        AntiInOrderTravel(T->lchild);  
    }  
    return;  
}  

void AntiPostOrderTravel(BiTree T)  
{  
    if (T->data != '#'&&T->data != '\0'){  
        AntiPostOrderTravel(T->rchild);  
        AntiPostOrderTravel(T->lchild);  
        Visit(T);  
    }  
    return;  
}  


int main()
{
	Node *Root = (Node*)malloc(sizeof(Node));
	Q.push(Root);  
	CreateTree();
	printf("BiTree\n");  
    PrintAoru(Root, 0);  
    printf("pre_sequence  : ");  
    PreOrderTravel(Root);  
    printf("\n");  
    printf("in_sequence   : ");  
    InOrderTravel(Root);  
    printf("\n");  
    printf("post_sequence : ");  
    PostOrderTravel(Root);  
    printf("\n");  
    
    printf("Number of leaf: %d\n", num);  
    
    printf("BiTree swapped\n");  
    AntiPrintAoru(Root, 0);  
    printf("pre_sequence  : ");  
    AntiPreOrderTravel(Root);  
    printf("\n");  
    printf("in_sequence   : ");  
    AntiInOrderTravel(Root);  
    printf("\n");  
    printf("post_sequence : ");  
    AntiPostOrderTravel(Root);  
    printf("\n");  
    return 0;  
}