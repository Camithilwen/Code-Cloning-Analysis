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
#include<unordered_map>
#include<unordered_set>
#include<random>
#include<bitset>
#include <queue>
#include <map>


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


ll frac[300000];


long long inverse(long long mod, long long val) {
	long long x[2] = { mod, val };
	long long a[2] = { 1, 0 };
	long long i;
	for (i = 0; x[!i]; i ^= 1) {
		a[!i] -= x[i] / x[!i] * a[i];
		x[i] = x[i] % x[!i];
	}
	if (!i) a[!i] += mod;
	return a[!i];
}

ll mod = 998244353;

ll mem[300000];

int main() {
	frac[0] = 1;
	mem[0] = 1;
	ll N, M, K;
	cin >> N >> M >> K;
	if (M == 1) {
		if (K == N - 1) PRI(1);
		else PRI(0);
		return 0;

	}
	REP(i, 1, 300000) {
		frac[i] = frac[i - 1] * i % mod;
		mem[i] = mem[i - 1] * (M - 1) % mod;
	}
	ll ret = 0;
	REP(i, 0, K + 1) {
		ll x = M * mem[N - i - 1] % mod;
		x *= frac[N - 1];
		x %= mod;
		x *= inverse(mod,frac[i]);
		x %= mod;
		x *= inverse(mod,frac[N - 1 - i]);
		x %= mod;
		ret += x;
		ret %= mod;
	}
	PRI(ret);
	return 0;
}


