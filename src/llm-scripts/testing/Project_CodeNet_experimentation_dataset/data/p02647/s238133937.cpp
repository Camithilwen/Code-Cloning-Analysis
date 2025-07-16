#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = LLONG_MAX;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;



int main(){
    ll N, K; cin >> N >> K;
    vector<ll> A(N+1);
    for(int i = 0; i < N; i++) cin >> A[i];
    while(K--){
        vector<ll> A_(N+1);
        for(int i = 0; i < N; i++){
            ll l = i-A[i], r = i + A[i];
            l = max(l, 0LL), r = min(r, N-1);
            A_[l]++;
            A_[r+1]--;
        }
        ll t = 0;
        bool flag = true;
        for(int i = 0; i < N; i++) {
            t += A_[i];
            A[i] = t;
            if(flag && A[i] != N) flag = false;
        }
        if(flag) break;
    }
    for(int i = 0; i < N; i++) cout << A[i] << " "; cout << endl;
}
