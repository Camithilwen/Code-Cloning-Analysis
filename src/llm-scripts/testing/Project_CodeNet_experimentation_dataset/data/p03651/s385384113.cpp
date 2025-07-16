#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	if(a%b==0)
	{
		return b;
	}
	else
	{
		return gcd(b, a%b);
	}
}

int main()
{
	int n, k;
	bool ans = 0, ma = 0;
	cin >> n >> k;
	int A[100001];
	for (int i = 0; i < n; ++i)
	{
		cin >> A[i];
		if(A[i] == k)
		{
			ans = 1;
		}
		if(A[i] > k)
		{
			ma = 1;
		}
	}
	sort(A, A+n);
	bool ok = 0;
	int g = gcd(A[1],A[0]);
	for (int i = 1; i < n - 1; ++i)
	{
		g = gcd(g, A[i]);

	}
	ok = (k % g == 0);
	if(ma && ok)
	{
		ans = 1;
	}
	cout << (ans?"POSSIBLE":"IMPOSSIBLE") << endl;

	return 0;
}