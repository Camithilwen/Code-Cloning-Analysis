#include <bits/stdc++.h>
using namespace std;

int const N = 2e5 + 7;
int n, k;
int bit[N];
int ar[N];

void add(int x, int val)
{
	while (x < N)
		bit[x] += val, x += (x & -x);
}

int sum(int x)
{
	int res = 0;
	while (x)
		res += bit[x], x -= (x & -x);
	return res;
}

//Lamps with N radius
int getMax()
{
	int res = 0;
	for (int i = 1; i <= n; ++i)
		res += (ar[i] == n);
	return res;
}

void update()
{
	memset(bit, 0, sizeof(bit));
	for (int i = 1; i <= n; ++i)
	{
		add(max(1, i - ar[i]), 1);
		add(min(n+1, i + ar[i] + 1), -1);
	}

	for (int i = 1; i <= n; ++i)
		ar[i] = sum(i);
}

int main()
{
	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
		cin >> ar[i];
	

	for (int i = 0; i < k; ++i)
	{
		update();
		if (getMax() == n)
			break;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (i != 1) cout << " ";
		cout << ar[i];
	}
	cout << '\n';
	return 0;
}