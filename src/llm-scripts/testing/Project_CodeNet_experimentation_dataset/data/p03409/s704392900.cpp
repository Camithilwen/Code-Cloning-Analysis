#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    ll N;
    cin >> N;
    vector<ll> a(N), b(N), c(N), d(N);
    vector<Pll> R(N), B(N);
    rep(i,N){
        cin >> a[i] >> b[i];
        //a[i];
        //b[i];
        R[i] = Pll(a[i], b[i]);
    }
    vector<vector<ll>> note(2*N+100,vector<ll>(2*N+100));
    rep(i,N){
        cin >> c[i] >> d[i];
        //c[i]++;
        //d[i]++;
        B[i] = Pll(c[i], d[i]);
        /*rep(j,c[i]){
            rep(k,d[i]){
                note[j][k]++;
            }
        }*/
    }
    sort(R.begin(), R.end());
    sort(B.begin(), B.end());
    vector<ll> memo(N*2+100);
    ll ans = 0;
    rep(i,N){
        ll cc = B[i].fi;
        ll dd = B[i].se;
        ll id = -1;
        ll score = -1e18;
        rep(j,N){
            if(memo[j]) continue;
            ll aa = R[j].fi;
            ll bb = R[j].se;
            if(aa < cc && bb < dd){
                if(bb >= score){
                //if(score > note[aa][bb]){
                //    score = note[aa][bb];
                    id = j;
                    score = bb;
                }
                //}
            }
        }
        if(id != -1){
            memo[id] = 1;
            ans++;
        }
        /*
        rep(j,cc){
            rep(k,dd){
                note[j][k]--;
            }
        }*/
    }
    cout << ans << endl;
}