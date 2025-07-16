#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define P pair<ll, ll>
#define Graph vector<vector<P>>
#define fi first
#define se second
constexpr ll mod = 1000000007;
constexpr ll INF = (1ll << 60);
constexpr double pi = 3.14159265358979323846;
template <typename T>inline bool chmax(T &a, T b){if (a < b){a = b;return 1;}return 0;}
template <typename T>inline bool chmin(T &a, T b){if (a > b){a = b;return 1;}return 0;}

int main(){
    ll n;cin>>n;
    map<ll,ll> a;

    rep(i,n){
        ll p;cin>>p;
        if(a.find(p)==a.end()) a[p]=1;
        else a[p]++;
    }
    
    ll ans=1;
    priority_queue<ll> que;
    que.push(0);
    que.push(0);
    for(auto itr=a.begin();itr!=a.end();itr++){
        rep(i,itr->second/2) que.push(itr->first);
    }

    ans*=que.top();
    que.pop();
    ans*=que.top();

    cout<<ans<<endl;
    return 0;
}