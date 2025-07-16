#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define P pair<ll, ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr ll mod = 1000000007;
constexpr ll INF = (1ll << 60);
constexpr double pi = 3.14159265358979323846;
template <typename T>
inline bool chmax(T &a, T b){if (a < b){a = b;return 1;}return 0;}
template <typename T>
inline bool chmin(T &a, T b){if (a > b){a = b;return 1;}return 0;}

int main(){
    ll n,m,x,y;cin>>n>>m>>x>>y;
    bool yes=true;
    vector<ll> x_vec(n),y_vec(m);
    rep(i,n) cin>>x_vec[i];
    rep(i,m) cin>>y_vec[i];

    for(ll z=-100;z<=100;z++){
        bool Yes=false;
        if(!(x<z && z<=y)) Yes=true;
        rep(i,n) if(!(x_vec[i]<z)) Yes=true;
        rep(i,m) if(!(y_vec[i]>=z)) Yes=true;

        if(!Yes){
            yes=false;
            break;
        }
    }

    if(yes) cout<<"War"<<endl;
    else cout<<"No War"<<endl;
    return 0;
}