#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct AVLNode *Position;
typedef Position AVLTree; /* AVL树类型 */
typedef char ElementType;
struct AVLNode{
    ElementType Data; /* 结点数据 */
    AVLTree Left;     /* 指向左子树 */
    AVLTree Right;    /* 指向右子树 */
    int Height;       /* 树高 */
};
 
int Max ( int a, int b )
{
    return a > b ? a : b;
}

int GetHeight(AVLTree T){
	if(!T)return 0;
	else return T->Height ;
}
 
AVLTree SingleLeftRotation ( AVLTree A )
{ /* 注意：A必须有一个左子结点B */
  /* 将A与B做左单旋，更新A与B的高度，返回新的根结点B */     
  
    AVLTree B = A->Left;
    A->Left = B->Right;
    B->Right = A;
    A->Height = Max( GetHeight(A->Left), GetHeight(A->Right) ) + 1;
    B->Height = Max( GetHeight(B->Left), A->Height ) + 1;
  
    return B;
}

AVLTree SingleRightRotation( AVLTree A)
{
	AVLTree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	A->Height = Max( GetHeight(A->Left), GetHeight(A->Right) ) + 1;
    B->Height = Max( GetHeight(B->Right), A->Height ) + 1;
	
	return B;
}
 
AVLTree DoubleLeftRightRotation ( AVLTree A )
{ /* 注意：A必须有一个左子结点B，且B必须有一个右子结点C */
  /* 将A、B与C做两次单旋，返回新的根结点C */
     
    /* 将B与C做右单旋，C被返回 */
    A->Left = SingleRightRotation(A->Left);
    /* 将A与C做左单旋，C被返回 */
    return SingleLeftRotation(A);
}
 
AVLTree DoubleRightLeftRotation ( AVLTree A )
{ 
    A->Right = SingleLeftRotation(A->Right);
    return SingleRightRotation(A);
}

 
AVLTree Insert( AVLTree T, ElementType X )                         /*传进来的指针一定会改变，程序繁琐尽量少用指针的指针，多用返回值*/
{ /* 将X插入AVL树T中，并且返回调整后的AVL树 */
    if ( !T ) { /* 若插入空树，则新建包含一个结点的树 */
        T = (AVLTree)malloc(sizeof(struct AVLNode));
        T->Data = X;
        T->Height = 0;
        T->Left = T->Right = NULL;
    } /* if (插入空树) 结束 */
 
    else if ( X < T->Data ) {
        /* 插入T的左子树 */
        T->Left = Insert( T->Left, X);
        /* 如果需要左旋 */
        if ( GetHeight(T->Left)-GetHeight(T->Right) == 2 )
            if ( X < T->Left->Data ) 
               T = SingleLeftRotation(T);      /* 左单旋 */
            else 
               T = DoubleLeftRightRotation(T); /* 左-右双旋 */
    } /* else if (插入左子树) 结束 */
     
    else if ( X > T->Data ) {
        /* 插入T的右子树 */
        T->Right = Insert( T->Right, X );
        /* 如果需要右旋 */
        if ( GetHeight(T->Left)-GetHeight(T->Right) == -2 )
            if ( X > T->Right->Data ) 
               T = SingleRightRotation(T);     /* 右单旋 */
            else 
               T = DoubleRightLeftRotation(T); /* 右-左双旋 */
    } /* else if (插入右子树) 结束 */
 
    /* else X == T->Data，无须插入 */
 
    /* 别忘了更新树高 */
    T->Height = Max( GetHeight(T->Left), GetHeight(T->Right) ) + 1;
     
    return T;
}

void PreOrderTravel(AVLTree T)
{
	if(T)
	{
			printf("%c", T->Data);  
			PreOrderTravel(T->Left );
			PreOrderTravel(T->Right );
	}
}

void PostOrderTravel(AVLTree T)  
{  
    if(T)
	{		
			PostOrderTravel(T->Left );
			PostOrderTravel(T->Right );
			printf("%c", T->Data);  	
	}  
} 

void InOrderTravel(AVLTree T)  
{  
    if (T){  
        InOrderTravel(T->Left);  
        printf("%c", T->Data);  
        InOrderTravel(T->Right);  
    }  
    return;  
} 

void Post(AVLTree T,int depth)
{
	int i = 0;
	if(T){
		Post(T->Right,depth+1 );
		for(;i < depth;i ++)printf("    ");
		printf("%c\n",T->Data );
		Post(T->Left,depth+1 );
	}
	return ;
}

int main()
{
	char s[10000];int i = 0;
	gets(s);
	AVLTree T = NULL;
	for(i = 0;i < strlen(s);i ++)
		T = Insert(T,s[i]);
	printf("Preorder: ");PreOrderTravel(T);printf("\n");
	printf("Inorder: ");InOrderTravel(T);printf("\n");
	printf("Postorder: ");PostOrderTravel(T);printf("\n");
	printf("Tree:\n");
	Post(T,0);
	return 0;
}