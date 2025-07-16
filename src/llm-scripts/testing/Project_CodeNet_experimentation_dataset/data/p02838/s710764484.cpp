#include <iostream>
#include <vector>
using namespace std;
long long MOD = 1e9 + 7;
int main(){
    int N;
    cin >> N;
    vector<long long> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    vector<long long> cnt(60, 0);
    for(int i = 0; i < N; i++){
        int cn = 0;
        long long t = A[i];
        while(t > 0){
            if(t % 2 == 1) cnt[cn]++;
            cn++;
            t >>= 1;
        }
    }
    long long ans = 0;
    for(int i = 0; i < 60; i++){
        ans += (1LL << i) % MOD * cnt[i] % MOD * (N - cnt[i]) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}