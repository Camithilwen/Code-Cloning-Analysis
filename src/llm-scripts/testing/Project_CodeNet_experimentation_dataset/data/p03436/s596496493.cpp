#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<ll,ll> P;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define EFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i, n) FOR(i,0,n)
#define IINF 1e9

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
// memo:BFS 
int main(void){
    int h,w,ans = 0;
    cin >> h >> w;
    vector<vector<char>> s(h,vector<char>(w));
    vector<vector<int>> dist(h,vector<int>(w,-2));
    queue<P> q;
    int c_hash = 0;
    REP(i,h)REP(j,w){
        cin >> s[i][j];
        if(s[i][j] == '#') dist[i][j] = -1,c_hash++;
    }

    q.push(P(0,0));
    dist[0][0] = 0;
    while(!q.empty()){
        P v = q.front();
        q.pop();
        REP(i,4){
            int vx = v.first + dx[i];
            int vy = v.second + dy[i];   
            if(vx < 0 || vx >= h || vy < 0 || vy >= w) continue;
            if(dist[vx][vy] == -2){
            dist[vx][vy] = dist[v.first][v.second] + 1;
            q.push(P(vx,vy)); 
            }
            
        }
    }
    
    if(dist[h-1][w-1] > 0 ) ans = h*w - c_hash - dist[h-1][w-1] - 1;
    else ans = -1;
    cout << ans << endl;
    return 0;
}