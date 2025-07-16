#include <iostream>
#include <string>
#include <algorithm>
#include <utility> 
#include <unordered_set>
#include <vector>
#include <list> 
#include <string>
#include <iterator> 
#include <deque>
#include <array>
#include <forward_list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <climits>
#include <bitset>
#include <numeric>
using namespace std;


const long double PI = 3.14159265358979323846264338327950;
const int N = 1e5+5;

template <class T>
T gcd(T a, T b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int ac[N], wa[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k;
	int a, b;
	string s;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> k >> s;
		if (s[0] == 'W' && ac[k] == 0) {
			wa[k]++;
		} else {
			ac[k]++;
		}
	}

	a = b = 0;
	for (int i = 0; i <= n; ++i) {
		if (ac[i]) {
			++a;
			if (wa[i]) b += wa[i];
		}
	}

	cout << a << ' ' << b << '\n';
}
		