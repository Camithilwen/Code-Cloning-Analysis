#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int a,b;cin >> a >> b;
	cout << (a > b ? 2*a-1 : b > a ? 2*b -1 : 2*a);
	return 0;
}
