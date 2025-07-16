#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"
#include "string"
#include "map"
#include "unordered_map"
#include "iomanip"
#include "random"

using namespace std;
const long long int MOD = 1000000007;

long long int power(long long int x, long long int n, long long int M) {
	long long int tmp = 1;

	if (n > 0) {
		tmp = power(x, n / 2, M);
		if (n % 2 == 0) tmp = (tmp*tmp) % M;
		else tmp = (((tmp*tmp) % M)*x) % M;
	}
	return tmp;
}

long long int N, M, K, Q, W, H, L, R;
long long int ans;



int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	while (N) {
		set<pair<long double, string> >s;
		for (int i = 0; i < N; i++) {
			string t;
			long double  p, a, b, c, d, e, f, n, m;
			cin >> t >> p >> a >> b >> c >> d >> e >> f >> n >> m;
			s.insert({ 1000-((f*n*m - p) / (a + b + c + d*m + e*m)) ,t });
		}
		for (auto i : s) {
			cout << i.second << endl;
		}
		cout << "#\n";
		cin >> N;
	}
	return 0;
}