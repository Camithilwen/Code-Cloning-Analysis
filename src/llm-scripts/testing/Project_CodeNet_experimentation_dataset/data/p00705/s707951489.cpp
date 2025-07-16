#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	for (;;) {
		int N, Q; cin >> N >> Q;
		if (N == 0 && Q == 0) break;
		vector<int> a(100);
		while (N--) {
			int M; cin >> M;
			while (M--) {
				int i; cin >> i;
				a[i]++;
			}
		}
		int _i = 0; Q--;
		for (int i = 1; i < 100; i++)
			if (a[i] > Q) {
				_i = i;
				Q = a[i];
			}
		cout << _i << endl;
	}
}