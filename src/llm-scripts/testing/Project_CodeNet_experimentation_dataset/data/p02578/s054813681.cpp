#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

int  main()
{
	int n;
	cin >> n;
	vector <long> a(n);
	rep(i, n)
		cin >> a[i];
	vector <long> b(n, 0);
	ll sum = 0;
	long max = a[0];
	int i = 0;
	while (i < n)
	{
		if (max < a[i])
			max = a[i];
		else if (a[i] < max)
			sum += max - a[i];
		i++;
	}
	cout << sum << endl;
	return (0);
}
