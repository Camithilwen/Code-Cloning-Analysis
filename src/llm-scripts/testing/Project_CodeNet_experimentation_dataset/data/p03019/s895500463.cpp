#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;

int main(){
    ll N, X;
    cin >> N >> X;
    ll b[N], l[N], u[N];
    rep(i, N) cin >> b[i] >> l[i] >> u[i];
    ll S = 0;
    rep(i, N) S += b[i]*l[i];
    pli p[N];
    rep(i, N) p[i] = pli(b[i]*l[i]+(X-b[i])*u[i], i);
    sort(p, p+N, greater<pli>());
    ll ans = INF;
    ll sum[N+1];
    sum[0] = 0;
    rep(i, N) sum[i+1] = sum[i] + p[i].first;
    rep(i, N){
        ll s = p[i].first;
        int j = p[i].second;
        if(sum[i] < S){
            ll k = lower_bound(sum, sum+N+1, S)-sum;
            ll rem = S-(sum[k]-s);
            ll n;
            if(rem <= b[j]*l[j]) n = (rem+l[j]-1)/l[j];
            else n = b[j]+(rem-b[j]*l[j]+u[j]-1)/u[j];
            ans = min(ans, (k-1)*X+n);
        }
        else{
            ll k = lower_bound(sum, sum+N+1, S-s)-sum;
            ll rem = S-sum[k];
            ll n;
            if(rem < 0) n = 0;
            elif(rem <= b[j]*l[j]) n = (rem+l[j]-1)/l[j];
            else n = b[j]+(rem-b[j]*l[j]+u[j]-1)/u[j];
            ans = min(ans, k*X+n);
        }
    }
    cout << ans << endl;
}