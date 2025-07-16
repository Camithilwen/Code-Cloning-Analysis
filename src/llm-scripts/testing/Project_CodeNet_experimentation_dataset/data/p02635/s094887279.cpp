#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll modpow(ll x, ll n){
    ll res = 1;
    ll mul = x;
    while(n){
        if(n % 2) res = res * mul % MOD;
        mul = mul * mul % MOD;
        n /= 2;
    }
    return res;
}

struct Combination
{
    int maxn;
    vector<ll> fmemo;
    vector<ll> imemo;
    vector<ll> ifmemo;
    
    Combination(int maxn) : maxn(maxn){
        fmemo.resize(maxn + 1);
        imemo.resize(maxn + 1);
        ifmemo.resize(maxn + 1);
        for(ll i = 1; i <= maxn; i++){
            imemo[i] = modpow(i, MOD - 2);
        }
    }

    ll fact(ll n){
        if(n == 0) return 1;
        if(fmemo[n]) return fmemo[n];
        return fmemo[n] = n * fact(n - 1) % MOD;
    }

    ll ifact(ll n){
        if(n == 0) return 1;
        if(ifmemo[n]) return ifmemo[n];
        return ifmemo[n] = imemo[n] * ifact(n - 1) % MOD;
    }

    ll com(ll n, ll k){
        if(k > n || k < 0) return 0;
        if(k == n || k == 0) return 1;
        return (fact(n) * ifact(k) % MOD) * ifact(n - k) % MOD;
    }
};

ll dp[305][305][305];

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int d[305];
    int m = 0;
    int c = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            d[m] = c;
            m++;
            c = 0;
        }
        else c++;
    }
    d[m] = c;
    m++;
    int b[305];
    b[m] = 0;
    for(int i = m - 1; i >= 0; i--) b[i] = b[i + 1] + d[i];
    int p;
    cin >> p;
    dp[m - 1][0][d[m - 1]] = 1;
    for(int i = m - 1; i > 0; i--){
        for(int j = 0; j <= min(p, b[i]); j++){
            for(int k = d[i - 1]; k <= b[i - 1]; k++){
                for(int l = max(d[i], k - d[i - 1]); l <= b[i - 1]; l++){
                    if(k - d[i - 1] < l - d[i]) dp[i - 1][j][k] = (dp[i - 1][j][k] + dp[i][j][l]) % MOD;
                    else dp[i - 1][j + (k - d[i - 1]) - (l - d[i])][k] = (dp[i - 1][j + (k - d[i - 1]) - (l - d[i])][k] + dp[i][j][l]) % MOD;
                }
            }
        }
    }
    ll ans = 0;
    for(int j = 0; j <= min(p, 300); j++){
        for(int k = 0; k <= 300; k++) ans = (ans + dp[0][j][k]) % MOD;
    }
    cout << ans << endl;
}
