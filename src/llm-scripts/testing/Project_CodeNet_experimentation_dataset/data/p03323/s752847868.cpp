#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define e "\n"
#define MaRiaMa { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
#define fix(n) cout << fixed << setprecision(n);
using namespace std;
int main()
{
	MaRiaMa;
	int a, b,sum=16;
	cin >> a >> b;
	int s = max(a, b) - min(a, b);
	if (s == 0)
		cout << "Yay!";
	else
	{
		sum -= (2*min(a,b));
		if ((s += s) <= sum)
			cout << "Yay!";
		else
			cout << ":(";
	}
}