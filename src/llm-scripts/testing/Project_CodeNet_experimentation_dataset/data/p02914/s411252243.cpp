#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

struct Gauss 
{
	static const int bits = 60;

	int table[bits];

	Gauss() 
	{
		for(int i = 0; i < bits; i++) 
			table[i] = 0;
	}

	int size() 
	{
		int ans = 0;
		for(int i = 0; i < bits; i++) 
		{
			if(table[i]) 
				ans++;
		}
		return ans;
	}

	bool can(int x) 
	{
		for(int i = bits-1; i >= 0; i--) 
			x = min(x, x ^ table[i]);
		return x == 0;
	}

	void add(int x) 
	{
		for(int i = bits-1; i >= 0 && x; i--) 
		{
			if(table[i] == 0) 
			{
				table[i] = x;
				x = 0;
			} 
			else 
				x = min(x, x ^ table[i]);
		}
	}

	int getBest() 
	{
		int x = 0;
		for(int i = bits-1; i >= 0; i--) 
			x = max(x, x ^ table[i]);
		return x;
	}

	void merge(Gauss &other)
	{
		for(int i = bits-1; i >= 0; i--)
			add(other.table[i]);
	}
};

int n;
int a[N];
Gauss g;

int32_t main()
{
	IOS;
	cin >> n;
	int curXor = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		curXor ^= a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		a[i] = a[i] & (((1LL << 60) - 1) ^ curXor);
		g.add(a[i]);
	}
	cout << curXor + g.getBest() * 2;
	return 0;
}