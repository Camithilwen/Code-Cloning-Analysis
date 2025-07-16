#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1'000'000'007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)
#define repd(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=b-1; (ll)(a)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


class FactorialMod{
    void calc_inverse(){
        inverse[0] = 0;
        inverse[1] = 1;
        for(int i=2; i<=max_num; i++){
            inverse[i] = md-((md/i)*inverse[md%i]%md);
        }
    }

    void calc_factorial_inverse(){
        factorial[0] = factorial_inverse[0] = 1;
        for (int i=1; i<=max_num; i++) {
            factorial[i] = (factorial[i-1]*i)%md;
            factorial_inverse[i] = (factorial_inverse[i-1]*inverse[i])%md;
        }
    }

    public:
        ll max_num, md;
        vector<ll> inverse; 
        vector<ll> factorial;
        vector<ll> factorial_inverse;
        FactorialMod(ll _max_num, ll _md=MOD){
            max_num = _max_num;
            md = _md;
            inverse = vector<ll>(max_num+1);
            factorial = vector<ll>(max_num+1);
            factorial_inverse = vector<ll>(max_num+1);
            calc_inverse();
            calc_factorial_inverse();
        }

        ll combination(int n, int k){
            return (((factorial[n]*factorial_inverse[k])%md)*factorial_inverse[n-k])%md;
        }

        ll multiChoose(int n, int k){
            return combination(n+k-1, k);
        }
};

ll modpow(ll x, ll n, ll md=MOD){
    ll res=1, dig=x;
    while(n){
        if(n&1) res = res*dig%md;
        dig = dig*dig%md;
        n /= 2;
    }
    return res;
}
ll comb(ll N_, ll C_, ll mo) {
	const int NUM_=400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}
int main(){
    ll n, m, k; cin >> n >> m >> k;
    //重複組み合わせは配列倍(n+k)にする
    ll mod = 998244353, res=0;
    FactorialMod calc_mod(n, mod);
    rep(i, k+1){
        res += m*calc_mod.combination(n-1, i)%mod*modpow(m-1, n-1-i, mod)%mod;
        res %= mod;
    }   
    cout << res << endl; 
    

}