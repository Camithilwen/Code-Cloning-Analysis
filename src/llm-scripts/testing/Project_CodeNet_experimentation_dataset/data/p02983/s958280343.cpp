#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<functional>
#include<math.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pf(n) printf("%d\n",n)
#define pff(a,b) printf("%d  %d\n",a,b);
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1001001001;
const double PI = acos(-1);

int main() {
	ll l, r;
	cin >> l >> r;

	ll ans = 1001001;
	if (r - l >= 2019) {
		ans = 0;
	}
	else {
		for (ll i = l; i < r; i++) {
			for (ll j = i + 1; j <= r; j++) {
				ans = min(ans, (i*j) % 2019);
			}
		}
	}
	cout << ans << endl;

	return 0;
}