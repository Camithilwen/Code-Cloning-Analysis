#include<bits/stdc++.h>
using namespace std;

#define deb(x) cerr<<"["#x<<" : "<<x<<" ]\n";

int main()
{
	using ll = long long;
	ll n, y;
	cin >> n >> y;
	ll k = y - 1000*n;
	deb(k);
	int b = 0, a = 0;
	
	while(true) {
		if((k - (4000*b)) < 0) {
			puts("-1 -1 -1");
			return 0;
		}
		
		if((k - 4000*b) % 9000 == 0) {
			a = (k - 4000*b) / 9000;
			deb(a);
			deb(b);
			break;
		}
		b++;
	}
	
	if((n - a - b) < 0) puts("-1 -1 -1");
	else cout << a << ' ' << b << ' ' << n-a-b;
	
}
