#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M;

	while(cin >> N >> M, N || M) {
		vector<int> P;
		vector<int> v;
		for(int i = 0; i < N; i++) {
			int tmp;
			cin >> tmp;
			P.push_back(tmp);
		}
		P.push_back(0);

		for(int i = 0; i < P.size(); i++) {
			for(int j = 0; j < P.size(); j++) {
				v.push_back(P[i]+P[j]);
			}
		}
		sort(v.begin(), v.end());
		int j = v.size() - 1;
		int res = 0;
		for(int i = 0; i < v.size(); i++) {
			while(v[i]+v[j] > M && j >= 0)
				j--;
			if(j >= 0)
				res = max(res, v[i] + v[j]);
		}
		cout << res << endl;
	}
}