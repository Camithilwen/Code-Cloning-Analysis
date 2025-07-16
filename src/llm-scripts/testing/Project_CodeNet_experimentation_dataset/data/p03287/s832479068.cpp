#include<bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
using Graph = vector<vector<int>>;

ll N,M;
vector<ll> A;

int main(){
    cin>>N>>M;
    A.resize(N);
    rep(i,N)cin>>A[i];
    vector<ll> V(N);
    V[0] = A[0]%M;
    rep1(i,N-1)V[i] = (V[i-1] + A[i])%M;
    sort(V.begin(),V.end());
    map<ll,ll> r;;;;
    rep(i,N) r[V[i]]++;
    ll res = 0;
    for(auto p:r){
        ll amari = p.first;
        ll cnt = p.second;
        if(amari==0){
            res += cnt;
            res += cnt*(cnt-1)/2;
        }else{
            res += cnt*(cnt-1)/2;
        }
    }
    cout<<res<<endl;
}
