#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define ld long double
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
// const ll INF = 1LL << 30;
#define pp pair<ll, pair<ll, ll>> 
#define fi first
#define se second

void print(Vl vec){
    rep(i, 0, sz(vec)){
        if(i) cout << " ";
        cout << vec[i];
    }
    coel;
}

////////////////////////////////////////////////////////


int main() {
    ll d, g; cin >> d >> g;
    Vl p(d), c(d);
    rep(i, 0, d) cin >> p[i] >> c[i];
    ll ans = INF;
    for(int tmp = 0; tmp < (1 << d); tmp++){
        bitset<12> s(tmp);
        vector<bool> f(d, false);
        ll sum = 0;
        ll cnt = 0;
        rep(i, 0, 10){
            if(s.test(i)){
                f[i] = true;
                sum += p[i]*(i+1)*100 + c[i];
                cnt += p[i];
            }
        }
        if(sum >= g){
            chmin(ans, cnt);
            continue;
        }
        for(int i = d-1; i >= 0; i--){
            if(f[i]) continue;
            bool h = false;
            rep(j, 0, p[i]){
                sum += (i+1)*100;
                cnt ++;
                if(sum >= g){ 
                    h = true; 
                    chmin(ans, cnt);
                    break;
                }
            }
            if(h) break;
        }
    }
    co(ans);

    return 0;
}

