#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 1000000007
#define TE 2e5
using namespace std;
using ll = long long;
using ldb = long double;


int main() {
	int N, M; cin >> N >> M;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
			A[i][j]--;
		}
	}

	vector<bool> sp(M, true);
	int ans = 1e8;
	for (int k = 0; k < M - 1; k++) {
		vector<int> num(M);
		int temp = 0, id = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int a = A[i][j];
				if (sp[a]) {
					num[a]++;
					if (temp < num[a])
						temp = num[a], id = a;
					break;
				}
			}
		}
		//cout << "temp=" << temp << endl;
		sp[id] = false;
		if (temp == 0)continue;
		ans = min(ans, temp);
	}
	cout << (M == 1 ? N : ans) << endl;
}
