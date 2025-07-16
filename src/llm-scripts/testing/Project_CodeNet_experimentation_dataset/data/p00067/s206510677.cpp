#include<iostream>
#include<cstdio>
using namespace std;
int n,m,x1[4]={0,0,1,-1},y1[4]={1,-1,0,0};
char island[13][13];
int serch(int x,int y)
{
    island[x][y]='0';
    for(int i=0;i<4;i++){
        int x2=x+x1[i],y2=y+y1[i];
        if(x2>=0&&x2<=11&&y2>=0&&y2<=11&&island[x2][y2]=='1')serch(x2,y2);
    }
    //cout<<"end\n";
}
int main(void)
{
    int A=0;
    while(1){
            A=0;
    for(int i=0;i<12;i++){
           if(scanf("%s",island[i])==EOF)goto end1;
    }
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
            if(island[i][j]=='1'){
               // cout<<"str\n";
                serch(i,j);
                A++;
            }
        }
    }
    cout<<A<<"\n";
    }
    end1:;
}