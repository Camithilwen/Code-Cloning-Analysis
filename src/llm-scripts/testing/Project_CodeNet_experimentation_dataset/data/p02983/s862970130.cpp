#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define forin(in) for(int i=0; i<(int)in.size(); i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

int main() {
    ll L, R;
    cin >> L >> R;
    if (R - L >= 2050) cout << 0 << endl;
    else {
        ll ans = 2018;
        for (ll i = L; i < R; i++)
            for (ll j = i + 1; j <= R; j++) {
                ans = min(ans, (i * j) % 2019);
            }
        cout << ans << endl;
    }
}