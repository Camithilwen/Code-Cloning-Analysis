#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> p;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    ll x;
    cin >> N >> x;

    vector<ll> a(N);

    for(int i = 0; i < N; i++) cin >> a[i];

    ll ans = 0;

    for(int i = 1; i < N; i++) {
        if(a[i] + a[i - 1] <= x) continue;
        if(a[i - 1] <= x) {
            ans += a[i] + a[i - 1] - x;
            a[i] -= a[i] + a[i - 1] - x;
            //cerr << "a " << a[i - 1] << " " << a[i] << endl;
        } else {
            ans += a[i];
            a[i] = 0;
            ans += a[i - 1] - x;
            a[i - 1] = x;
            //cerr << "b " << a[i - 1] << " " << a[i] << endl;
        }
    }

    cout << ans << endl;
}