#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N, L;
	cin >> N >> L;

	vector<int>V;
	for (int i = 0; i < N; i++) V.push_back(L + i);

	sort(V.begin(), V.end());

	int ans = 0;

	auto result = find(V.begin(), V.end(), 0);
	
	if (result != V.end()) {
		for (int i = 0; i < N; i++) ans += V[i];
		cout << ans << endl;
		return 0;
	}
	else {
		int A = V.front();
		int B = V.back();

		if (abs(A) < abs(B)||abs(A)==abs(B)) {
			for (int i = 1; i < N; i++) ans += V[i];
			cout << ans << endl;
			return 0;
		}
		else if(abs(A) > abs(B)) {
			for (int i = 0; i < N - 1; i++) ans += V[i];
			cout << ans << endl;
			return 0;
		}
	}
}