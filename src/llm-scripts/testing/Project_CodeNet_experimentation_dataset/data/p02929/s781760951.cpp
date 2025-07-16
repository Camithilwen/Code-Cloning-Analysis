#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cfloat>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
#define int long long
#define ll long long
#define eps LDBL_EPSILON
#define mod (ll)1000000007
#define INF LLONG_MAX/10
#define P pair<int,int>
#define prique priority_queue
using namespace std;
int n;
string s;
bool b[200010];
signed main() {
	cin >> n >> s;
	if (s[0] == 'W' || s.back() == 'W') {
		cout << 0 << endl;
		return 0;
	}
	REP(i, 2 * n - 1) {
		if (s[i - 1] == s[i] && !b[i - 1])b[i] = true;
		if (s[i - 1] != s[i] && b[i - 1])b[i] = true;
	}
	if (!b[2 * n - 1]) {
		cout << 0 << endl;
		return 0;
	}
	int ans = 1, cnt = 0;
	rep(i, 2 * n) {
		if (b[i]) {
			ans *= cnt;
			ans %= mod;
			cnt--;
		}
		else cnt++;
	}
	if (cnt) {
		cout << 0 << endl;
		return 0;
	}
	REP(i, n) {
		ans *= i;
		ans %= mod;
	}
	cout << ans << endl;
}