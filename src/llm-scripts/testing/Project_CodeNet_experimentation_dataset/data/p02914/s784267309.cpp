#include <bits/stdc++.h>
#define MAX 100005
#define bit(x) (1ll << x)

using namespace std;

int n;
int cnt[64];
long long a[MAX], ans;

inline long long Rd() {
	long long x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}

struct linear_base {
	long long u[60];
	inline void insert(long long val) {
		for(int i = 59; i >= 0; --i) {
			if(val & bit(i)) {
				if(u[i]) val ^= u[i];
				else {
					u[i] = val;
					return;
				}
			}
		}
	}
	inline long long query() {
		long long res = 0;
		for(int i = 59; i >= 0; --i)
			if((res ^ u[i]) > res) res ^= u[i];
		return res;
	}
}lsk;

int main() {
	n = Rd();
	for(int i = 1; i <= n; ++i) {
		a[i] = Rd();
		for(int j = 59; j >= 0; --j)
			if(a[i] & bit(j)) ++cnt[j];
	}
	
	for(int i = 59; i >= 0; --i) {
		if(cnt[i] & 1) {
			ans += bit(i);
			for(int j = 1; j <= n; ++j) {
				if(a[j] & bit(i)) {
					a[j] ^= bit(i);
				}
			}
		}
	}
	for(int i = 1; i <= n; ++i) lsk.insert(a[i]);

	cout << ans + 2ll * lsk.query() << endl;
	return 0;
}