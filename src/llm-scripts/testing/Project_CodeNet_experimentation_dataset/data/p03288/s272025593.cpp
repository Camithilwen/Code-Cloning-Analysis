#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int R;
	cin >> R;
	string S;
	if (R < 1200) S = "ABC";
	else if (R < 2800) S = "ARC";
	else  S = "AGC";
	cout << S << endl;
	return 0;
}
