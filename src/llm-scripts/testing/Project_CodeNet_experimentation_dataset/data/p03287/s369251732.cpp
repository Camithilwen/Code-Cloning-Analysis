#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N, M; cin >> N >> M;
    vector<int> A(N);
    rep(i, N){
        cin >> A[i];
    }
    vector<int> R(N+1);
    R[0] = 0;
    rep(i, N){
        int r = A[i] + R[i];
        r %= M;
        R[i+1] = r;
    }

    map<ll, ll> m;
    rep(i, N+1){
        m[R[i]]++;
    }

    ll ans = 0;
    for (auto p : m){
        ll value = p.second;
        value = value * (value-1) / 2;
        ans += value;
    }

    cout << ans << endl;

    return 0;
}