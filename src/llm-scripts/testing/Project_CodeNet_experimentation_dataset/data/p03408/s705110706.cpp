#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int Max = 1e6 + 5;

int lst[Max];
string ls[Max];
map<string, int> ma1, ma2;

int main()
{
	int n, m, g = 0;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		string t;
		cin >> t;
		ma1[t]++;
		ls[++g] = t;
	}
	cin >> m;
	for (int i = 1;i <= m;i++)
	{
		string t;
		cin >> t;
		ma2[t]++;
		ls[++g] = t;
	}
	int ma = -1e9 - 5;
	for (int i = 1;i <= g;i++)
	{
		ma = max(ma, ma1[ls[i]] - ma2[ls[i]]);
	}
	cout << max(0,ma);
}