#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N), B(N), S(N);
    rep(i, 0, N){
        cin >> A[i] >> B[i];
        S[i] = A[i] + B[i];
    }
    sort(S.begin(), S.end(), greater<ll>());
    ll taka = 0;
    rep(i, 0, N){
        if(i % 2 == 0) taka += S[i];
    }
    
    ll ans = taka - accumulate(B.begin(), B.end(), 0LL);
    cout << ans << endl;
    return 0;
}