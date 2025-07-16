#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;


int main(){
    ll N, M, Q; cin >> N >> M >> Q;
    vector<vector<ll>> D(N+1, vector<ll>(N+1));
    for(int i = 0; i < M; i++){
        ll l, r; cin >> l >> r; D[l][r]++;
    }
    for(int i = 0; i < N+1; i++){
        for(int j = 0; j < N; j++) D[i][j+1] += D[i][j];
    }

    while(Q--){
        ll p, q; cin >> p >> q;
        ll cnt = 0;
        for(;p <= q; p++){
            cnt += D[p][q];
        }
        cout << cnt << endl;
    }

}
