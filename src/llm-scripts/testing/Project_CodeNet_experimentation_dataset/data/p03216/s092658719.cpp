#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <functional>
#include <cctype>
#include <list>
#include <limits>
#include <cassert>
#include <random>
#include <time.h>
#include <unordered_set>
//#include <boost/multiprecision/cpp_int.hpp>



using namespace std;
using Int = long long;
//using namespace boost::multiprecision;

const double EPS = 1e-10;
long long const MOD = 998244353;

long long mod_pow(long long x, long long n) {
    long long res = 1;
    for (int i = 0;i < 60; i++) {
        if (n >> i & 1) res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}

template<typename T>
T gcd(T a, T b) {
    return b != 0 ? gcd(b, a % b) : a;
}

template<typename T>
T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

void fastInput() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

const int MAXN = 1100010;
long long fact[MAXN], inv[MAXN];

void initComb() {
    fact[0] = 1;
    for (int i=1; i<MAXN; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }

    inv[MAXN - 1] = mod_pow(fact[MAXN - 1], MOD-2);
    for (int i=MAXN - 2; i>=0; i--) {
        inv[i] = (inv[i+1] * (i+1)) % MOD;
    }
}

long long comb(int n, int r) {
    if (n < r) return 0;
    if (n < 0 || r < 0) return 0;
    return fact[n] * inv[n-r] % MOD * inv[r] % MOD;
}

Int imos_D[1000005];
Int imos_C[1000005];
Int imos_M[1000005];
Int dp[1000005][5];

int main(void) {
    int N; cin >> N;
    string S; cin >> S;
    int Q; cin >> Q;

    for (int i = 0; i < N; i++) {
        if (S[i] == 'D') imos_D[i+1] = 1;
        else imos_D[i+1] = 0;
        imos_D[i+1] += imos_D[i];

        if (S[i] == 'C') imos_C[i+1] = 1;
        else imos_C[i+1] = 0;
        imos_C[i+1] += imos_C[i];

        if (S[i] == 'M') imos_M[i+1] = 1;
        else imos_M[i+1] = 0;
        imos_M[i+1] += imos_M[i];
    }

    for (int i = 0; i < Q; i++) {
        int K; cin >> K;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int j = 0; j < N; j++) {
            dp[j+1][0] = dp[j][0];
            dp[j+1][1] = dp[j][1];
            dp[j+1][2] = dp[j][2];
            dp[j+1][3] = dp[j][3];
            dp[j+1][4] = dp[j][4];
            if (S[j] == 'D') {
                dp[j+1][1] += dp[j][0];
            }
            if (S[j] == 'M') {
                dp[j+1][2] += dp[j][1];
            }
            if (S[j] == 'C') {
                dp[j+1][3] += dp[j][2];
            }

            if (S[j] == 'C') {
                if (j+1-K >= 0) {
                    Int NumOfM = imos_M[j+1] - imos_M[j+1-K];
                    dp[j+1][4] += dp[j][2] - NumOfM * dp[j+1-K][1] - dp[j+1-K][2]; 
                } else {
                    dp[j+1][4] += dp[j][2];
                }
            }
            // cout << NumOfM << endl;
        }
        Int U = dp[N][3];
        cout << dp[N][4] << endl;
    }
}