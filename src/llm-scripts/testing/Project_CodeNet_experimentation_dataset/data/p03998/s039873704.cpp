#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Pld = pair<ld, ld>;
using Vec = vector<ll>;
using VecP = vector<P>;
using VecB = vector<bool>;
using VecC = vector<char>;
using VecD = vector<ld>;
using VecS = vector<string>;
using Graph = vector<VecP>;
#define REP(i, m, n) for(ll (i) = (m); (i) < (n); ++(i))
#define REPR(i, m, n) for(ll (i) = (m); (i) > (n); --(i))
#define rep(i, n) REP(i, 0, n)
#define R cin>>
#define repr(i, n) REPR(i, n, 0)
#define all(s) (s).begin(), (s).end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define in(a) insert(a)
#define P(p) cout<<(p)<<endl;
#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()
#define SORT(a) sort((a).begin(), (a).end())
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long int> vll;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
void sonic(){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);}
void setp(const ll n){cout << fixed << setprecision(n);}
const ll INF = 1e9+1;
const ll LINF = 1e18+1;
const ll mod = 1e9+7;
//const ll MOD = 998244353;
const ld PI = acos(-1);
const ld EPS = 1e-11;
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}
template<typename T> void co(T e){cout << e << "\n";}
template<typename T> void co(const vector<T>& v){for(const auto& e : v)
    { cout << e << " "; } cout << "\n";}
ll gcd(ll a, ll b) {
    if (a < b)swap(a, b);
    if (b == 0) return a;
    unsigned r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}
ll lcm(ll a, ll b) {
    ll g = gcd(a, b);
    return a * b / g;
}
bool prime(ll n) {
    for (ll i = 2; i <= sqrt(n); i++) {
        if (n%i == 0)return false;
    }
    return n != 1;
}


int pow(int x, int y, int mod){
    int ret=1;
    for(;y;y>>=1,x=1ll*x*x%mod){
        if(y&1) ret=1ll*ret*x%mod;
    }
    return ret;
}


int n = 3010, maxn = 3000;
ll fac[3010], inv[3010];


void init(){
    fac[0]=1;
    REP(i, 1, maxn+1)fac[i]=1ll*fac[i-1]*i%mod;
    inv[maxn]=pow(fac[maxn], mod-2, mod);
    REPR(j,maxn-1,-1)inv[j]=1ll*inv[j+1]*(j+1)%mod;
}



int main() {
    sonic();
    map<char, string> mp;
    R mp['a'] >> mp['b'] >> mp['c'];
    char pre = 'a', nxt;
    while(mp[pre]!=""){
        nxt=mp[pre][0];
        mp[pre]=mp[pre].substr(1, mp[pre].length());
        pre=nxt;
    }
    pre-=32;
    co(pre);
}
