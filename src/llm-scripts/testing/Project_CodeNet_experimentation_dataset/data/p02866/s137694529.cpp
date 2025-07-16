#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;

ll modpow(ll a, ll p, ll M){
    ll ret = 1;
    while(p){
    if(p & 1) ret = ret * a % M;
    a = a * a % M;
    p >>= 1;
    }
    return ret;
}

int main() {
    ll N, M;
    M = 998244353;
    cin >> N;
    vector<ll> D(N);
    rep(i, N) cin >> D[i];

    vector<ll> num(N,0);
    rep(i,N) num[D[i]]++;
    ll ans = 1;
    for(int i = 1; i < N; i++){
        ans *= modpow(num[i-1], num[i],M);
        ans %= M;
    }
    if(num[0] != 1 || D[0] != 0) ans = 0;
    cout << ans << endl;

}