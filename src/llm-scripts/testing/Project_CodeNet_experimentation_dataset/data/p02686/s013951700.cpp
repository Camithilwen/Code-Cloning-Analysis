#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define pb push_back
#define mk make_pair
#define mod 1000000007
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define prec(y,x) fixed<<setprecision(y)<<x
#define inf 1e18
#define pi 3.1415926535
typedef tree<int, null_type, less<int>, rb_tree_tag,                    //if using ll change int to ll
        tree_order_statistics_node_update> pbset;
#define fob(x) find_by_order(x)
#define ook(x) order_of_key(x)
int main()

{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	string s;  ll l, r; l = 0; r = 0; vector<pair<int, pair<int, int>>> v1, v2;
	vector<int> ans, ans1;
	for (int i = 1; i <= n; i++)
	{
		cin >> s; int a = 0; int b = 0; //cout << s << endl;
		for (int j = 0; j < s.size(); j++)
		{

			if (s[j] == '(')
				a++;
			else
			{
				if (a == 0)
					b++;
				else
					a--;
			}
		}
		if (a == 0 && b == 0)
		{
			ans.pb(i);
		}
		else if (a == 0)
		{
			r += b;
			ans1.pb(i);
		}
		else if (b == 0)
		{
			l += a; ans.pb(i);
		}
		else
		{
			if (a >= b)
			{
				v1.pb(mk(b, mk(a, i)));
			}
			else
			{
				v2.pb(mk(a, mk(b, i)));
			}
		}
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	int flag = 0;
	for (int i = 0; i < v1.size(); i++)
	{
		int b = v1[i].ff;
		int a = v1[i].ss.ff;
		ans.pb(v1[i].ss.ss);
		l -= b;
		if (l < 0)
		{
			flag = 1; break;
		}
		l += a;
	}
	if (flag == 1)
	{
		cout << "No" << endl; return 0;
	}
	for (int i = v2.size() - 1; i >= 0; i--)
	{
		int a = v2[i].ff;
		int b = v2[i].ss.ff;
		ans.pb(v2[i].ss.ss);
		l -= b;
		if (l < 0)
		{
			flag = 1; break;
		}
		l += a;
	}

	if (flag == 1 || l != r)
	{
		cout << "No" << endl;
	}
	else
	{
		cout << "Yes" << endl;
		
	}
	return 0;
}
