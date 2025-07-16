#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5 , MOD = 1e9 + 7;
long long fact[N] , fact_inv[N];

int mul(long long a , long long b) {
    return a * b % MOD;
}

long long power(long long a , long long b) {
    if (!b) return 1;
    long long r = power(a , b / 2);
    r = mul(r , r);
    if (b&1) return mul(r , a);
    return r;
}

long long mod_inv(long long x) {
    return power(x , MOD - 2);
}

long long nCr(long long n , long long r){
    if (!n) return !r;
    if(r>n) return  0;
    return mul(fact[n] , mul(fact_inv[n - r] , fact_inv[r]));
}

void pre() {
    fact[0] = fact_inv[0] = 1;
    for(int i = 1 ; i < N ;i++) {
        fact[i] = mul(fact[i - 1] , i);
        fact_inv[i] = mod_inv(fact[i]);
    }
}

int add (int a , int b) {
    a += b;
    while (a >= MOD) a -= MOD;
    while (a < 0) a += MOD;
    return a;
}

int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n , m , k;
    cin >> n >> m >> k;

    pre();

    int ans = 0;
    for (int i = 1 ;i <= n ;i++) {
        int ways = n - i + 1;
        ways = mul(ways , mul(m , m - (i == 1)));
        ways = mul(ways , nCr(n * 1ll * m - 2 , k - 2));
        ans = add(ans , mul(ways , i - 1));
    }

    for (int i = 1 ;i <= m ;i++) {
        int ways = m - i + 1;
        ways = mul(ways , mul(n , n - (i == 1)));
        ways = mul(ways , nCr(n * 1ll * m - 2 , k - 2));
        ans = add(ans , mul(ways , i - 1));
    }

    cout << ans;
}