#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt" > "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\b.answer"
int main() {
	int sum = 0;
	vector<int>as(4), bs(2);
	for (int i = 0; i < 4; ++i) {
		cin >> as[i];
		sum += as[i];
	}
	cin >> bs[0] >> bs[1];
	sum += bs[0] + bs[1];
	sum -= *min_element(as.begin(), as.end()) + *min_element(bs.begin(), bs.end());
	cout << sum << endl;

	return 0;
}