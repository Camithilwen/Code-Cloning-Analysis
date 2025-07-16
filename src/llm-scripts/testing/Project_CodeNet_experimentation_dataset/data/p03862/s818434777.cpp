#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<memory.h>
using namespace std;
typedef long long ll;
const int Max = 4e5 + 5;

int lst[Max];

int main()
{
	int n, x;
	cin >> n >> x;
	for (int i = 1;i <= n;i++)
	{
		scanf("%d", &lst[i]);
	}
	ll sum = 0;
	if (lst[1] > x)
	{
		sum = lst[1] - x;
		lst[1] = x;
	}
	for (int i = 2;i <= n;i++)
	{
		if (lst[i - 1] + lst[i] > x)
		{
			int t = lst[i] + lst[i - 1] - x;
			lst[i] -= t;
			sum += t;
		}
	}
	cout << sum << endl;
}