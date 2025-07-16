#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<map>
#define PRE std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const int Max = 1e6 + 5;
const int Mod = 1e9 + 7;
ll ls1[Max], ls2[Max],ls3[Max],sum[Max];

int main()
{
	PRE;
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)cin >> ls1[i];
	for (int i = 1;i <= n;i++)cin >> ls2[i];
	for (int i = 1;i <= n;i++)cin >> ls3[i];
	sort(ls1 + 1, ls1 + 1 + n);
	sort(ls2 + 1, ls2 + 1 + n);
	for (int i = 1;i <= n;i++)
	{
		int g = lower_bound(ls1 + 1, ls1 + 1 + n, ls2[i]) - ls1-1;
		sum[i] = sum[i - 1] + lower_bound(ls1 + 1, ls1 + 1 + n, ls2[i]) - ls1-1;
	}
	ll res = 0;
	for (int i = 1;i <= n;i++)
	{
		res += sum[lower_bound(ls2 + 1, ls2 + n + 1, ls3[i]) - ls2-1];
	}
	cout << res;
}