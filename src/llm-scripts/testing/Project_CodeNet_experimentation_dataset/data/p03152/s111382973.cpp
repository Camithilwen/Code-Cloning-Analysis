#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <random>
#include <functional>
#include <stack>
#include <iomanip>
#include <cassert>
//#include <boost/multiprecision/cpp_int.hpp>
#include <complex>

using namespace std;
const long long MOD = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ll> pdl;
typedef pair<ld, ld> pdd;
//typedef boost::multiprecision::cpp_int bigint;
//0->決定
//1->xのみ決定
//2->yのみ決定
//3->x,yの範囲のみ決定
struct query {
	ll type;
	pll p1, p2;
};

ll H, W;
vector<ll> A, B;
vector<vector<pll>> DP;
vector<query> DP2;

int main() {
	cin >> H >> W;
	A.resize(H + 1);
	for (ll y = 1; y <= H; y++)cin >> A[y];
	sort(A.begin(), A.end(), [](ll a, ll b) {return a < b; });
	B.resize(W + 1);
	for (ll x = 1; x <= W; x++)cin >> B[x];
	sort(B.begin(), B.end(), [](ll a, ll b) {return a < b; });
	for (ll x = W; x > 1; x--) {
		if (B[x] == B[x - 1]) {
			cout << 0 << endl;
			return 0;
		}
	}
	for (ll y = H; y > 1; y--) {
		if (A[y] == A[y - 1]) {
			cout << 0 << endl;
			return 0;
		}
	}
	DP.resize(W * H + 1, vector<pll>(2, pll(0, 0)));
	DP2.resize(W * H + 1);
	ll xuse = W, yuse = H;
	for (ll p = W * H; p >= 1; p--) {
		if (A[yuse] == p && B[xuse] == p) {
			DP[p][0] = pll(xuse, yuse);
			DP[p][1] = pll(xuse, yuse);
			xuse--;
			yuse--;
			DP2[p] = { 0,pll(xuse,yuse),pll(-1,-1) };
		}
		else if (A[yuse] == p) {
			DP[p][0] = pll(xuse + 1, yuse);
			DP[p][1] = pll(W, yuse);
			DP2[p] = { 2,pll(xuse + 1, yuse),pll(W, yuse) };
			yuse--;
		}
		else if (B[xuse] == p) {
			DP[p][0] = pll(xuse, yuse + 1);
			DP[p][1] = pll(xuse, H);
			DP2[p] = { 1,pll(xuse, yuse + 1) ,pll(xuse, H) };
			xuse--;
		}
		else {
			DP[p][0] = pll(xuse+1, yuse+1);
			DP[p][1] = pll(W, H);
			DP2[p] = { 3,pll(xuse + 1, yuse + 1) ,pll(W, H) };
		}
	}
	ll ans = 1;
	for (ll p = W * H; p >= 1; p--) {
		if (DP[p][0] == DP[p][1])continue;
		else if (DP[p][0].second == DP[p][1].second) {
			ans = (ans * (DP[p][1].first - DP[p][0].first + 1)) % MOD;
		}
		else if (DP[p][0].first == DP[p][1].first) {
			ans = (ans * (DP[p][1].second - DP[p][0].second + 1)) % MOD;
		}
	}
	for (ll p = W * H; p >= 1; p--) {
		if (DP[p][0].first == DP[p][1].first ||
			DP[p][0].second == DP[p][1].second)continue;
		ans = (ans * ((W - DP[p][0].first+1) * (H - DP[p][0].second+1)-(W*H-p))) % MOD;
	}
	ans = 1;
	for (ll p = W * H; p >= 1; p--) {
		if (DP2[p].type == 0)continue;
		else if (DP2[p].type == 1) {
			ll left = DP2[p].p2.second - DP2[p].p1.second + 1;
			ans = (ans * left) % MOD;
		}
		else if (DP2[p].type == 2) {
			ll left = DP2[p].p2.first - DP2[p].p1.first + 1;
			ans = (ans * left) % MOD;
		}
		else {
			ll left = (W - DP[p][0].first + 1) * (H - DP[p][0].second + 1) - (W * H - p);
			ans = (ans * left) % MOD;
		}
	}
	cout << ans << endl;
	return 0;
}