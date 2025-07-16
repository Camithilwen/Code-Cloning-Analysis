#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
//#define MOD 1000000007
const int INF = 1LL<<30;

char fi[410][410];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int h,w;
int vis[410][410];

int main() {
    
    cin>>h>>w;

    rep(i,h){
        rep(j,w){
            cin>>fi[i][j];
        }
    }

    ll ans=0;
    rep(i,h){
        rep(j,w){
            if(vis[i][j]) continue;
            vis[i][j]=true;
            vector<ll> num(2,0);
            queue<pair<int,int>> que;
            que.push({i,j});

            while (!que.empty())
            {
                auto p=que.front();
                que.pop();
                int x=p.first,y=p.second;
                num[fi[x][y]=='#']++;

                rep(k,4){
                    int nx=x+dx[k];
                    int ny=y+dy[k];
                    if(nx>=0 && nx<h && ny>=0 && ny<w && !vis[nx][ny] && fi[nx][ny]!=fi[x][y]){
                        que.push({nx,ny});
                        vis[nx][ny]=true;
                    }
                }
            }
            ans+=num[0]*num[1];
        }
    }

    cout<<ans<<endl;
}