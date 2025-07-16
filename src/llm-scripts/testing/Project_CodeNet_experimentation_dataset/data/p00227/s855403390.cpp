#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"


int main() {
	while (1) {
		int N, M; cin >> N >> M;
		if (!N)break;
		vector<int>prices(N);
		for (int i = 0; i < N; ++i) {
			cin >> prices[i];
		}
		sort(prices.begin(), prices.end(), greater<int>());
		int ans=0,num = 0;
		for (int i = 0; i < N; ++i) {
			num++;
			if (num == M) {
				num = 0;
			}
			else {
				ans += prices[i];
			}
		}
		cout << ans << endl;
	}
	return 0;
}