#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n;
char s[maxn];
typedef long long ll;
const ll mod = 1e9 + 7;
ll fac(int x) { ll ret = 1; for(int i = 1; i <= x; ++i) ret = ret * i % mod; return ret;}
ll f(int i, int j)
{
	if(i == 0) return j == 0;
	if(s[i] == 'B')
	{
		if(j & 1)
			return f(i - 1, j - 1);
		else
			return f(i - 1, j + 1) * (j + 1) % mod;
	}
	else
	{
		if(j & 1)
			return f(i - 1, j + 1) * (j + 1) % mod;
		else if(j > 0)
			return f(i - 1, j - 1);
		else
			return 0;
	}
}
int main()
{
	scanf("%d", &n);
	scanf("%s", s + 1);
	cout << f(2 * n, 0) * fac(n) % mod << endl;
	return 0;
}