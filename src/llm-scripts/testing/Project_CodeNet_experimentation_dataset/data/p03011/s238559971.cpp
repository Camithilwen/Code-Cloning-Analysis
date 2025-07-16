/*G - Travelling Salesman Problem*/

/*F - PLUR @ EDC*/

/*A - Headphones */

#include <bits/stdc++.h>
using namespace std;

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b, c;
	int ans;
	int maximo;

	cin >> a >> b >> c;

	ans = a + b + c;
	maximo = max(a, b);
	maximo = max(maximo, c);

	ans -= maximo;

	cout << ans;

	return 0;
}