#include <bits/stdc++.h>
using namespace std;
#define all(V) V.begin(),V.end()
using ll = long long;
const ll MOD = 1000000007;

ll A[520][520];

int main() {
	for (int i = 0;i < 520;i++) {
		for (int j = 0;j < 520;j++) {
			A[i][j] = -1;
		}
	}
	set<ll> S;
	priority_queue<ll> T;
	bool w;
	for (int i = 5;;i++) {
		w = 1;
		if (i % 2 == 0)continue;
		if (i % 3 == 0)continue;
		for (int x : S) {
			if (i % x == 0) {
				w = 0;
				break;
			}
		}
		if (w) {
			S.insert(i);
			if (i > 550)T.push(i);
			if (T.size() == 1200)break;
		}
	}
	for (int i = 1;i < 520;i += 2) {
		ll a = i, b = 1, c = T.top();T.pop();
		while (a < 520 && b < 520) {
			A[a][b] = c * (a + b);
			a++;b++;
		}
	}
	for (int i = 3;i < 520;i += 2) {
		ll a = 1, b = i, c = T.top();T.pop();
		while (a < 520 && b < 520) {
			A[a][b] = c * (a + b);
			a++;b++;
		}
	}

	for (int i = 5;i < 513;i++) {
		for (int j = 5;j < 513;j++) {
			if (A[i][j] >= 0)continue;
			A[i][j] = A[i - 1][j] * A[i + 1][j] + 1LL;
		}
	}

	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cout << A[i + 8][j + 8];
			if (j == N - 1)cout << "\n";
			else cout << " ";
		}
	}
}