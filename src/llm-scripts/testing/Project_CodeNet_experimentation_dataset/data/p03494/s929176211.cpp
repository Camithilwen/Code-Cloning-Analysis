#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e3 + 7;
int lst[Max];
int n;

bool check()
{
	for (int i = 1; i <= n; i++)
	{
		if (lst[i] % 2 != 0) return false;
		else lst[i] /= 2;
	}
	return true;
}

int main()
{

	cin >> n;
	for (int i = 1; i <= n; i++)scanf("%d", &lst[i]);
	int g = 0;
	while (check())
	{
		g++;
	}
	cout << g;
}