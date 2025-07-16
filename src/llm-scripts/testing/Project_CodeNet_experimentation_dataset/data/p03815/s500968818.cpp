#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    ll x; cin >> x;
    ll nokori = x % 11;
    ll ans = (x-nokori) / 11;
    ans *= 2;
    if(nokori > 6){
        ans += 2;
    } else if(nokori > 0) {
        ans++;
    }

    cout << ans << endl;

    return 0;
}