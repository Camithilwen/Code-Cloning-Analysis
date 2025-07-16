#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL N, M; cin >> N >> M;
		vector<vector<UL>> E(N);
		rep(i, M) {
			UL a, b; cin >> a >> b; a--; b--;
			E[a].push_back(b);
			E[b].push_back(a);
		}
		vector<int> F(N);
		ULL z, b, u; z = b = u = 0;
		rep(s, N) {
			if (F[s]) continue;
			F[s] = s + 1;
			if (E[s].size() == 0) {
				z++; F[s] = s + 1; continue;
			}
			queue<UL> Q; Q.push(s);
			bool bok = true;
			while (Q.size()) {
				UL p = Q.front(); Q.pop();
				for (UL e : E[p]) {
					if (F[p] == F[e]) bok = false;
					if (F[e] == 0) {
						F[e] = -F[p];
						Q.push(e);
					}
				}
			}
			if (bok) b++; else u++;
		}
		ULL ans = 0;
		ans += (z * N * 2 - z * z);
		ans += ((b + u) * (b + u) + b * b);
		cout << ans << endl;
	}


	Problem();
};
int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}
Problem::Problem() {
	cout << fixed << setprecision(10);
}
