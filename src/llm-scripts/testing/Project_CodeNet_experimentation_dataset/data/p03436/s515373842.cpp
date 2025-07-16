#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
using vc=vector<char>;

int dr[4]={-1,0,0,1};
int dc[4]={0,-1,1,0};

void bfs(const vector<vc> &field, vector<vi> &dist){
    queue<pair<int,int>> que;
    que.push({1,1});
    dist[1][1]=0;
    while(!que.empty()){
        auto x=que.front(); que.pop();
        for(int i=0;i<4;i++){
            int nr=x.first+dr[i];
            int nc=x.second+dc[i];
            if(field[nr][nc]=='#') continue;
            if(dist[nr][nc]!=-1) continue;
            dist[nr][nc]=dist[x.first][x.second]+1;
            que.push({nr,nc});
        }
    }
}

int main(){
    int r,c;
    cin >> r >> c;
    vector<vc> field(r+2,vc(c+2,'#'));
    int ans=0;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> field[i][j];
            if(field[i][j]=='.') ans++;
        }
    }
    vector<vi> dist(r+2,vi(c+2,-1));
    bfs(field,dist);
    if(dist[r][c]==-1){
        cout << "-1" << endl;
        return 0;
    }
    cout << ans-dist[r][c]-1 << endl;
    
}