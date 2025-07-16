#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<climits>
#include<map>
#include<string>
#include<functional>
#include<iomanip>
#include<deque>
#include<random>
#include<set>
#include<bitset>
#include<cassert>

using namespace std;
typedef long long ll;
typedef double lldo;
#define mp make_pair
#define pub push_back
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define chmax(x,y) x = max(x,y)
ll gcd(ll a, ll b) { if (a % b == 0) { return b; } else  return gcd(b, a % b); }
ll lcm(ll a, ll b) { if (a == 0) { return b; }return a / gcd(a, b) * b; }
template<class T>ll LBI(vector<T>& ar, T in) { return lower_bound(ar.begin(), ar.end(), in) - ar.begin(); }
template<class T>ll UBI(vector<T>& ar, T in) { return upper_bound(ar.begin(), ar.end(), in) - ar.begin(); }

ll n, a[200005] = {}, b[200005] = {}, j = 0, bef = -1;

int main() {
	cin >> n;
	rep(i, n)cin >> a[i];
	rep(i, n)cin >> b[i];
	rep(i, n) {
		if (bef != a[i])j = 0;
		if (a[i] == b[i]) {
			while ((a[i] == a[j] || a[i] == b[j]) && j < n)j++;
			if (j < n) {
				swap(b[i], b[j]);
			}
			else {
				cout << "No" << endl;
				return 0;
			}
		}
		bef = a[i];
	}
	cout << "Yes" << endl;
	rep(i, n)cout << b[i] << endl;
	return 0;
}