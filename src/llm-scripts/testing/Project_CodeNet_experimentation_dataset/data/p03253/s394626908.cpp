#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;


#define rep(i,n) for(ll (i)=0; (i)<(ll)(n); (i)++)
#define frep(i,m,n) for(ll (i)=(m); (i)<=(ll)(n); (i)++)
#define rrep(i,n) for(ll (i)=(n)-1; (i)>-1; (i)--)
#define frrep(i,m,n) for(ll (i)=(n); (i)>(ll)(m); (i)--)
#define ALL(x) (x).begin(), (x).end()

const ll INF = 100100100100100100;
const ll MOD = 1000000007;

// get abs
ll my_abs(ll a);
// a^n
ll a_n(ll a, ll n);
// get gcd
ll my_gcd(ll a, ll b);
// a^(-1) % MOD 
ll inv(ll a);
// (a+b+c)%MOD
ll madd(ll a, ll b, ll c);
// (a-b)%MOD
ll msub(ll a, ll b);
// (a*b*c)%MOD
ll mtime(ll a, ll b, ll c);

// map of result of factorization
void factorization(ll n, map<ll, ll> &a) {
    while((n%2) == 0) {
        n /= 2;
        if(a.count(2)) a.at(2)++;
        else a[2] = 1;
    }
    for(ll i = 3; i*i <= n; i+=2) {
        while((n%i) == 0) {
            n /= i;
            if(a.count(i)) a.at(i)++;
            else a[i] = 1;
        }
    }
    if(n != 1) a[n] = 1;
}

void factorial_map(vector<ll> &n, vector<ll> &ninv);

int main() {
    ll n, m;
    cin >> n >> m;
    map<ll, ll> a;
    vector<ll> nfac(101010), ninv(101010);
    factorial_map(nfac, ninv);
    factorization(m, a);
    ll ans = 1;
    
    for(auto p: a) {
        auto v = p.second;
        ll comb = mtime(nfac[v+n-1], ninv[v], ninv[n-1]);
        ans = mtime(ans, comb, 1);
    }

    cout << ans << endl;
    
    return 0;
}

ll my_abs(ll a) {
    if(a >= 0) return a;
    else return -1 *a;
}

ll a_n(ll a, ll n) { 
    if(n == 0) return 1;
    
    ll ret = a, count = 1;
    while(count * 2 < n) {
        ret *= ret;
        ret %= MOD;
        count *= 2;
    }
    if(count == n) return ret;
    else return (ret * a_n(a, n-count))%MOD;
}

ll my_gcd(ll a, ll b) {
    if(b == 0) return a;
    return my_gcd(b, a%b);
}

ll inv(ll a) {
    return a_n(a, MOD-2);
}

ll madd(ll a, ll b, ll c) {
    ll ret = (a+b) % MOD;
    return (ret+c) % MOD;
}

ll msub(ll a, ll b) {
    if(a < b) return (a-b+MOD) % MOD;
    else return (a-b) % MOD;
}

ll mtime(ll a, ll b, ll c) {
    ll ret = (a*b) % MOD;
    return (ret*c) % MOD;
}

void factorial_map(vector<ll> &n, vector<ll> &ninv) {
    n[0] = 1;
    for(ll i = 1; i < n.size(); i++) n[i] = (n[i-1] * i) % MOD;
    ninv[n.size()-1] = inv(n[n.size()-1]);
    for(ll i = n.size() - 2; i > -1; i--) ninv[i] = (ninv[i+1] * (i+1)) % MOD;
}
