#include <bits/stdc++.h>
using namespace std;

int	main()
{
	int	N, M, Q;
	cin >> N >> M >> Q;
	vector<vector<int>>	cnt_vec(N + 1, vector<int>(N + 1, 0));
	int	L, R;
	for (int i = 0; i < M; ++i) {
		cin >> L >> R;
		cnt_vec.at(L).at(R) += 1;
	}
	vector<vector<int>>	cumsum(N + 1, vector<int>(N + 1, 0));
	for (int i = N; i > 0; --i) {
		for (int j = 1; j <= N; ++j) {
			cumsum.at(i).at(j) = cnt_vec.at(i).at(j);
			cumsum.at(i).at(j) += cumsum.at(i).at(j - 1);
			if (i < N) {
				cumsum.at(i).at(j) += cumsum.at(i + 1).at(j);
				cumsum.at(i).at(j) -= cumsum.at(i + 1).at(j - 1);
			}
		}
	}
	int	p, q;
	for (int i = 0; i < Q; ++i) {
		cin >> p >> q;
		cout << cumsum.at(p).at(q)  << endl;
	}
}
