#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef vector<double> Vec;
typedef vector<Vec> Mat;
typedef pair<ll,ll> P;
typedef pair<double,ll> Pd;
typedef pair<double,double> PD;
typedef priority_queue<P,vector<P>,greater<P> > P_queue;
typedef priority_queue<Pd,vector<Pd>,greater<Pd> > Pd_queue;

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e15;
const double DEL=1e-6;

#define _GLIBCXX_DEBUG
#define REP(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end())


void Add(ll &a, ll b){
    a=(a+b)%mod;
    return;
}

void Pro(ll &a, ll b){
    a=(a*b)%mod;
    return;
}

ll H,W; 
vector<P> d;

vec ans;
void init(){
    cin>>H>>W;
    rep(i,H){
        ll x,y; cin>>x>>y;
        x--; y--;
        d.pb(mp(x,y));
        ans.pb(-1);
    }
}

void Solve(){
    set<P> x;
    multiset<ll> y;
    rep(i,W) {
        P f=mp(i,i);
        x.insert(f);
        y.insert(0);
    }
    rep(i,H){
        ll Biggest=-INF;
        for(auto itr=x.lower_bound(mp(d[i].first,-INF));itr!=x.end();){
            ll R=(*itr).first, L=(*itr).second;
           // cout<<i<<':'<<R<<' '<<L<<endl;
            if(R>d[i].second+1) break;
            Biggest=max(Biggest,L);
            auto itr1=y.lower_bound(R-L);
            y.erase(itr1);
            itr=x.erase(itr);
        }
        if(Biggest!=-INF) if(d[i].second!=W-1) {x.insert(mp(d[i].second+1,Biggest)); y.insert(d[i].second+1-Biggest);}
        if(y.size()) ans[i]=*(y.begin());
        else break;
    }
    rep(i,H) if(ans[i]>=0) ans[i]+=(i+1);
    
}

int main(){
    init();
    Solve();
    rep(i,H) cout<<ans[i]<<endl;
}


