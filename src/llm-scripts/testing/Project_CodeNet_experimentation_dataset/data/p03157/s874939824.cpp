#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll INF=1e18;
const ll mod=1e9+7;

int main(){
    ll h,w;
    cin >> h >> w;
    ll dx[4]={-1,1,0,0};
    ll dy[4]={0,0,-1,1};
    vector<vector<char>> s(h,vector<char>(w));
    rep(i,h){
        rep(j,w){
            cin >> s[i][j];
        }
    }
    vector<vector<ll>> used(h,vector<ll>(w));
    ll ans=0;
    rep(i,h){
        rep(j,w){
            if(used[i][j]) continue;
            queue<pll> que;
            que.push({i,j});
            ll white=0,black=0;
            used[i][j]=1;
            while(!que.empty()){
                pll x=que.front();
                que.pop();
                if(s[x.fi][x.se]=='#') black++;
                else white++;
                rep(k,4){
                    ll nx=x.fi+dx[k];
                    ll ny=x.se+dy[k];
                    if(0<=nx && nx<=h-1 && 0<=ny && ny<=w-1 && s[x.fi][x.se]!=s[nx][ny] && used[nx][ny]==0){
                        que.push({nx,ny});
                        used[nx][ny]=1;
                    }
                }
            }
            ans+=white*black;
        }
    }
    cout << ans << endl;
    return 0;
}

