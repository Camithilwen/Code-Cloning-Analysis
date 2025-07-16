#include<bits/stdc++.h>
using namespace std;
int f[100][100];
int main(){
    int a,b,i,j,k,s,t;
    scanf("%d%d",&a,&b);
    //a>=b
    if(a==0){
        printf("1 1\n#\n");
        return 0;
    }
    if(b==0){
        printf("1 1\n.\n");
        return 0;
    }
    printf("100 100\n");
    for(i=0;i<50;i++)for(j=0;j<100;j++)f[i][j]=0;//o->B->#
    for(i=50;i<100;i++)for(j=0;j<100;j++)f[i][j]=1;//1->A->.
    a--;b--;
    for(i=0;i<49&&a>0;i++)
        for(j=i%3;j<99&&a>0;j+=3){
            f[i][j]=1;
            a--;
        }
    for(i=51;i<100&&b>0;i++)
        for(j=i%3;j<99&&b>0;j+=3){
            f[i][j]=0;
            b--;
        }
    for(i=0;i<100;i++){
        for(j=0;j<100;j++){
            if(f[i][j]==0)printf("#");else printf(".");
        }
        printf("\n");
    }
    return 0;
}
