#include <stdio.h>
#include <malloc.h>   //malloc,realloc
#include <math.h>     //含有overflow
#define MAXSIZE 12500 
typedef struct{
	int i,j;//row, clomun
	int e;//data
}triple;//三元组

typedef struct{
	triple data[MAXSIZE];
	int mu;//行数
	int nu;//列数
	int tu;//非零元个数 
}matrix; 

matrix M,*T;
int num[1000];
int cpos[1000];
void FastTransMatrix(matrix M, matrix *T);

int main(){
	int i;
	T = (matrix*)malloc(sizeof(matrix));
	scanf("%d %d %d",&M.mu , &M.nu , &M.tu );
	for(i = 1;i <= M.tu ;i ++){
		scanf("%d",&M.data [i].i) ;
		scanf("%d",&M.data [i].j) ;
		scanf("%d",&M.data [i].e) ;
	}
	
	FastTransMatrix(M,T);
	
	for(i = 1;i <= (*T).tu ;i ++){
		printf("%d,",(*T).data [i].i);
		printf("%d,",(*T).data [i].j);
		printf("%d\n",(*T).data [i].e);
	}
}

void FastTransMatrix(matrix M, matrix *T)
{
	(*T).mu =M.mu ;(*T).nu = M.nu ;(*T).tu = M.tu ;
	int p,col,i;
	for(col = 1;col <= M.nu;col ++){
		num[col] = 0;
	}
	
	for(p = 1;p <= M.tu;p ++){
		col = M.data [p].j;
		num[col] ++;
	}
	
	printf("num:");
	for(i = 1;i <= M.nu;i ++ ){
		printf("%d,",num[i]);
	}
	printf("\n");
	
	cpos[1] = 1;
	for(col = 2;col <= M.nu;col ++){
		cpos[col] = cpos[col - 1] + num[col - 1];
	}
		
	printf("cpot:");
	for(i = 1;i <= M.nu;i ++ ){
		printf("%d,",cpos[i]);
	}
	printf("\n");
	
	
	for(p = 1;p <= M.tu;p ++){
		col =  M.data [p].j;
		(*T).data[cpos[col]].i  = M.data[p].j ;
		(*T).data[cpos[col]].j  = M.data[p].i ;
		(*T).data[cpos[col]].e  = M.data[p].e ;
		cpos[col]++;
	}
}