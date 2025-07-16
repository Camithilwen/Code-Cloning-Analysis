#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if ((a < c && b > c) || (a > c && b < c)) puts("Yes");
	else puts("No");
	return 0;
}