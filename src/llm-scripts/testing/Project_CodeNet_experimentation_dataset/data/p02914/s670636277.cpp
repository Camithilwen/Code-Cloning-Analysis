#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<int,int>
#define ff first
#define ss second
#define boost ios::sync_with_stdio(false);cin.tie(nullptr)
#define endl "\n"
#include "string"

int maxSubSetXor(int *a,int n) {
	int ans = 0;
	int id = 0;
	for(int i = 61; i >= 0; i--) {
		int maxid  = -1, maxi = -1;
		for(int j = id; j < n; j++) {
			if( a[j] & (1ll << i) && a[j] > maxi) {
				maxi = a[j];
				maxid = j;
			}
		}
		if(maxid == -1)
			continue;
		swap(a[maxid] , a[id]);
		for(int j = 0; j < n; j++) {
			if(j != id && a[j] & (1ll << i) )
				a[j] ^= maxi;
		}
		id++;
	}

	for(int i = 0; i < n; i++)
		ans ^= a[i];
	return ans;
}

int32_t main() {
	int n;
	cin >> n;
	int a[n] , xr = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		xr ^= a[i];
	}
	for(int i = 0; i < n; i++)
		a[i] &= ~xr;
	int ans  = maxSubSetXor(a, n);
	ans = 2 * ans + xr;
	cout << ans << endl;
}