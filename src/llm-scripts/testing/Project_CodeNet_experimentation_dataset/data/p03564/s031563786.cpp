#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9 * 2;

int main() {
	int n, k;
	cin >> n >> k;
	int num = 1;
	rep(i, n){
		num += min(num, k);
	}
	cout << num << endl;
}
