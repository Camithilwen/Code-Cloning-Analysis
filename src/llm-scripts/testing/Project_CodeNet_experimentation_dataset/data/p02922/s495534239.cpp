#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L
#define MOD 1000000007
//setprecision(15)

int main() {
	int A, B; cin >> A >> B;
	if (B == 1) {
		cout << "0" << endl; return 0;
	}
	if (B - A <= 0) {
		cout << "1" << endl; return 0;
	}
	B -= A;
	int cnt = 1;
	while (1) {
		cnt++;
		if (B - (A - 1) <= 0) {
			cout << cnt << endl;
			return 0;
		} else {
			B -= A - 1;
		}
	}
}