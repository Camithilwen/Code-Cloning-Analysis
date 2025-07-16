#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
using namespace std;
using cd = complex <double>;
 
typedef pair <int, int> pii;
const int N = 3e3 + 5;
const long long INF = 1e18;
const int mod = 1e9 + 7;//786433;//998244353;
const double Pi = acos(-1);
const int p = 510200;
 
void Fastio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int n, m;
int Fact[200005];
map <int, int> M;

int BinPow(int x, int n)
{
	if(n == 0)
	{
		return 1;
	}
	int temp = BinPow(x, n >> 1);
	if(n & 1)
	{
		return 1ll * temp * temp % mod * x % mod;
	}
	else
	{
		return 1ll * temp * temp % mod;
	}
}

int C(int k, int n)
{
	return 1ll * Fact[n] * BinPow(Fact[k], mod - 2) % mod * BinPow(Fact[n - k], mod - 2) % mod;
}

signed main()
{
//	Fastio();
	cin >> n >> m;
	Fact[0] = 1;
	for(int i = 1; i <= 2e5; i++)
	{	
		Fact[i] = 1ll * Fact[i - 1] * i % mod;
	}
	for(int i = 2; i <= sqrt(m); i++)
	{
		while(m % i == 0)
		{
			M[i]++;
			m /= i;
		}
	}
	if(m > 1)
	{
		M[m]++;
	}
	int ans = 1;
	for(auto x : M)
	{
		ans = 1ll * ans * C(n - 1, x.se + n - 1) % mod;
	}
	cout << ans;
}