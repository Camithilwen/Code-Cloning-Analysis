#include <bits/stdc++.h>

using namespace std;

int N,a[500010],s[500010];
vector<int>pos[1<<20];
int sum0[500010];
const int MOD = 1e9 + 7;

int main() {
	scanf("%d",&N);
	for (int i=1;i<=N;i++) {
		scanf("%d",&a[i]);
		s[i] = s[i - 1] ^ a[i];
		pos[s[i]].push_back(i);
		sum0[i] = sum0[i - 1] + (s[i] == 0);
	}
	if (s[N] != 0) {
		int X = s[N];
		int s0 = 1, s1 = 0;
		for (int i=1;i<=N;i++) {
			if (s[i] == X) {
				int F = s0;
				s1 = (s1 + F) % MOD;
				if (i == N) {
					printf("%d\n",F);
					return 0;
				}
			} else if (s[i] == 0) {
				int F = s1;
				s0 = (s0 + F) % MOD;
			}
		}
	}
	int ans = 0;
	int p2 = 1;
	for (int i=1;i<=sum0[N-1];i++) {
		p2 = p2 * 2 % MOD;
	}
	ans = p2;
	for (int v=1;v<(1<<20);v++) {
		if (pos[v].size() == 0) {
			continue;
		}
		if (pos[v].size() == 1) {
			ans++;
			continue;
		}
		int lastF = 1, s0 = 1, s1 = 1;
		for (int i=1;i<pos[v].size();i++) {
			int bz = sum0[pos[v][i]] - sum0[pos[v][i-1]];
			s0 = (1LL * bz * s1 + s0) % MOD;
			int F = s0;
			s1 = (s1 + F) % MOD;
		}
		ans = (ans + s1) % MOD;
	}
	printf("%d\n",ans);
}