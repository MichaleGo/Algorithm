#include <stdio.h>
#include <malloc.h>   //malloc,realloc
#include<string.h>
typedef struct{
	int i,j;//row, clomun
	int e;//data
}triple;//三元组

typedef struct{
	triple data[110];
	int mu;//行数
	int nu;//列数
	int tu;//非零元个数 
}matrix; 

matrix M, N, *Q;
int num[100010];
int cpos[10010];
int ctemp[10010];
void multip(matrix M,matrix N, matrix *Q );

int main(){
	//
	int i;
	Q = (matrix*)malloc(sizeof(matrix));
	scanf("%d %d %d",&M.mu , &M.nu , &M.tu );
	for(i = 1;i <= M.tu ;i ++){
		scanf("%d",&M.data [i].i) ;
		scanf("%d",&M.data [i].j) ;
		scanf("%d",&M.data [i].e) ;
	}
	
	scanf("%d %d %d",&N.mu , &N.nu , &N.tu );
	for(i = 1;i <= N.tu ;i ++){
		scanf("%d",&N.data [i].i) ;
		scanf("%d",&N.data [i].j) ;
		scanf("%d",&N.data [i].e) ;
	}
	
	multip(M, N, Q);
	
	printf("%d\n",(*Q).mu);
	printf("%d\n",(*Q).nu);
	printf("%d\n",(*Q).tu);
	for(i = 1;i <= (*Q).tu ;i ++){
		printf("%d,",(*Q).data [i].i);
		printf("%d,",(*Q).data [i].j);
		printf("%d\n",(*Q).data [i].e);
	}
	
	return 0;
} 

void multip(matrix M,matrix N, matrix *Q )
{
	int i, j, k = 1, p, col;
	(*Q).mu = M.mu;
	(*Q).nu = N.nu;
	(*Q).tu = 0;
	for(col = 0; col <= N.mu;col ++){
		num[col] = 0;
	}
	for(i = 0;i < 1000;i++){
		ctemp[i] = 0;
	}
	//按照行标号 标记 矩阵N ，方便对第k行的元素寻址。 
	for(i = 1;i <= N.tu; i ++ ){
		col = N.data [i].i;
		num[col]++;
	}
	cpos[1] = 1;
	for(col = 2; col <= N.mu+1;col ++){
		cpos[col] = cpos[col-1] + num[col - 1];
	}
	
	//核心代码 
	// traverse M 
	for(i = 1;i <= M.tu;i ++){
		 //M  row i only one ele 
		if(M.data[i].i != M.data[i+1].i){
			
			col = M.data[i].j;
			for(j = cpos[col];j <= cpos[col+1] - 1; j++){
			    (*Q).data[k].i = M.data[i].i;
			    (*Q).data[k].j = N.data[j].j;
			    (*Q).data[k].e = M.data[i].e * N.data[j].e ;
			    k++;
			    (*Q).tu++;
		    }
		}else{
			// M  row i one more ele. 
			memset(ctemp,0,sizeof(ctemp));
			while(M.data[i].i == M.data[i+1].i){
				//traverse the same row eles of M 
				col = M.data[i].j;
			    for(j = cpos[col];j <= cpos[col+1] - 1; j++){
			    	p = N.data[j].j;//p的最大值是N的nu 
			    	ctemp[p] +=  M.data[i].e * N.data[j].e;
		        }
		        i++;
			}
			 	col = M.data[i].j;
			    for(j = cpos[col];j <= cpos[col+1] - 1; j++){
			    	p = N.data[j].j;//p的最大值是N的nu 
			    	ctemp[p] +=  M.data[i].e * N.data[j].e;
		        }
			
			//copy to Q
			for(p = 1;p <= N.nu;p ++){
				if(ctemp[p]){
					(*Q).data[k].i = M.data[i].i;
					(*Q).data[k].j = p;
					(*Q).data[k].e = ctemp[p] ;//很自然的就可以保证Q按行列有序 
					k++;
					(*Q).tu++;
				}
			}
		}
	}
	
	return;
}