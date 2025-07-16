#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, a, b) for(ll i = a; i < b; i++)
#define out(x) std::cout << x << '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define sz(x) ((int)(x).size())
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g * b; }
const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INF = INT_MAX / 2;
const ll  inf = LLONG_MAX / 2;
const int mod = 1000000007;
const int MAX_N = 101010;
const long double PI = acos(-1);

vector<int> eratos(int max_n) {
	vector<int> is_prime(max_n, 1);
	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i < max_n; i++) {
		if (!is_prime[i]) continue;
		for (int j = i * 2; j < max_n; j += i) {
			is_prime[j] = 0;
		}
	}
	return is_prime;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	/*------------------------------*/

	int n;
	cin >> n;

	vector<int> prime = eratos(55555);
	vector<int> ans;
	for (int i = 0; i < sz(prime); i++)
	{
		if (prime[i]) {
			if (i % 10 == 1) {
				ans.push_back(i);
			}
		}
	}
	
	rep(i, n) {
		cout << ans[i] << " ";
	}
	cout << endl;

	return 0;
}