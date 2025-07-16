#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>

#define PI 3.14159265359

#define INF 99999999;

#define rep(i, n) for(int i=0; i<n; i++)
#define REP(n) rep(i, n)

typedef long long ll;

using namespace std;



/*
class LightSwitchingPuzzle
{
public:
	int minFlips(string s)
	{

	}
}
*/


int main()
{
	int n, m;
	
	while (cin >> n >> m, n | m)
	{
		int p[n];
		
		REP(n) cin >> p[i];
		sort(p, p + n);
		
		int sum = 0, cnt = 0;
		for (int i=n-1; i>=0; i--)
		{
			cnt++;
			if (cnt == m)
			{
				cnt = 0;
				continue;
			}
			sum += p[i];
		}
		
		cout << sum << endl;
		
		/*
		//テスト出力
		REP(n) cout << p[i] << " ";
		*/
	}
	
	return 0;
}