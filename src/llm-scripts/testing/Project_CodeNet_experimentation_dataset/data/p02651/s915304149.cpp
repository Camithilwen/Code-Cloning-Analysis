#include <bits/stdc++.h>
#define ll long long 
#define ld long double
#define int long long
using namespace std;
const ll INF = 1e18;
const ll MOD = 998244353;

int basis[100];
int cnt = 0;

void insert(int mask) {
	for(int i = 61; i >= 0; i--) {
		if(!(mask&(1ll << i)))	continue;
		if(basis[i] == 0)	{
			basis[i] = mask;
			cnt++;
			return;
		}
		mask ^= basis[i];
	}
}

bool check(int mask) {
	for(int i = 61; i >= 0; i--) {
		if(!(mask&(1ll << i)))	continue;
		if(!basis[i]) return false;
		mask ^= basis[i];
	}
	return (mask == 0);
}

int32_t main() {
	ios::sync_with_stdio(!cin.tie(NULL));

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		memset(basis, 0, sizeof(basis));
		cnt = 0;
		int arr[n];
		for(int i = 0; i < n; i++)	cin >> arr[i];
		string s;
		cin >> s;
		bool flag = true;

		for(int i = n - 1; i >=0; i--) {
			if(s[i] == '0') {
				insert(arr[i]);
			}
			else {
				if(!check(arr[i])) {
					cout << 1 << "\n";
					flag = false;
					break;
				}
			}
		}
		if(flag)
		cout << 0 << "\n";
	}
}

