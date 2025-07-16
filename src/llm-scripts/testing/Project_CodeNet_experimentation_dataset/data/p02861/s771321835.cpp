#include<bits/stdc++.h>							
typedef long long ll;
#define pb push_back
#define mod 1000000007ll
const ll maxn = 9e18;
using namespace std;
const ll maxsize = 100000009;


double d(double x, double y, double a, ll b) {
	return sqrt((x - a) * (x - a) + (y - b) * (y - b));
}


ll fact(ll n) {
	if(n == 0) return 1;
	return n * fact(n - 1);
}


void solve() {
	int n;
	cin >> n;
	int arr[n];
	vector<pair<int,int>> c(n);
	double ans = 0;
	for(int i = 0; i < n; ++i) cin >> c[i].first >> c[i].second;
	for(int i = 0; i < n; ++i) arr[i] = i + 1;
		do{
			for(int i = 0; i < n - 1; ++i) {
				ans += d(c[arr[i] - 1].first, c[arr[i] - 1].second, c[arr[i + 1] - 1].first	, c[arr[i + 1] - 1].second);
					}
			}while(next_permutation(arr, arr + n));
			cout << ans / fact(n) << endl;
}


int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(35);
	solve();
	return 0;
}
 
 
 

