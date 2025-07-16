#include <iostream>
#define ll long long
using namespace std;
int main () {
	int q,p = 0,n; cin >> q; ll ans = 0;
	while (q--){
		cin >> n;
		if (n<p) ans += p-n;
		else p=n;
	} cout << ans << "\n";
	return 0;
}