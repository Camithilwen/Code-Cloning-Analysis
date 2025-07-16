#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define prt(v) cout<<(v)<<"\n";
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
#define endl "\n"
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;

//dp[i][j]はそれぞれiグラム、jグラム買うときの最小価格
vector<vector<ll>> dp(500, vector<ll>(500, INF));

signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll A;
    cin >> A;
    ll B;
    cin >> B;
    vector<ll> X(N,0);
    for(ll i=0;i<N;++i)cin>>X[i];
    ll ans=0;
    for(ll i=1;i<N;++i){
        ans+=min(A*(X[i]-X[i-1]),B);
    }
    prt(ans)

    return 0;
}
