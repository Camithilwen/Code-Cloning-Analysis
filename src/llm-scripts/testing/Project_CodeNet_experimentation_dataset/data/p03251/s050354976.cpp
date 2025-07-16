#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	int X[100], Y[100];
	int inin;
	for (int i = 0; i < n; ++i)
	{
		cin >> X[i];
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> Y[i];
	}
	sort(X, X+n);
	sort(Y, Y+m);
	bool ok = 0;
	for (int i = x+1; i <= y; ++i)
	{
		if (i > X[n-1] && i <= Y[0])
		{
			ok = 1;
		}
	}
	cout << (ok?"No War":"War") << endl;
 
	return 0;
}