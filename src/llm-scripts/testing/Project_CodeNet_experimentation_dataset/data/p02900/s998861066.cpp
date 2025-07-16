#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <string>
#include <cmath>
#include <complex>
#include <numeric>
#include <cassert>

#include <vector>
#include <array>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

#define PI 3.14159265358979323846
#define int64 long long
#define uint64 unsigned long long
#define coutfix(i) cout << fixed << setprecision(i)		//coutの浮動小数出力の桁数設定
using namespace std;

int main()
{
	int64 aa, bb, ans = 1, tmp1, tmp2;
	cin >> aa >> bb;
	tmp1 = tmp2 = gcd(aa, bb);
	for(int64 ii = 2;ii * ii <= tmp2;ii++)
	{
		if(tmp1 % ii == 0)
		{
			ans++;
			while(tmp1 % ii == 0)
			{
				tmp1 /= ii;
			}
		}
	}
	if(tmp1 != 1)
	{
		ans++;
	}
	cout << ans << endl;
	return 0;
}