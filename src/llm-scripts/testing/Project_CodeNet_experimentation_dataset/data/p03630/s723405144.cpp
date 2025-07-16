
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <complex>
#include <cstdint>
#include <tuple>
#include <numeric>
#define M_PI       3.14159265358979323846


using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define FILL(a, x) memset(a, x, sizeof(a))

//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)

const int N = 2005;
char board[N][N];
int val[N][N];

class UnionFind {
public:
	vector<int> data;
	UnionFind(int n) : data(n, -1) {}
	int find(int x) {
		if (data[x] < 0)return x;
		return data[x] = find(data[x]);
	}
	bool unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y)return false;
		if (data[x] > data[y])swap(x, y);
		data[x] += data[y];
		data[y] = x;
		return true;
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	int size(int x) {
		return -data[find(x)];
	}
};

int main() {
	int h, w;
	scanf("%d%d", &h, &w);
	REP(i, h)scanf("%s", board[i]);
	REP(i, w)val[0][i] = w - i;
	FOR(i, 1, h) {
		val[i][w - 1] = 1;
		bool same = (board[i - 1][w - 1] == board[i][w - 1]);
		for (int j = w - 2; j >= 0; j--) {
			if (same ^ (board[i - 1][j] == board[i][j])) {
				val[i][j] = 1;
				same = !same;
			}
			else val[i][j] = val[i][j + 1] + 1;
		}
	}
	int ans = max(h, w);
	REP(j, w) {
		UnionFind uf(h);
		vector<PII> vpii(h - 1);
		FOR(i, 1, h)vpii[i - 1] = MP(val[i][j], i);
		sort(ALL(vpii), greater<PII>());
		REP(i, h - 1) {
			if (uf.unite(vpii[i].second - 1, vpii[i].second)) {
				ans = max(ans, uf.size(vpii[i].second) * vpii[i].first);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}