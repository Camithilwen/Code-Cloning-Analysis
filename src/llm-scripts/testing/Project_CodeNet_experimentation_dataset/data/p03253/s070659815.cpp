#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////////
const long long int INF = 1LL<<60;
const long long int Mod = 1000000007;
using ll = long long int; using ci = const int;
using vi = vector<int>;  using Vi = vector<long long int>;
using P = pair<int, int>;  using PLL = pair<ll, ll>;
using matrix = vector<vector<ll>>;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define rp(i,N) for(ll i = 0; i < (ll)N; i++)
#define repi(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
template<class T>bool chmax(T &former, const T &b) { if (former<b) { former=b; return true; } return false; }
template<class T>bool chmin(T &former, const T &b) { if (b<former) { former=b; return true; } return false; }
template<class T>T sqar(T x){ return x*x; }//sqrt(x)は平方根;
#define Sort(v) std::sort(v.begin(), v.end(), std::greater<decltype(v[0])>()) //降順でVをソート
#define p_queue(v) priority_queue<v, vector<v>, greater<v> >
template<class T> inline void princ(T x){cout<<x<<" ";}; 
template<class T> inline void print(T x){cout<<x<<"\n";};
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
///////////////////////////////////////////////////////////////////////////////////

ll pow(ll x,ll y,ll mod){
    if(y==0) return 1;
    if(y&1) return x*pow(x,y-1,mod)%mod;
    ll p=pow(x,y/2,mod);
    return p*p%mod;
}

ll com(ll x,ll y,ll mod){
    ll res=1;
    rp(i,y) {
        res *= x-i;
        res %= mod;
    }
    rp(i,y){
        res *= pow(i+1,mod-2,mod);
        res %= mod;
    }
    return res;
}
int main(){
    int n,m;
    cin >> n >> m;
    vi p_count;
    for(int i=2; i*i<=m; i++){
        int ctr=0;
        while(m%i==0){
            m /= i;
            ctr++;
        }
        if(ctr) p_count.pb(ctr);
    }
    if(m!=1) p_count.pb(1);
    int ps=p_count.size();
    ll ans=1;
    for(auto p:p_count){
        ans *= com((ll)p+(ll)n-1ll,(ll)(n-1),Mod);
        ans %= Mod;
    }
    print(ans);
    return 0;
}