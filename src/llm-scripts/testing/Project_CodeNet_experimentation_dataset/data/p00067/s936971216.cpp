#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)

using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int ans;
string island[20];

int dfs(int x,int y){
    island[y][x]='0';
    REP(i,4){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0&&nx<12&&ny>=0&&ny<12&&island[ny][nx]=='1')dfs(nx,ny);
    }
    return 0;
}

int main(){
    while(1){
        REP(y,12){
            if(!(cin>>island[y]))return 0;
        }
        ans=0;
        REP(y,12){
            REP(x,12){
                if(island[y][x]=='1'){
                    dfs(x,y);
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}