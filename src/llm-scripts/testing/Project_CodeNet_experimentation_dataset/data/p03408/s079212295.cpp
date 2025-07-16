#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N, M;
	cin >> N;
	string s[N];
	rep(i,N) cin >> s[i];
	cin >> M;
	string t[M];
	rep(i,M) cin >> t[i];
	sort(s,s+N);
	int ans = 0;
	int u = 1;
	string c = s[0];
	for (int i=1; i<N; i++){
		if (s[i] == c) u++;
		else {
			int d = 0;
			rep(j,M) if (t[j] == c) d++;
			ans = max(ans, u-d);
			u = 1;
			c = s[i];
		}
		if (i == N-1) {
			int d = 0;
			rep(j,M) if (t[j] == c) d++;
			ans = max(ans, u-d);
		}
	}
	cout << ans << endl;

	return 0;
}
