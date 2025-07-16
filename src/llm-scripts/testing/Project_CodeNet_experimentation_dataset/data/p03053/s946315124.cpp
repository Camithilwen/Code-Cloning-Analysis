#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

int dist[1005][1005];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main(){
    int h,w;cin >> h >> w;
    queue<int> q;
    rep(i,h)rep(j,w){
        char ch;cin >> ch;
        if(ch == '#'){
            dist[i][j]=0;
            q.push(w*i+j);
        }else dist[i][j] = -1;
    }

    while(q.size()){
        int ind = q.front();
        q.pop();
        int y = ind/w;
        int x = ind%w;
        for(int i = 0;i < 4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || h <= ny || w <= nx) continue;
            if(dist[ny][nx]!=-1) continue;
            dist[ny][nx] = dist[y][x] + 1;
            q.push(w*ny+nx);
        }
    }
    int ans = 0;
    rep(i,h){
        rep(j,w){
            ans = max(ans,dist[i][j]);
        }
    }
    cout << ans << endl;


}