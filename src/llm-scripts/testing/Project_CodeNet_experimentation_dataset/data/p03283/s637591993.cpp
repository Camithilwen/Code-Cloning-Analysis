#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using st=string;
using ch=char;
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vP;
typedef vector<ch> vc;
typedef vector<vc> vvc;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(ll i=a;i>=b;i--)
#define per(i,a) ROF(i,a,0)
#define pb push_back
#define mp make_pair
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld PI=acos(-1);
const ll INF=1e18;
st abc="abcdefghijklmnopqrstuvwxyz";
st ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

int main() {
    ll N,M,Q;
    cin >> N >> M >> Q;
    vvl cnt(N+1,vl(N+1,0));
    rep(i,M){
        ll L,R;
        cin >> L >> R;
        cnt[L][R]++;
    }
    FOR(i,0,N+1){
        FOR(j,1,N+1){
            cnt[i][j]+=cnt[i][j-1];
        }
    }
    FOR(i,1,N+1){
        FOR(j,0,N+1){
            cnt[i][j]+=cnt[i-1][j];
        }
    }
    rep(i,Q){
        ll p,q;
        cin >> p >> q;
        p--;
        cout << cnt[p][p]+cnt[q][q]-cnt[p][q]-cnt[q][p] << endl;
    }
}