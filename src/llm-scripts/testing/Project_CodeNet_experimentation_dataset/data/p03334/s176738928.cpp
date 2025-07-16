#include<bits/stdc++.h>
int n,d1,d2,color[606][606],N;
void paint(int d){
    int b=0;
    while(!(d&3))d>>=2,++b;
    if(d&1){
        for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
        if(((i>>b)+(j>>b))&1)color[i][j]=1;
    }else{
        for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
        if((i>>b)&1)color[i][j]=1;
    }
}
int main(){
    scanf("%d%d%d",&n,&d1,&d2);
    N=n<<1;
    paint(d1),paint(d2);
    int NN=n*n;
    for(int i=0;i<N;++i)
    for(int j=0;j<N;++j)
    if(!color[i][j]){
        printf("%d %d\n",i,j);
        if(!--NN)return 0;
    }
}