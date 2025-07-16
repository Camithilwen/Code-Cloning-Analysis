#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N, M, L, R;
	cin >> N >> M;

	int a, b;
	a = 0;
	b = N;

	for (int i = 0; i < M; i++) {
		cin >> L >> R;
		a = max(a, L);
		b = min(b, R);
	}

	int ret = b - a;
	if (ret < 0) ret = 0;
	else ret++;

	cout << ret << endl;
}