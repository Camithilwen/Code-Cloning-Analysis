#include"bits/stdc++.h"

#define rep(i, N) for(int i = 0;i < N;i++)

typedef long long ll;

const int mod = 1e9 + 7;

using namespace std;



int main(void) {
	int N, Q; cin >> N >> Q;
	string S; cin >> S;
	vector<int> l(Q), r(Q);
	rep(i, Q) {
		cin >> l[i] >> r[i];
		l[i]--;
		r[i]--;
	}

	rep(i, S.size()-1) {
		if (S[i] == 'A' && S[i + 1] == 'C') {
			S[i] = '@';
		}
	}

	vector<int> sum(S.size(), 0);
	sum[0] = (int)(S[0] == '@');
	for(int i = 1;i < S.size();i++) {
		sum[i] = sum[i - 1];
		sum[i] += (int)(S[i] == '@');
	}

	rep(q, Q) {
		int ans = sum[r[q]-1] - sum[l[q]];
		ans += (int)(S[l[q]] == '@');
		cout << ans << endl;
	}

	return 0;
}