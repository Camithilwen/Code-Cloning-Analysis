#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll n, y;
ll count(ll mon){
    ll cnt = y / mon;
    y %= mon;
    return cnt;
}

int main() {
    cin >> n >> y;
    vector<ll> a(3, 0);
    a[2] = count(10000);
    a[1] = count(5000);
    a[0] = count(1000);
    ll d = n - (a[0]+a[1]+a[2]);
    if (d<0){
        cout << -1 << " " << -1 << " " << -1 << endl;
        return 0;
    }
    ll val = min(a[2], d/9);
    a[0] += val*10;
    a[2] -= val;
    d -= val*9;
    val = min(a[1], d/4);
    a[0] += val*5;
    a[1] -= val;
    d -= val*4;
    val = min(a[2], d);
    a[1] += val*2;
    a[2] -= val;
    d -= val;
    if (d!=0){
        cout << -1 << " " << -1 << " " << -1 << endl;
        return 0;
    }
    cout << a[2] << " " << a[1] << " " << a[0] << endl;
    //printf("%.12f", ans);
}
