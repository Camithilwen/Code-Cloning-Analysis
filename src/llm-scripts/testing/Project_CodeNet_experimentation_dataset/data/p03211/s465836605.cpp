/*https://atcoder.jp/contests/abc114/tasks/abc114_b*/
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
	string s;
	int min_dif = 1e5 + 1;
	cin >> s;
	for (int i = 0; i < s.length() - 2; i++)
	{
		char a, b, c;
		a = s[i], b = s[i + 1], c = s[i + 2];
		string n;
		n += s[i];
		n += s[i + 1];
		n += s[i + 2];

		// cout << a << " " << b << " " << c << endl;
		// int x = stoi(n) + atoi(b) + atoi(c);
		// cout << n << endl;

		int x = stoi(n);
		// cout << x <<< " ->" abs(x - 753)
		min_dif = min(min_dif, abs(x - 753));
	}
	cout << min_dif;
}