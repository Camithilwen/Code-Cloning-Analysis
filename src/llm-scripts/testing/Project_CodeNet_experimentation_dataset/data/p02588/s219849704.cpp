#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define debug(var) do{cout << #var << " : "; view(var);}while(0)
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
template<class T> void view(T e) {cout << e << endl;}
template<class T> void view(const vector<T> &v) {for(const auto &e : v){cout << e << " ";} cout << endl;}
template<class T> void view(const vector<vector<T>> &vv) {for(const auto &v : vv){view(v);}}
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

const double eps = 1e-1;

int main() {
    int n; cin >> n;
    vll x;
    rep(i,n) {
        double f; cin >> f;
        f *= inf;
        ll l = ll(f+eps);
        x.push_back(l);
    }
    vvint data(50,vint(50,0));
    vector<P> ct;
    rep(i,n) {
        int ct_2 = 0, ct_5 = 0;
        while (x[i] % 2 == 0) {
            ct_2++;
            x[i] /= 2;
        }
        while (x[i] % 5 == 0) {
            ct_5++;
            x[i] /= 5;
        }
        data[ct_2][ct_5]++;
        ct.push_back(P(ct_2,ct_5));
    }
    rep(i,50)rep(j,50) {
        if (i != 0) data[i][j] += data[i-1][j];
        if (j != 0) data[i][j] += data[i][j-1];
        if (i != 0 && j != 0) data[i][j] -= data[i-1][j-1];
    }
    ll ans = 0;
    rep(i,n) {
        int ct_2 = max(0,18 - ct[i].first);
        int ct_5 = max(0,18 - ct[i].second);
        int tmp = data[49][49];
        if (ct_5 != 0) tmp -= data[49][ct_5-1];
        if (ct_2 != 0) tmp -= data[ct_2-1][49];
        if (ct_5 != 0 && ct_2 != 0) tmp += data[ct_2-1][ct_5-1];
        if (ct_2 <= ct[i].first && ct_5 <= ct[i].second) tmp--;
        ans += tmp;
    }
    ans /= 2;
    cout << ans << endl;
}