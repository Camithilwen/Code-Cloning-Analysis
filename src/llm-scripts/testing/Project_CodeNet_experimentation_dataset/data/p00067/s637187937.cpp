#include<iostream>
#include<cstdio>
using namespace std;

char map[13][13];
int d[13][13];
int dy[4]={-1,0,1,0};
int dx[4]={0,-1,0,1};

void bfs(int y,int x);
int main(){
    char a[12];
    string str;
    while(1){
    int co=0;
    for(int i=0;i<12;i++){
        cin>>map[i];
    }
    if(cin.eof())break;
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
            d[i][j]=0;
        }
    }
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
          if(map[i][j]=='1' && d[i][j]==0){
	    co++;
            bfs(i,j);
          }
        }
    }
    cout<<co<<endl;
    }
}
void bfs(int y,int x){
    d[y][x]=1;
    for(int p=0;p<4;p++){
        int ny=y+dy[p];
        int nx=x+dx[p];
        if(ny>=0 && ny<12 && nx>=0  && nx<12  && d[ny][nx]==0 && map[ny][nx]=='1' ){
            bfs(ny,nx);
        }
    }
   return;
}