#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(long long i=0;i<(long long)(n);i++)
#define rep2(i, s, n) for(long long i=(s);i<(long long)(n);i++)
#define repi(i, n) for(int i=0;i<(int)(n);i++)
#define rep2i(i, s, n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define chmax(s, t) s=max(s,t);
#define chmin(s, t) s=min(s,t); 

#define deg2rad(deg) (((deg)/360)*2*M_PI)
#define rad2deg(rad) (((rad)/2/M_PI)*360)

using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vvll = vector<vll>;
using P = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;

const ll INF = (1LL<<60);
const int INFi = (1<<29);

/*素数判定*/
bool is_prime(ll n){
    if(n==1) return false;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

/*約数列挙*/
vll enum_divisors(ll n){
    vll l;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            l.push_back(i);
            if(n/i != i) l.push_back(n/i);
        }
    }
   sort(all(l));
   return l;
}

/*素因数分解*/
vector<P> prime_factorize(ll n){
    vector<P> l;
    for(ll i=2;i*i<=n;i++){
        if(n%i!=0) continue;
        ll e = 0;
        while(n%i==0){
            e++;
            n /= i;
        }
        l.push_back({i, e});
    }
    if(n!=1) l.push_back({n, 1});
    return l;
}

/*最小公倍数*/
ll lcm(ll a, ll b){
    return a*b/__gcd(a,b);
}

/*最大公約数*/
ll gcd(ll a, ll b){
    return __gcd(a,b);
}

/*組み合わせ(Combination)*/
const ll CMAX = 1010000;
const ll CMOD = 1e9+7;
ll fac[CMAX], finv[CMAX], inv[CMAX];
// テーブルを作る前処理
void combinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (ll i = 2; i < CMAX; i++) {
		fac[i] = fac[i - 1] * i % CMOD;
		inv[i] = CMOD - inv[CMOD%i] * (CMOD / i) % CMOD;
		finv[i] = finv[i - 1] * inv[i] % CMOD;
	}
}
// 二項係数計算
ll comb(ll n, ll k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % CMOD) % CMOD;
}

/*階乗*/
ll factorial(ll n){
    const ll FMOD = 1e9+7;
    ll ret = n;
    for(ll i=n-1;i>0;i--){
        ret*=i;
        ret%=FMOD;
    }
    return (ret?ret:1);
}


int main(){

    ll n; cin >> n;
    ll absmin = INF;
    ll ans = 0;
    ll minuscnt = 0;
    rep(i, n){
        ll in; cin >> in;
        chmin(absmin, abs(in));
        if(in<0) minuscnt++;
        ans += abs(in);
    }

    cout << (minuscnt%2==0?ans:ans-2*absmin) << endl;

    return 0;
}