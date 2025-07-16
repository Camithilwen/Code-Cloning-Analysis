#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)


int main() {
	int A, B, C;
	cin >> A >> B >> C;
	
	vector<int> ac(A);
	vector<int> bc(B);

	int minA = 1<<30, minB = 1<<30;
	rep(i, A) {
		cin >> ac.at(i);
		minA = min(minA, ac.at(i));
	}
	rep(j, B) {
		cin >> bc.at(j);
		minB = min(minB, bc.at(j));
	}

	int ans = minA + minB;

	rep(i, C) {
		int m;
		int tmp=0;
		cin >> m;
		tmp += ac.at(m-1);
		cin >> m;
		tmp += bc.at(m - 1);
		cin >> m;
		tmp -= m;
		ans = min(ans, tmp);
	}
	cout << ans << endl;
}