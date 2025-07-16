#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int sum = 0;
	int m = 10000;

	for (int i = 0;i < 4;i++){
		int tmp; cin >> tmp;
		sum += tmp;
		m = min(m,tmp);
	}	

	int a,b; cin >> a >> b;

	cout << sum-m+max(a,b) << endl;

	return 0;

}
