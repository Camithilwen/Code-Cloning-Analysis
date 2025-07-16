#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
typedef long long ll; 
using namespace std;

ll n, m; 

template < typename T >
inline T read()
{
	T x = 0, w = 1; char c = getchar();
	while(c < '0' || c > '9') { if(c == '-') w = -1; c = getchar(); }
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * w; 
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("cpp.in", "r", stdin), freopen("cpp.out", "w", stdout);
#endif
	n = read <ll> (), m = n / 11 * 2ll, n %= 11;
	if(!n) { printf("%lld\n", m); return 0; }
	else if(n <= 6) { printf("%lld\n", m + 1); return 0; }
	else printf("%lld\n", m + 2); 
	return 0; 
}
