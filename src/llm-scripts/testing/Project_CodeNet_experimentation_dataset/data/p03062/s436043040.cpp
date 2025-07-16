#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll n;
    cin >> n;
    vector<ll> a(n, 0), b(n, 0);
    ll sum = 0, count = 0;
    bool zero = false;
    rep1(i, n){
        cin >> a[i];
        sum += abs(a[i]);
        b[i] = abs(a[i]);
        if (a[i]<0) count++;
        if (a[i]==0) zero = true;
    }
    ll ans;
    sort(b.begin(), b.end());
    if (count%2==0 || zero) ans = sum;
    else ans = sum - 2*b[0];
    cout << ans << endl;
    //printf("%.12f", ans);
}