#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
void setIO(string name = "c") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int main() {
    //setIO();
    ll n, m; cin >> n >> m;
    vector <ll> v (n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll ans = max(v[0], m) - m; v[0] -= max(v[0], m) - m;
    for (int i = 0; i < n - 1; i++) {
        ans += max(v[i] + v[i + 1], m) - m;
        v[i + 1] -= max(v[i] + v[i + 1], m) - m;
    }
    cout << ans << "\n";
}