#pragma GCC optimize("O3")
//#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx2")
#define io_init cin.tie(0);ios::sync_with_stdio(0);cout<<setprecision(20)
#include <bits/stdc++.h>
constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int main() {
	int N;
	cin >> N;
	vector<vector<pair<int, int>>> person(N, vector<pair<int, int>>());
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		for (int j = 0; j < A; j++) {
			int x, y;
			cin >> x >> y;
			x--;
			person[i].push_back({ x,y });
		}
	}
	int ans = 0;
	//bitが立っている人が正直
	for (int i = 0; i < (1 << N); i++) {
		bool flag = true;
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			if ((i & (1 << j)) == 0)continue;
			cnt++;
			for (int k = 0; k < person[j].size(); k++) {
				if (((i & (1 << person[j][k].first)) != 0) != person[j][k].second)flag = false;
			}
		}
		if (flag)ans = max(ans, cnt);
	}
	cout << ans << endl;
}