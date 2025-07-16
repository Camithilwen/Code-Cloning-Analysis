#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9 * 2;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	sort(a.begin(), a.end());
	int count = 1;
	int out = 0;
	rep(i, n - 1){
		if(a[i] == a[i + 1]) count++;
		else{
			if(count % 2 == 1) out++;
			count = 1;
		}
	}
	if(count % 2 == 1) out++;
	cout << out << endl;
}
