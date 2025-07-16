#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int N;
	cin >> N;
	vector<int> a(N + 1), b(N + 1);
	for (int i = 1; i <= N; i++) cin >> a[i];
	for (int i = N; i >= 1; i--){
		int s = 0;
		for (int j = i + i; j <= N; j += i){
			s ^= b[j];
		}
		b[i] = s ^ a[i];
	}
	vector<int> ans;
	for (int i = 1; i <= N; i++){
		if (b[i]) ans.push_back(i);
	}
	cout << ans.size() << endl;
	rep(i, ans.size()){
		cout << ans[i] << " ";
	}
	return 0;
}
