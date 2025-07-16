//khodaya khodet komak kon
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")


using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1000000 + 10;
const ll MOD = 1000000000 + 7;
const ll INF = 1000000010;
const ll LOG = 25;

int n, Ans;
char S[N], T[N];
int bias, que[N], head, tail;

int main() {
	cin >> n;
	for (int i = 1; i <= n;i++) cin >> S[i];
	for (int i = 1; i <= n; i++) cin >> T[i];
	int ok = 1;
	for (int i = 1; i <= n; ++i) if (S[i] != T[i]) ok = 0;
	if (ok) return cout << 0, 0;
	head = 1, tail = 0;
	for (int i = n, j = n; i >= 1; --i) {
		if (j > i) j = i;
		while (head <= tail && que[head] + bias > i) ++head;
		Ans = std::max(Ans, tail - head + 2);
		if (i == 1 || T[i - 1] != T[i]) {
			while (j && S[j] != T[i]) --j;
			if (!j) return cout << -1, 0;
			--bias;
			que[++tail] = j - bias;
			--j;
		}
	}
	cout << Ans;
	return 0;
}
