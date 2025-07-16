#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<string>
using namespace std;

int a[5];

string S;

string poker(int p, int q, int r, int s, int t)
{
	if (p == q && q == r && r == s)
	{
		return "four card";
	}
	if (s == t && q == r && r == s)
	{
		return "four card";
	}
	if (p == q && q == r && s == t)
	{
		return "full house";
	}
	if (p == q && r == s && s == t)
	{
		return "full house";
	}
	if (p == q - 1 && q == r - 1 && r == s - 1 && s == t - 1)
	{
		return "straight";
	}
	if (p == 1 && q == 10 && r == 11 && s == 12 && t == 13)
	{
		return "straight";
	}
	if (p == q && q == r)
	{
		return "three card";
	}
	if (r == s && q == r)
	{
		return "three card";
	}
	if (r == s && s == t)
	{
		return "three card";
	}
	if (p == q && r == s)
	{
		return "two pair";
	}
	if (p == q && s == t)
	{
		return "two pair";
	}
	if (q == r && s == t)
	{
		return "two pair";
	}
	if (p == q)
	{
		return "one pair";
	}
	if (q == r)
	{
		return "one pair";
	}
	if (r == s)
	{
		return "one pair";
	}
	if (s == t)
	{
		return "one pair";
	}
	return "null";
}

int main() {
	while (cin >> S)
	{
		int cnt = 0;
		string U = "";
		S += ',';
		for (int i = 0; i < S.size(); i++)
		{
			if (S[i] == ',')
			{
				a[cnt] = stoi(U);
				U = "";
				cnt++;
			}
			else
			{
				U += S[i];
			}
		}
		sort(a, a + 5);
		cout << poker(a[0], a[1], a[2], a[3], a[4]) << endl;
	}
}