#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<pi, pi> pp;
typedef pair<ll, ll> pl;
double PI = 3.1415926535897932;
const double EPS = 1e-9;
const ll MOD = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 60;

int n, m;
ll k;
int x[100000];
int d[100000];
int D[100000];
int to[100000];
int a[100000];
int tmp[100000];
bool saw[100000];

int main() {
    cin >> n;
    rep(i,n) cin >> x[i];
    rep(i,n-1) d[i] = x[i+1]-x[i];
    rep(i,n-1) to[i] = i;
    cin >> m >> k;
    rep(i,m) cin >> a[i];
    rep(i,m) a[i]--;
    rep(j,m) {
        swap(to[a[j]-1], to[a[j]]);
    }
    rep(i,n-1) {
        if (saw[i]) continue;
        int p = i;
        int si = 0;
        saw[p] = true;
        tmp[si++] = p;
        while (!saw[to[p]]) {
            saw[to[p]] = true;
            p = to[p];
            tmp[si++] = p;
        }
        rep(j,si) {
            D[tmp[j]] = d[tmp[(j+k)%si]];
        }
    }

    ll pos = x[0];
    cout << pos << endl;
    rep(i,n-1) {
        pos += D[i];
        cout << pos << endl;
    }
}