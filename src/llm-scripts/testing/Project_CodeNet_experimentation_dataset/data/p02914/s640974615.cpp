#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const ll mod = 1e9 + 7;
const int maxn = 1e5+5;
vector<int>tar;
ll v[maxn];
ll b[65];
void ins(ll x) {
    for (int i = 0 ; i < tar.size() ; i++) {
        if (x & (1LL<<(tar[i]))) {
            if (b[i]) {
                x ^= b[i];
            }
            else {
                b[i] = x;
                break;
            }
        }
    }
}
void go() {
    int n;
    cin >> n;
    ll sum = 0;
    f1(n) {
        cin >> v[i];
        sum ^= v[i];
    }
    for (int i = 60 ; i >= 0 ; i--) {
        if (sum & (1LL<<i)) {

        }
        else {
            tar.pb(i);
        }
    }
    f1(n) {
        ins(v[i]);
    }
    ll ans = 0;
    for (int i = 0 ; i < tar.size() ; i++) {
        if (b[i] && !(ans & (1LL<<tar[i]))) {
            ans ^= b[i];
        }
    }
    cout << ans + (sum ^ ans) << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 0;
    int t;
    if (!c) {
        t = 1;
    }
    else {
        cin >> t;
    }
    while (t--) {
        go();
    }
}
