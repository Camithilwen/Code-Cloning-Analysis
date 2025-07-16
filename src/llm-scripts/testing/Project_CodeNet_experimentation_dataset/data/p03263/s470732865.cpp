#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	int H, W;
	cin >> H >> W;
	int a[H][W];
	for(int i = 0; i < H; i++)
		for(int j = 0; j < W; j++) cin >> a[i][j];

	vector<tuple<int, int, int, int>> v;
	for(int i = 0; i < H; i++) {
		for(int j = 0; j < W; j++) {
			if(a[i][j] % 2 == 0) continue;
			if(i == H - 1 && j == W - 1) continue;

			if(j == W - 1) {
				v.push_back(make_tuple(i + 1, j + 1, i + 2, j + 1));
				a[i + 1][j]++;
			} else {
				v.push_back(make_tuple(i + 1, j + 1, i + 1, j + 2));
				a[i][j + 1]++;
			}
		}
	}

	cout << v.size() << "\n";
	for(int i = 0; i < v.size(); i++) cout << get<0>(v[i]) << " " << get<1>(v[i]) << " " << get<2>(v[i]) << " " << get<3>(v[i]) << "\n";
	return 0;
}