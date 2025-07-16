#include "bits/stdc++.h"
using namespace std;


int main() {
	int N;
	cin >> N;
	vector<int>A(N +1 );
	for (int n = 0;n<N;++n) {
		cin >> A[n + 1];
	}
	vector<int>B(N + 1);
	for (int n = N;n>=1;--n) {
		int sum = 0;
		for (int m = n + n;m <= N;m += n) {
			sum += B[m];
		}
		if (A[n] == sum%2) {
			B[n] = 0;
		}
		else{
			B[n] = 1;
		}
	}
	vector<int>Ans;
	for (int n = 0; n < N; ++n) {
		if (0 != B[n + 1]) {
			Ans.push_back(n + 1);
		}
	}
	cout << Ans.size()<<endl;
	for (int n = 0; n < Ans.size(); ++n) {
		if (0 !=n) {
			cout << " ";
		}
		cout << Ans[n];
	}
	return 0;
}