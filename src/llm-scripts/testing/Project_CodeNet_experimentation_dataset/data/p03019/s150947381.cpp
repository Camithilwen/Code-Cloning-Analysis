#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using vp = vector<pll>;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repb(i, n) for (int i = (n-1); i >= 0; i--)
#define rea(i, a, b) for (int i = (a); i < (b); i++)
#define reab(i, a, b) for (int i = (a)-1; i >= (b); i--)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((int)(x).size())
#define PRINT(V) for (auto v:(V)) {cerr << v << " ";} cerr << endl
#define dump(x) cerr << #x << " : " << (x) << endl
#define dump2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define dump3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")" << endl
inline ll GCD(ll a, ll b){return b ? GCD(b, a % b) : a;}
const ll MOD = 1000000007;
const ll INF = 100000000000000000;
/* END OF TEMPLATE */

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    ll n, x;
    cin >> n >> x;
    vll b(n), l(n), u(n);
    rep(i, n){
        cin >> b[i] >> l[i] >> u[i];
    }
    vector<tuple<ll, ll, ll, ll>> vt;
    ll val = 0;
    rep(i, n){
        vt.emplace_back(b[i]*l[i]+(x-b[i])*u[i], u[i], l[i], b[i]);
        val -= l[i]*b[i];
    }
    sort(vt.rbegin(), vt.rend());
    vll acc;
    acc.emplace_back(0);
    rep(i, n){
        acc.emplace_back(*acc.rbegin()+get<0>(vt[i]));
    }
    // ans : 0 ~ nx
    
    // binary search
    // https://qiita.com/drken/items/97e37dd6143e33a64c8c
    ll bsl = -1;
    ll bsr = n*x;
    while(bsr - bsl > 1){
        // dump2(bsl, bsr);
        ll mid = bsl + (bsr - bsl) / 2;
        ll q = mid / x;
        ll r = mid % x;
        ll m = 0;
        rep(i, q){
            ll mt;
            if(r > get<3>(vt[i])){
                mt = get<2>(vt[i])*get<3>(vt[i]) + get<1>(vt[i])*(r-get<3>(vt[i]));
            }else{
                mt = get<2>(vt[i])*r;
            }
            // dump(mt);
            m = max(m, acc[q+1] - get<0>(vt[i]) + mt);
        }
        rea(i, q, n){
            ll mt;
            if(r > get<3>(vt[i])){
                mt = get<2>(vt[i])*get<3>(vt[i]) + get<1>(vt[i])*(r-get<3>(vt[i]));
            }else{
                mt = get<2>(vt[i])*r;
            }
            // dump(mt);
            m = max(m, acc[q] + mt);
        }
        if(m + val >= 0){
            bsr = mid;
        }else{
            bsl = mid;
        }
    }
    cout << bsr << endl;
}