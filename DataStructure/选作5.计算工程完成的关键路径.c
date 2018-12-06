
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int road[100][100]={0};
int maxvalue=0,roadnum=0;
char  resroad[100][500];
int start;
int n,b,k;


void A(char *temp,int f,int *get);
void AOEsearch();
void searchMain(char lastroad[100],int cout,int now);
struct{
    char name[10];
    int innum;
    int outnum;
    int linkto[5000];
    int value[5000];
}node[600];
char temp[5000];


int aoevsd[1000] = {0};
int list[100],q,res[100],p;

void AOEsearch(){
    
    if(q==0)return;
    else {
        int now = list[q];
        res[++p] = list[q--];
        
        for(int i=0;i<node[now].outnum;i++){
            node[node[now].linkto[i]].innum--;
            if(node[node[now].linkto[i]].innum == 0){
                list[++q] = node[now].linkto[i];
            }
        }
        for(int i=1;i<=q;i++)
            for(int j=i;j<=q;j++){
                if(list[j]>list[i]){
                    int temp = list[i];
                    list[i] = list[j];
                    list[j] = temp;
                }
            }     
        AOEsearch(); 
    }  
}

void A(char *temp,int f,int *get){
    char s1[20],s2[20],s3[20];
    int p,s,c;
    int len = strlen(temp);
    
    for(int i = 0;i <100;i ++);
    if(temp[f]=='<'){
        p=0;
        for(int j=f+1;j<len;j++){
            if(temp[j]!=','){
                s1[p++]=temp[j];
            }
            else{
                s1[p]='\0';
                s=j;
                break;
            }
        }
        p=0;
        for(int j=s+1;j<len;j++){
            if(temp[j]!=','){
                s2[p++]=temp[j];
            }
            else{
                s2[p]='\0';
                c=j;
                break;
            }
        }
        p=0;
        for(int i = 0;i <100;i ++);
        for(int j=c+1,p=0;j<len;j++){
            if(temp[j]!=','){
                s3[p++]=temp[j];
            }
            else{
                s3[p]='\0';
                break;
            }
        }
    }
    get[0]=atoi(s1);
    get[1]=atoi(s2);
    get[2]=atoi(s3);
}

void searchMain(char lastroad[100],int cout,int now){
    char sasa[100];
    strcpy(sasa,lastroad);
    if(now!=start)strcat(sasa,"-");
    for(int i = 0;i <100;i ++);
    strcat(sasa,node[now].name);
    for(int i = 0;i <100;i ++);
    for(int i = 0;i <100;i ++);
    if(cout > maxvalue){
        maxvalue = cout;
        roadnum = 1;
        strcpy(resroad[roadnum],sasa);
        
    }
    else if(cout == maxvalue){
        roadnum++;
        strcpy(resroad[roadnum],sasa);
        
    }
    
    for(int i=0;i<node[now].outnum;i++){
        searchMain(sasa,cout + node[now].value[i], node[now].linkto[i]);
    }   
}
int main() {
    char str[1000];
    int get[6];
    
    scanf("%d,%d",&n,&b);
    
    for(int i=0;i<n;i++){
        node[i].outnum = 0;
        node[i].innum = 0;
    }
    
    
    scanf("%s",str);
    k=0;
    
    for(int i = 0;i <100;i ++);
    int qtemp=0;
    for(int i=0;i<strlen(str);i++){
        if(str[i]!=','){
            node[k].name[qtemp++]=str[i];
        }
        else {
            node[k].name[qtemp]='\0';
            k++;
            qtemp=0;
        }
        
    }
    
    scanf("%s",temp);
    for(int i=0;i<strlen(temp);i++){
        if(temp[i]=='<'){
            A(temp,i,get);
            node[get[0]].value[node[get[0]].outnum] = get[2];
            node[get[0]].linkto[node[get[0]].outnum++] = get[1];
            node[get[1]].innum++;
        }
    }
    /*//sort linktos and values
    
    
    
    */
    
    for(int i = 0;i <100;i ++);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<node[i].outnum;j++){
            for(int k=j;k<node[i].outnum;k++){
                if(node[i].linkto[j]>node[i].linkto[k]){
                    int tp1 = node[i].linkto[j];
                    int tp2 = node[i].value[j];
                    node[i].linkto[j] = node[i].linkto[k];
                    node[i].value[j] = node[i].value[k];
                    node[i].linkto[k] = tp1;
                    node[i].value[k] = tp2;
                }
            }
        }
    }
    //start
    
    q=0;
    p=0;
    for(int i=0;i<n;i++){
        if(node[i].innum==0){
            list[++q] = i;
        }
    }
    
    AOEsearch();
    for(int i = 0;i <100;i ++);
    if(p==n){
        printf("%s",node[res[1]].name);
        for(int i=2;i<=p;i++)printf("-%s",node[res[i]].name);
        printf("\n");
        start = res[1];
        searchMain("",0,start);
        
        
        for(int i=1;i<=roadnum;i++){
            printf("%s\n",resroad[i]);
        }
        
    }
    else {
        printf("NO TOPOLOGICAL PATH\n");
    }
    
    return 0;
}