#include<iostream>
#include<cstdlib>
#include<utility>
#include<tuple>
#include<string>
#include<vector>
#include<numeric>
#include<algorithm>
#include<queue>
#include<deque>
#include<bitset>
#include<cmath>
#include<map>
#include<iomanip>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
#define rep(i, a, b) for(ll i = a; i < b; i++)

int main() {

	ll n;
	cin >> n;
	string ans;
	
	while (n) {
		--n;
		ans += (char)('a' + (n % 26));
		n /= 26;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;

	return 0;
}