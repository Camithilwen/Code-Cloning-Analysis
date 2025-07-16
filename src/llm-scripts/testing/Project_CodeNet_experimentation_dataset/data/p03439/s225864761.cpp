#pragma region
#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <list>
#include <iomanip>
#include <cstdint>
#include <cstdlib>

using namespace std;
typedef long long ll;
//#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define rrep(i, s) for (int(i) = (s) - 1; (i) >= 0; --(i))
#define all(x) x.begin(),x.end()
#pragma endregion


int main()
{
	int n; cin >> n;
	cout << 0 << endl;
	string z; cin >> z;
	if (z == "Vacant")return 0;
	int ok = 0, ng = n;
	while (true)
	{
		int mid = abs(ok + ng) / 2;
		cout << mid << endl;
		string s; cin >> s;
		if (s == "Vacant")return 0;
		else if ((mid % 2 == 0 && s == z) || (mid % 2 == 1 && s != z))
		{
			ok = mid;
		}
		else ng = mid;
	}
}