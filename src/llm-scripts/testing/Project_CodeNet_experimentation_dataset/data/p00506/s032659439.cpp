#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=a;i<b;++i)

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int n, a[3], p;

int main() {
	cin >> n;
	for_(i,0,n) cin >> a[i];
	
	p = gcd(a[0], a[1]);
	if (n == 3) p = gcd(a[2], p);
	
	vector< int > c;
	for_(i,1,0 || i*i <= p) {
		if (p % i == 0) {
			c.push_back(i);
			if (p/i != i) c.push_back(p/i);
		}
	}
	
	sort(c.begin(), c.end());
	
	for_(i,0,(int)c.size()) {
		bool ok = 1;
		for_(j,0,n) ok &= (a[j] % c[i] == 0);
		if (ok) cout << c[i] << endl;
	}
	
	return 0;
}