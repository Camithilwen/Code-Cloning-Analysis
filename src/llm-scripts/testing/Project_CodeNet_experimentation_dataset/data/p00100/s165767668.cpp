#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt"
int main() {
	while (1) {
		int N; cin >> N;
		if (!N)break;
		map<int, long long int>mp;
		vector<int>vs;
		for (int i = 0; i < N; ++i) {
			long long int a, b, c; cin >> a >> b >> c;
			mp[a] += b*c;
			if (find(vs.begin(), vs.end(), a) == vs.end())vs.emplace_back(a);
		}
		bool flag = false;
		for (auto v : vs) {
			if (mp[v] >= 1000000) {
				cout << v << endl;
				flag = true;
			}
		}
		if (!flag)cout << "NA" << endl;
	}
	return 0;
}

