
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;

int main() {

	int n;
	cin >> n;
	vector<double> a(n);
	double sum = 0;
	rep(i, n){
		cin >> a[i];
		sum += a[i];
	}

	double k = sum / n;
	double mi = 100000;
	int ans = 0;
	rep(i, n){
		if(mi > abs(a[i]-k)){
			mi = abs(a[i]-k);
			ans = i;
		}
	}
	cout << ans << endl;

    return 0;
}
