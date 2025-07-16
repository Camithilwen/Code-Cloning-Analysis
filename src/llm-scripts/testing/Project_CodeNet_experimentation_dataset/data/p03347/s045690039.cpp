#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N), B(N), C(N);
    rep(i,N){
        cin >> A[i];
    }
    rep(i,N){
        if(A[i] > i){
            cout << -1 << endl;
            return 0;
        } 
    }
    rep(i,N-1){
        if(A[i+1] - A[i] > 1){
            cout << -1 << endl;
            return 0;
        }
    }
    map<ll,ll> mp;
    rep(i,N){
        B[i] = i-A[i];
        mp[B[i]] = A[i];
    }
    rep(i,N-1){
        if(B[i+1] < B[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    ll ans = 0;
    for(auto& e:mp){
        ans += e.second;
    }
    cout << ans
     << endl;
}