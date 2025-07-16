
// C - 2D Plane 2N Points

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

pair<int, int> red[100];
pair<int, int> blue[100];
bool used_red[100];

int main() {
	int N;
	cin >> N;

	for (int i=0; i<N; i++) {
		int a, b;
		cin >> a >> b;
		red[i] = make_pair(a, b);
	}

	for (int i=0; i<N; i++) {
		int c, d;
		cin >> c >> d;
		blue[i] = make_pair(c, d);
	}

	sort(blue, blue+N);

	int ans = 0;

	for (int i=0; i<N; i++) {
		int bx = blue[i].first;
		int by = blue[i].second;

		int max_ry = -1;
		int max_red_idx = -1;
		for (int j=0; j<N; j++) {
			int rx = red[j].first;
			int ry = red[j].second;

			if (rx < bx && ry < by && ry > max_ry && used_red[j] == false) {
				max_red_idx = j;
				max_ry = ry;
			}
		}

		if (max_red_idx != -1) {
			ans++;
			used_red[max_red_idx] = true;
		}
	}

	cout << ans << endl;

	return 0;
}