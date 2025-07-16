#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<ll, ll>;
/* ちゃんと考えてわかって実装 */

int main(void){
    ll n, k;
    cin >> n >> k;

    vector<ll> x;
    for(int i=0; i<n; i++){
        int tmpx; cin >> tmpx;
        x.push_back(tmpx);
    }

    ll ans = 1e19;
    for(int l=0; l<=n-k; l++){
        int r = l+k-1;
        ll tmp_ans = min(abs(x[l])+abs(x[l]-x[r]), abs(x[r])+abs(x[l]-x[r]));
        ans = min(ans, tmp_ans);
    }

    cout << ans << endl;
    return 0;
}