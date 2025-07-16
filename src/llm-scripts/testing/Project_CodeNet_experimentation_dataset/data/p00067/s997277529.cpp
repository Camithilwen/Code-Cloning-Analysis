#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
char field[12][12];
int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};

void dfs(int x,int y){
    field[x][y]='0';
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(0<=nx&&nx<12&&0<=ny&&ny<12&&field[nx][ny]=='1')dfs(nx,ny);
    }
    return;
}

int main(void){
    char a;
    while(cin>>a){
        int ans=0;
        for(int i=0;i<12;i++){
            for(int j=0;j<12;j++){
                if(i==0&&j==0)field[0][0]=a;
                else cin>>field[i][j];
            }
        }
        for(int i=0;i<12;i++){
            for(int j=0;j<12;j++){
                if(field[i][j]=='1'){
                    dfs(i,j);ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}
