#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define int long long
#define INF 1000000000000000000
using namespace std;

#define ANS(f) if(f) cout << "YES" << endl; else cout << "NO" << endl;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readv(vector<T> &a){ REP(i, a.size()) cin >> a[i]; }
void readi(vector<int> &a){ REP(i, a.size()){cin >> a[i]; a[i]--;} }
void debug(mat m){REP(i, m.size()){ REP(j, m[i].size()){ cout << m[i][j] << ","; } cout << endl; }}

int modpow(int x, int n, int m){
    int a = 1;
    IREP(i, 64){
        a = (a * a) % m;
        if(((n >> i) & 1) == 1) a = (a * x) % m;
    }
    return a;
}

class Combination
{
public:

    vec fact, invfact;
    int MAX_N, mod;

    Combination(int MAX_N, int mod): MAX_N(MAX_N), mod(mod) {
        initialize();
    }

    void initialize(){
        fact = vec(MAX_N + 1);
        invfact = vec(MAX_N + 1);
        fact[0] = 1;
        FOR(i, 1, MAX_N + 1){
            fact[i] = (fact[i - 1] * i) % mod;
        }
        invfact[MAX_N] = modpow(fact[MAX_N], mod - 2, mod);
        IREP(i, MAX_N){
            invfact[i] = (invfact[i + 1] * (i + 1)) % mod;
        }
    }

    int nCr(int n, int r){
        if(r > n || r < 0 || n < 0) return 0;
        if(n > MAX_N){
            MAX_N = n;
            initialize();
        }
        int a = fact[n];
        a = (a * invfact[r]) % mod;
        a = (a * invfact[n - r]) % mod;
        return a;
    }
};

signed main(){

    int K, N; cin >> K >> N;
    int mod = 998244353;
    Combination comb(N + K, mod);

    FOR(i, 2, 2 * K + 1){
        if(i % 2 == 1){
            int p = min(i, 2 * K + 2 - i) / 2;
            int ans = 0;
            REP(j, p + 1){
                int k = K - 2 * p + j;
                int n = N - j;
                ans += ((comb.nCr(n + k - 1, n) * modpow(2, j, mod)) % mod) * comb.nCr(p, j);
                ans %= mod;
            }
            cout << ans << endl;
        }else{
            int p = min(i, 2 * K + 2 - i) / 2 - 1;
            int ans = 0;
            REP(j, p + 1){
                int k = K - 1 - 2 * p + j;
                int n = N - j;
                ans += ((comb.nCr(n + k - 1, n) * modpow(2, j, mod)) % mod) * comb.nCr(p, j);
                ans %= mod;
                n = N - j - 1;
                ans += ((comb.nCr(n + k - 1, n) * modpow(2, j, mod)) % mod) * comb.nCr(p, j);
                ans %= mod;
            }
            cout << ans << endl;
        }
    }

    
    return 0;
}