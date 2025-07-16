#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    ll n;
    ll m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> sum(n+1);
    sum[0] = 0;
    map<ll, ll> mp;
    mp[0] = 1;
    rep(i, n) {
        sum[i+1] = (sum[i]+a[i]) % m;
        ++mp[sum[i+1]];
    }
    ll ans = 0;
    for ( auto p : mp ) {
        ans += p.second * (p.second - 1 ) / 2;
    }
    cout << ans << endl;
    return 0;
}
