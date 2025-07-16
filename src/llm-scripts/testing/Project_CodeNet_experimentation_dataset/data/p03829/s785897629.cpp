#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    ll N, A, B;
    cin >> N >> A >> B;
    
    vec<ll> X(N);
    rep(i, N) cin >> X[i];

    ll ans = 0;
    ll now = X[0];
    for(int i=1;i<N;++i){
        ans+=min(A*(X[i]-now),B);
        now=X[i];
    }
    cout << ans << '\n';
}
