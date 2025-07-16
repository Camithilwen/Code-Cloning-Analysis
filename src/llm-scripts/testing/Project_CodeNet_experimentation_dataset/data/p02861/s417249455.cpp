#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
#include<map>
#include<iomanip>

using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(ll i=0;i<n;i++)


int main()
{
	ll n;
	cin >> n;
	vector<ll> x(n);
	vector<ll> y(n);
	rep(i, n) cin >> x[i] >> y[i];
	double sum = 0;
	rep(i, n) for (ll j = i + 1; j < n; j++)
	{
		sum += sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
	}
	double ans = 2 * sum / n;
	cout << fixed << setprecision(8) << ans << "\n";
	return 0;
}