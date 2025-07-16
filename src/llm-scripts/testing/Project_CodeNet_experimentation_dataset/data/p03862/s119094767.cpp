#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
    ll N,x;
    cin>>N>>x;
    vector<ll> v(N);
    for(ll i = 0; i < N; i++) cin>>v[i];
    ll ans = 0;
    if(v[0]>x){
        ans+=v[0]-x;
        v[0]=x;
    }
    for(ll i = 0; i < N-1; i++){
        if(v[i]+v[i+1]>x){
            ll t = x-v[i];
            ans+=v[i+1]-t;
            v[i+1]=t;
        }
    }
    cout<<ans<<endl;
}