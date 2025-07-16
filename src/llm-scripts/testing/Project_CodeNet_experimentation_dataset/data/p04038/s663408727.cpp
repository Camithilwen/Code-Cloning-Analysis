#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const int MAX_N = 2005;

ll sil[MAX_N * MAX_N], odw[MAX_N * MAX_N], DP[MAX_N][MAX_N];

ll pot(ll a, ll b) {
    ll result = 1;

    while(b > 0) {
        if(b % 2 == 1) {
            result = (result * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }

    return result;
}

ll binom(int n, int k) {
    ll result = sil[n];
    result = (result * odw[k]) % MOD;
    result = (result * odw[n - k]) % MOD;
    return result;
}

int main() {
    sil[0] = 1;
    for(int i = 1; i < MAX_N * MAX_N; i++) {
        sil[i] = (sil[i - 1] * i) % MOD;
    }
    odw[MAX_N * MAX_N - 1] = pot(sil[MAX_N * MAX_N - 1], MOD - 2);
    for(int i = MAX_N * MAX_N - 2; i >= 1; i--) {
        odw[i] = (odw[i + 1] * ll(i + 1)) % MOD;
    }
    odw[0] = odw[1];

    int n, k;
    
    cin >> n >> k;
    
    if(k == 1) {
        cout << 1;
        return 0;
    }
    
    for(int i = 0; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            if(i == 0) {
                if(j == 0) {
                    DP[i][j] = 1;
                } else {
                    DP[i][j] = (DP[i][j - 1] * binom(j * (k - 1) - 1, k - 2)) % MOD;
                }
                continue;
            }
            DP[i][j] = DP[i - 1][j];
            if(j > i) {
                DP[i][j] += DP[i][j - 1] * binom(j * (k - 1) + i - 1, k - 2);
                DP[i][j] %= MOD;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        DP[n][n] = (DP[n][n] * i) % MOD;
    }
    
    cout << DP[n][n];
    
    return 0;
}
