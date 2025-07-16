#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
#include <utility>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
string table[12];

void dfs(int x,int y){
    table[x][y]='0';
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0&&nx<12&&ny>=0&&ny<12&&table[nx][ny]=='1'){
            dfs(nx,ny);
        }        
    }
}

int main(){
    while(cin >> table[0]){
        for(int i=1;i<12;i++) cin >> table[i];
        int ans=0;
        rep(i,12){
            rep(j,12){
                if(table[i][j]=='1'){
                    dfs(i,j);
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}