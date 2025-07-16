#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    ll a[n], b[n], c[n];
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    for(int i=0; i<n; i++) cin >> c[i];

    sort(a, a+n);
    sort(b, b+n);
    sort(c, c+n);

    ll ans = 0;

    for(ll i=0; i<n; i++){
        ll u = upper_bound(a, a+n, b[i]-1) - a;
        ll l = lower_bound(c, c+n, b[i]+1) - c;

        ans += u * (n-l);
    }
    cout << ans << endl;

}