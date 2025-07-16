#include <bits/stdc++.h>
using namespace std;
 
long long int labs(long long int a, long long int b)
{
	return ((a>b)?a-b:b-a);
}
 
long long int lmin(long long int a, long long int b)
{
	return ((a>b)?b:a);
}
 
int main()
{
	long long int n, k, x[100001];
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i];
	}
	long long int ans = 1145141919;
	for (int i = k; i <= n; ++i)
	{
		ans = lmin(ans, labs(x[i-k]-x[i-1])+lmin(labs(x[i-k]),labs(x[i-1])));
	}
	cout << ans << endl;
	return 0;
}