#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1000000007;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef pair<ll,Pll> PlP;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    ll N;
    cin >> N;
    vector<ll> a(N), b(N), c(N), d(N);
    vector<Pll> p(N), q(N);
    rep(i,N){
        cin >> a[i] >> b[i];
        p[i] = Pll(a[i],b[i]);
    }
    rep(i,N){
        cin >> c[i] >> d[i];
        q[i] = Pll(c[i],d[i]);
    }
    sort(p.begin(),p.end());
    sort(q.begin(),q.end());
    vector<ll> memo(N);
    ll ans = 0;
    rep(i,N){
        ll Mb = -1;
        ll id = -1;
        rep(j,N){
            if(q[i].fi > p[j].fi && q[i].se > p[j].se && memo[j] == 0){
                if(Mb < p[j].se){
                    Mb = p[j].se;
                    id = j;
                }
            }
        }
        if(Mb != -1){
            memo[id] = 1;
            ans++;
        }
    }
    cout << ans << endl;
}