/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}

ll msb(ll v){
    v = v | (v >> 1LL);
    v = v | (v >> 2LL);
    v = v | (v >> 4LL);
    v = v | (v >> 8LL);
    v = v | (v >> 16LL);
    v = v | (v >> 32LL);
    return v ^ (v >> 1LL);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll A[100010];
    rep(i,0,N) cin >> A[i];
    ll ans = 0;
    rep(d,0,60){
        ll cnt = 0;
        rep(i,0,N){
            if((A[i]>>d)&1) cnt++; 
        }
        if(cnt % 2 == 1){
            ans += (1LL<<d);
            rep(i,0,N){
                if((A[i]>>d)&1){
                    A[i] -= (1LL<<d);
                }
            }
        }
    }
    vector<ll> V;
    rep(i,0,N){
        for(auto &v: V) if(msb(v) & A[i]) A[i] ^= v;
        if(A[i] > 0){
            for(auto &v: V) if(msb(A[i]) & v) v ^= A[i];
            V.push_back(A[i]);
            sort(V.begin(), V.end(), greater<ll>());
        }
    }

    ll res = 0;
    for(auto &v: V) res ^= v;
    ans += res * 2;
    print(ans);


    

}