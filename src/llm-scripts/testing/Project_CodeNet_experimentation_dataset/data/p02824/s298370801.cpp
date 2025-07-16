#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)
#define pcnt __builtin_popcountll
#define rng(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define v(T) vector<T>
#define vv(T) v(v(T))

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

template<typename T>inline istream& operator>>(istream&i,v(T)&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T1,typename T2>inline istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false; }

ll INF = 1001001001;
ll LINF = 1001001001001001001ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M, v, p;
    cin>>N>>M>>v>>p;
    vl as(N);
    cin>>as;
    sort(rng(as));
    reverse(rng(as));

    ll mi = N;
    rep(i, N) if (as[i] + M < as[p - 1]) {
        mi = i;
        break;
    }
    ll l = p - 1;
    ll r = mi;
    while (l + 1 < r) {
        ll m = (l + r) / 2;
        ll s = 0;
        s += M * (p - 1 + N - m);
        for (int i = p - 1; i < m; ++i) {
            s += as[m] + M - as[i];
        }
        if (s >= M * v) l = m;
        else r = m;
    }
    cout<<l + 1<<endl;
}
