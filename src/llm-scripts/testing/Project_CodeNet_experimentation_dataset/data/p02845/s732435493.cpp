#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
constexpr ll mod = 1e9+7;
int main(){
    ll N;
    cin >> N;
    vector<ll> A(N), num(N+1, 0);
    rep(i, 0, N) cin >> A[i];
    ll ans = 1;
    num[0] = 3;
    rep(i, 0, N){
        ans *= num[A[i]];
        num[A[i]]--;
        num[A[i]+1]++;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}