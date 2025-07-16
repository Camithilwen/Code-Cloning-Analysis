#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    if(S[0] == 'W' || S[2 * N - 1] == 'W') {
        cout << 0 << endl;
        return 0;
    }
    
    vector<bool> f(2 * N);
    f[0] = true;
    for(int i=1; i<2*N; ++i) {
        if(S[i - 1] != S[i]) f[i] = f[i - 1];
        else f[i] = !f[i - 1];
    }

    if(count(begin(f), end(f), true) != N) {
        cout << 0 << endl;
        return 0;
    }

    long long MOD = 1000000007;
    long long res = 1;
    for(int i=1; i<=N; ++i) res = (res * i) % MOD;
    
    int cnt = 0;
    for(int i=0; i<2*N; ++i) {
        if(f[i]) {
            ++cnt;
        } else {
            res = (res * cnt) % MOD;
            --cnt;
        }
    }
    cout << res << endl;
}