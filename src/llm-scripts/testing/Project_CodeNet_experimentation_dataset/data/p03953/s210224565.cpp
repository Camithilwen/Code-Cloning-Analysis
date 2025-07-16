#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<long long int>v(N);
	for (auto &i : v)cin >> i;
	cin >> M >> K;
	vector<int>p(N - 1);
	for (int i = 0; i < N - 1; i++)p[i] = i;
	for (int i = 0; i < M; i++) {
		cin >> L;
		swap(p[L - 2], p[L - 1]);
	}
	vector<vector<int>>to(62, vector<int>(N - 1));
	for (int i = 0; i < N - 1; i++)to[0][i] = p[i];
	for (int i = 1; i < 62; i++) {
		for (int j = 0; j < N - 1; j++) {
			to[i][j] = to[i - 1][to[i - 1][j]];
		}
	}
	for (int i = 0; i < N - 1; i++) {
		long long int box = K;
		int cnt = i;
		for (int j = 0; j < 62; j++) {
			if ((box >> j) & 1) {
				cnt = to[j][cnt];
			}
		}
		p[i] = cnt;
	}
	long long int num = v[0];
	cout << num << endl;
	for (auto i : p) {
		//cout << i << endl;
		num += v[i+1]-v[i];
		cout << num << endl;
	}
	return 0;
}