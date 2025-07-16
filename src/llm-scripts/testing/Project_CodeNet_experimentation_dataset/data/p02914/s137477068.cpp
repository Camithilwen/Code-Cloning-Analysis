#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MN = 100100;
const int A = 60;
ll w[MN];
ll fr[A];
int main() {
	ll n;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> w[i];
		for(int j=0;j<A;j++) {
			if(w[i]&(1LL<<j)) {
				fr[j]++;
			}
		}
	}
	ll res = 0;
	ll tot = 0;
	ll ms = 0;
	int st = 0;
	for(int b=A-1;b>=0;b--) {
		if(fr[b]&1) {
			tot += 1LL<<b;
			continue;
		}
		ms |= 1LL<<b;
		ll ma = -1,mi = -1;
		for(int i=st;i<n;i++) {
			if((w[i]&(1LL<<b)) && w[i] > ma) {
				ma = w[i];
				mi = i;
			}
		}
		if(mi >= 0) {
			swap(w[mi],w[st]);
			mi = st;
			for(int i=0;i<n;i++) {
				if((w[i]&(1LL<<b)) && (i != mi)) {
					w[i] ^= ma;
				}
			}
			st++;
		}
	}
	for(int i=0;i<n;i++) {
		res ^= w[i];
	}
	tot += (res&ms)*2;
	cout << tot << '\n';
}
