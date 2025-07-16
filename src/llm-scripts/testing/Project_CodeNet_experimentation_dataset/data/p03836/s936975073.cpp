#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


using namespace std;

const int INF = 1e9 + 7;
const int N = 1e5+5;


int main() {
	
	IO;
	
	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	
	string ans, ur, ld, mdf="L", mof = "R";
	
	while (ty > sy) {
		ur += 'U';
		ld += 'D';
		sy++;
	}
	mdf += ur + 'U';
	mof += ld + 'D';
	while (tx > sx) {
		ur += 'R';
		ld += 'L';
		mdf += 'R';
		mof += 'L';
		sx++;
	}

	mdf += "RD";
	mof += "LU";
	ans += ur + ld + mdf + mof;
	
	cout << ans << endl;
		
		

}

