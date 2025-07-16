#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 200010, M = 1010, mod = 998244353;

int n, m, k;
int infact[N], fact[N];

int qp(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = (LL)res * a % mod;
		a = (LL)a * a % mod;
		b >>= 1;
	}
	return res;
}

int C(int a, int b)
{
	return (LL)fact[a] * infact[b] % mod * infact[a - b] % mod;
}

int main()
{
	cin >> n >> m >> k;
	
	fact[0] = infact[0] = 1;
	for (int i = 1; i <= n; i ++ )
	{
		fact[i] = (LL)fact[i - 1] * i % mod;
		infact[i] = (LL)infact[i - 1] * qp(i, mod - 2) % mod;
	}
	
	int res = 0;
	for (int i = 0; i <= k; i ++ )
		res = (res + (LL)m * C(n - 1, i) % mod * qp(m - 1, n - 1 - i) % mod) % mod;
	cout << res << endl;
    return 0;
}