#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fast_io() ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
int n;
pair <int, int> get(string& s)
{
	stack <char> st;
	pair <int, int> ans;
	ans.first = 0;
	for (int i = 0; i < (int)s.size(); i++)
	{
		if (s[i] == '(')
			st.push('(');
		else
		{
			if (!st.empty())
				st.pop();
			else
				ans.first++;
		}
	}
	ans.second = (int)st.size();
	return ans;
}
bool balanced(string &s)
{
	int x = 0, y = 0;
	for (int i = 0; i < (int)s.size(); i++)
	{
		if (s[i] == '(')
			x++;
		else
			y++;
		if (x < y)
			return false;
	}
	if (x == y)
		return true;
	else
		return false;
}
int32_t main() {
	fast_io();
	cin >> n;
	vector < pair <int, int>> v1;
	vector < pair <int, int>> v2;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		pair <int, int> p = get(s);
		if (p.first == 0 && p.second == 0)
			continue;
		else
		{
			if (p.second - p.first >= 0)
				v1.pb(p);
			else
				v2.pb({p.second, p.first});
		}
	}
	sort(v1.begin(), v1.end());
	sort(v2.rbegin(), v2.rend());
	string res;
	for (auto x : v1)
	{
		for (int i = 0; i < x.first; i++)
			res += ')';
		for (int i = 0; i < x.second; i++)
			res += '(';
	}
	for (auto x : v2)
	{
		for (int i = 0; i < x.second; i++)
			res += ')';
		for (int i = 0; i < x.first; i++)
			res += '(';
	}
	if (balanced(res))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}