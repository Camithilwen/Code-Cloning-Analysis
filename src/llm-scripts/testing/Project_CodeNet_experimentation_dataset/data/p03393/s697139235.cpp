#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <iomanip>
#include <unordered_map>
#include <stack>

using namespace std;
typedef long long  ll;

const ll mod = 1000000007;

int main()
{
	string str;
	cin >> str;
	if (str.size() < 26)
	{
		map<char, ll> mp;
		for (ll i = 0; i < str.size(); i++)
		{
			mp[str[i]]++;
		}
		for (char i = 'a'; i < 'z' + 1; i++)
		{
			if (mp[i] == 0)
			{
				cout << str + i << endl;
				return 0;
			}
		}
	}
	ll index = str.size() - 1;
	for (ll i = str.size() - 1; i > 0 ; i--)
	{
		if (str[i - 1] > str[i])
		{
			index = i - 1;
		}
		else break;
	}
	if (index == 0)
	{
		cout << -1 << endl;
		return 0;
	}
	string q = str.substr(index, 1);
	for (ll i = index; i < str.size(); i++)
	{
		if (str.substr(index - 1, 1) < str.substr(i, 1))
		{
			q = min(q, str.substr(i, 1));
		}
	}
	string ans;
	if (index != 1)
	{
		ans += str.substr(0, index - 1);
	}
	cout << ans + q << endl;
	return 0;
}