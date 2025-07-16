
#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <iomanip>	
#include <deque>
#include <set>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define rrep(i,a,b) for(int i=a;i>=b;--i)
#define fore(i,a) for(auto &i:a)
#define INF INT_MAX/2;
typedef long long ll;
using namespace std;
using vi = vector<int>;
using vll = vector<ll>;
ll mod = 1e9 + 7;
//ll llmax = 10000000000000000000ll;
using namespace std;
using Graph = vector<vector<int>>;


int cnt_digit(ll N)
{
	int digit = 0;

	while (N > 0)
	{
		N /= 10;
		digit++;
	}
	return digit;
}


 // 最大公約数計算
 
ll gcd(ll a, ll b)
{
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}
// 最小公倍数の計算

ll lcm(ll a, ll b)
{
	ll g = gcd(a, b);

	return a / g * b;
}

struct union_find
{
	vector<int> par, r;
	union_find(int n)
	{
		par.resize(n);
		r.resize(n);
		init(n);
	}


	void init(int n)
	{
		for (int i = 0; i < n; i++) par[i] = i;
		for (int i = 0; i < n; i++) r[i] = 0;
	}

	int find(int x)
	{
		if (par[x] == x)return x;
		else return find(par[x]);
	}

	void unite(int x, int y)
	{
		x = find(x);
		y = find(y);

		if (r[x] < r[y])
		{
			par[x] = y;
		}
		else
		{
			par[y] = x;
			if (r[x] == r[y])
			{
				r[x]++;
			}
		}
	}
};



int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int a,b;
	cin >> a >> b;
	
	cout << max(max(a + b, a - b), a * b);
	
	
		
	
	
	
	
}
	