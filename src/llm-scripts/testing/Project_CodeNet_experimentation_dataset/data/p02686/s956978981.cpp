
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
using ldb = long double;


//BDD,ZDD,kdtree, bdtree,bicalc, bolonoy, doloney, tree, chinesemod,segmenttree,daikusutora, saidairyuu, 2bugurahu, heirokenshutu, topologicalsort, kyourenketuseibun

#define REP(i,a,b) for(ll i = a; i < b; ++i)
#define PRI(s) cout << s << endl
#define PRIF(v, n) printf("%."#n"f\n", v)
#define PRIY PRI("Yes")
#define PRIN PRI("No")
#define MINS(a,b) a = min(a,(decltype(a))(b))
#define MAXS(a,b) a = max(a,(decltype(a))(b))


using arr = array<ll, 3>;
int main() {
	auto proc = [](string str) {
		int bra = 0;
		int cket = 0;
		for (char c : str) {
			if (c == '(') {
				++bra;
			}
			else {
				if (bra > 0) --bra;
				else ++cket;
			}
		}
		return arr{cket, bra, bra - cket};
	};
	auto cmp = [](arr a, arr b) {
		if (a[0] == b[0])return a[1] > b[1];
		return a[0] < b[0];
	};
	auto cmp2 = [](arr a, arr b) {
		if (a[0] == b[0])return a[1] > b[1];
		return a[0] > b[0];
	};
	ll N;
	cin >> N;
	vector<arr> plus,minus;
	REP(i, 0, N) {
		string str;
		cin >> str;
		auto a = proc(str);
		if (a[2] >= 0) plus.push_back(a);
		else minus.push_back(a);
	}
	sort(plus.begin(), plus.end(), cmp);
	if (plus.size() == 0 || plus[0][0] > 0) {
		PRIN;
		return 0;
	}
	sort(minus.begin(), minus.end(), cmp2);
	int last = -1;
	REP(i, 0, minus.size()) {
		if (minus[i][1] == 0) {
			last = i;
			break;
		}
	}
	if (last == -1) {
		if (minus.size() != 0)PRIN;
		else {
			for (auto p : plus) {
				if (p[0] != 0 || p[1] != 0) {
					PRIN;
					return 0;
				}
			}
			PRIY;
		}
		return 0;
	}
	int cur = 0;
	for (auto p : plus) {
		cur -= p[0];
		if (cur < 0) {
			PRIN;
			return 0;
		}
		cur += p[1];
	}
	REP(i, 0, minus.size()) {
		if (i == last)continue;
		auto p = minus[i];
		cur -= p[0];
		if (cur < 0) {
			PRIN;
			return 0;
		}
		cur += p[1];
	}
	cur -= minus[last][0];
	if (cur == 0)PRIY;
	else PRIN;
	return 0;
}