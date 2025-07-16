#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
	int n;
	cin >> n;
	int a[4], ans, k;
	for (int i = 3; i >= 0; i--)
	{
		a[i] = n % 10; 
		n = n / 10;
	}
	string op;
	for (int i = 0; i < 8; i++)
	{
		ans = a[0];
		k = 1;
		for (int j = 2; j >= 0; j--)
		{
			if (i & (1 << j))
			{
				op += "-";
				ans -= a[k++];
			}
			else 
			{
				op += "+";
				ans += a[k++];
			}
		}
		if (ans == 7)
		{
			break;
		}
		else
		{
			op = "";
		}
	}
	string r = to_string(a[0]);
	k = 1;
	for (int i = 0; i < 3; i++)
		r += op[i] + to_string(a[k++]);
	r += "=7";
	cout << r << endl;
}
