#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)
#define pcnt __builtin_popcountll
#define rng(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define v(T) vector<T>
#define vv(T) v(v(T))
#define fi first
#define se second

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

    ll n;
    cin>>n;
    vl as(n);
    cin>>as;

    if (n == 1) {
        if (as[0]) cout<<-1<<endl;
        else cout<<0<<endl;
        return 0;
    }

    ll ans = as.back();
    for (int i = n - 2; i >= 0; --i) {
        if (as[i] > i) {
            cout<<-1<<endl;
            return 0;
        }
        if (as[i] + 1 < as[i + 1]) {
            cout<<-1<<endl;
            return 0;
        }
        if (as[i] + 1 == as[i + 1]) continue;
        ans += as[i];
    }
    cout<<ans<<endl;
}