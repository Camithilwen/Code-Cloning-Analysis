#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdint.h>
#include<vector>
#include<deque>
#include<stack>
#include<functional>
#include<string>
#include<cstring>
#include<time.h>
#include<array>
#include<iomanip>
#include<list>
#include<set>
#include<map>
#include<random>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
#include <queue>


using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ldouble = long double;


//BDD,ZDD,kdtree, bdtree,bicalc, bolonoy, doloney, tree, chinesemod,segmenttree,daikusutora, saidairyuu, 2bugurahu, heirokenshutu, topologicalsort, kyourenketuseibun

#define REP(i,a,b) for(int i = a; i < b; ++i)
#define PRI(s) cout << s << endl
#define PRIY PRI("Yes")
#define PRIN PRI("No")

using b = bitset<6400 * 2 + 64>;


int main() {
	ll H, W;
	vector<vector<b>> f;
	vector<vector<ll>> a, b;
	cin >> H >> W;
	f.resize(H);
	a.resize(H);
	b.resize(H);
	REP(i, 0, H) {
		f[i].resize(W);
		a[i].resize(W);
		REP(j, 0, W) {
			f[i][j].reset();
			cin >> a[i][j];
		}
	}
	REP(i, 0, H) {
		b[i].resize(W);
		REP(j, 0, W) {
			cin >> b[i][j];
		}
	}
	int i0 = 6400;
	f[0][0][i0 + b[0][0] - a[0][0]] = true;
	f[0][0][i0 - b[0][0] + a[0][0]] = true;
	auto bs = [](auto& b, int d) {
		if (d >= 0) return b << d;
		else return b >> -d;
	};
	REP(j, 1, W) f[0][j] = bs(f[0][j - 1], b[0][j] - a[0][j]) | bs(f[0][j - 1], -b[0][j] + a[0][j]);
	REP(i, 1, H) f[i][0] = bs(f[i - 1][0], b[i][0] - a[i][0]) | bs(f[i - 1][0], -b[i][0] + a[i][0]);
	REP(i, 1, H)REP(j, 1, W) {
		f[i][j] = bs(f[i][j - 1], b[i][j] - a[i][j]) | bs(f[i - 1][j], b[i][j] - a[i][j]);
		f[i][j] |= bs(f[i][j - 1], -b[i][j] + a[i][j]) | bs(f[i - 1][j], -b[i][j] + a[i][j]);
	}
	for (int i = 0; i <= 6400; ++i) {
		if (f[H - 1][W - 1][i0 + i] || f[H - 1][W - 1][i0 - i]) {
			PRI(i);
			return 0;
		}
	}
	return 0;
}


