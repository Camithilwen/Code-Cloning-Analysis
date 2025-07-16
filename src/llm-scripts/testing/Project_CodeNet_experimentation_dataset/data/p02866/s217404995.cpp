#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
typedef long long ll;
const ll MOD=998244353;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T>auto MAX(const T& a) { return *max_element(a.begin(),a.end()); }
template<class T>auto MIN(const T& a) { return *min_element(a.begin(),a.end()); }
template<class T, class U>U SUM(const T& a, const U& v) { return accumulate(a.begin(),a.end(), v); }
template<class T, class U>U COUNT(const T& a, const U& v) { return count(a.begin(),a.end(), v); }
template<class T, class U>int LOWER(const T& a, const U& v) { return lower_bound(a.begin(),a.end(), v) - a.begin(); }
template<class T, class U>int UPPER(const T& a, const U& v) { return upper_bound(a.begin(),a.end(), v) - a.begin(); }
int GCD(int a, int b) { return b ? GCD(b, a%b) : a; }
int LCM(int a, int b) { int g = GCD(a, b); return a / g * b; }
//---------------------------------------------------------------------------------------------------

int main(void){
    // Your code here!
    vector<int> d;
    int n;cin >> n;
    d.resize(n);
    vector<int> v(n,0);
    rep(i,n) {
        cin >> d[i];
        v[d[i]]++;
    }
    if (d[0] != 0) {
        cout << 0 << endl;
        return 0;
    }
    rep(i,n) {
        if(i != 0 && d[i] ==0) {
            cout << 0 << endl;
            return 0;
        }
    }

    ll ans = 1;
    int ma = 0;
    rep(i,n) chmax(ma,d[i]);

    FOR(i,2,ma) {
        ll ex = v[i-1];
        rep(j,v[i]) {
            ans *= ex;
            ans %= MOD;
        }
    }
    cout << ans << endl;
}

