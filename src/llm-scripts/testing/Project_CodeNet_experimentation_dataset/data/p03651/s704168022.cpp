#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL LLONG_MAX // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    Init();
    ll n, k; cin >> n >> k;
    vi a(n);
    bool possible = false;
    ll gcdNum = -1;
    rep(i, n){
        cin >> a[i];
        if(a[i] == k) possible = true;
        if(i == 0) gcdNum = a[i];
        else gcdNum = __gcd(gcdNum, a[i]);
    }
    sort(all(a));
    if(a[n-1] >= k && !possible){
        ll sub = k-a[n-1];
        if(sub%gcdNum == 0) possible = true;     
    }
    cout << (possible ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}