#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	ll ans = 0;
	for(int get_num = min(k, n); get_num >= 0; --get_num)
	{
		for(int start = -get_num; start <= 0; ++start)
		{
			ll sum = 0;
			vector<int> may_erase;
			for(int i = 0; i < get_num; ++i)
			{
				int val = v[start + i < 0 ? start + i + n : start + i];
				sum += val;
				if (val < 0) may_erase.emplace_back(val);
			}

			sort(may_erase.begin(), may_erase.end());
			int erase_num = min((int)may_erase.size(), k - get_num);
			ll erase_sum = 0;
			for(int i = 0; i < erase_num; ++i)
			{
				erase_sum += may_erase[i];
			}
			// cout << get_num << " " << start << " : " << sum << " - " << -erase_sum << endl;
			ans = max(ans, sum - erase_sum);
		}
	}
	cout << ans;



}

int main()
{
	fastio;
	solve();

	return 0;
}