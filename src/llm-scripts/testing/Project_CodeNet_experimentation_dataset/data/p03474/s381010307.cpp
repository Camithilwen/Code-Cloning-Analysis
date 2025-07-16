/*https://atcoder.jp/contests/abc084/tasks/abc084_b*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int a, b;
	string s;
	cin >> a >> b >> s;
	if (s.size() != a + b + 1 || s[a] != '-')
	{
		cout << "No";
		return 0;
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (i != a)
		{
			if (s[i] < 48 || s[i] > 57)
			{

				cout << "No";
				return 0;
			}
		}
	}
	cout << "Yes";
}