#include<iostream>
using namespace std;
#include<string>
#include<strstream>
#include<sstream>
#include<algorithm>
#include<math.h>
#include<iomanip>
#include<set>
long long mod = 10e18;
long long is(int n)
{
	if (n == 0)
		return 2;
	if (n == 1)
		return 1;
	return (is(n - 1) + is(n - 2));
}
int main()
{
	int n, k; cin >> n >> k; int j = 1;
	j += j;
	for (int i = 2; i <= n; ++i)
	{
		if (j < k)
		{
			j += j;
		}
		else
			j += k;
	}
	cout << j;
	
}