//E869120さんのコード
#include <bits/stdc++.h>
using namespace std;
 
long long N; string S;
 
int main() {
	cin >> N;
	if (N == 0) { cout << "0" << endl; return 0; }
	while (N != 0) {
		if (N % 2 == 1 || N % 2 == -1) { N--; S += "1"; }
		else { S += "0"; }
		N /= -2;
	}
	reverse(S.begin(), S.end());
	cout << S << endl;
	return 0;
}
