#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
const int N = 2e5 + 5;
typedef long long ll; 
using namespace std;

int n, A, B, x[N];
ll ans; 

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
	freopen("cpp.in", "r", stdin); 
#endif
	n = read <int> (), A = read <int> (), B = read <int> ();
	for(int i = 1; i <= n; i++) x[i] = read <int> ();
	for(int i = 1; i < n; i++) ans += min(1ll * B, 1ll * A * (x[i + 1] - x[i]));
	printf("%lld\n", ans); 
	return 0; 
}
