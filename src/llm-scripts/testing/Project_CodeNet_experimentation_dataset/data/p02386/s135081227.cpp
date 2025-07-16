#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iomanip>
#include <math.h>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <functional>

using namespace std;

typedef long long int ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;

#define FOR(i,n,m) for(ll i=(ll)(m);i<(ll)(n);++i)
#define REP(i,n) FOR(i,n,0)
#define IREP(i,n) for(ll i=(ll)(n);i>=0;--i)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

struct Face
{
	int f;
	int a[4];
};
struct Dice
{
	Face f[6];
};

Dice createDice(int k[])
{
	Face d[6];
	d[0].f = k[0];
	d[0].a[0] = k[4];
	d[0].a[1] = k[2];
	d[0].a[2] = k[1];
	d[0].a[3] = k[3];

	d[1].f = k[1];
	d[1].a[0] = k[0];
	d[1].a[1] = k[2];
	d[1].a[2] = k[5];
	d[1].a[3] = k[3];

	d[2].f = k[2];
	d[2].a[0] = k[0];
	d[2].a[1] = k[4];
	d[2].a[2] = k[5];
	d[2].a[3] = k[1];

	d[3].f = k[3];
	d[3].a[0] = k[0];
	d[3].a[1] = k[1];
	d[3].a[2] = k[5];
	d[3].a[3] = k[4];

	d[4].f = k[4];
	d[4].a[0] = k[0];
	d[4].a[1] = k[3];
	d[4].a[2] = k[5];
	d[4].a[3] = k[2];

	d[5].f = k[5];
	d[5].a[0] = k[1];
	d[5].a[1] = k[2];
	d[5].a[2] = k[4];
	d[5].a[3] = k[3];
	Dice dice;
	REP(i, 6)
	{
		dice.f[i] = d[i];
	}
	return dice;
}

int main()
{
	Dice d[105];

	int n;
	cin >> n;
	int sum = 0;
	REP(i, n)
	{
		int x[6];
		
		REP(j, 6)
		{
			cin >> x[j];
			sum += x[j];
		}

		
		d[i] = createDice(x);
	}

	if (sum == 22)
	{
		cout << "No" << endl;
		return 0;
	}
	string S = "Yes";

	REP(i, n)
	{
		FOR(j, n, i + 1)
		{
			bool same = true;
			REP(k, 6)
			{
				Face f1 = d[i].f[k];
				REP(l, 6)
				{
					Face f2 = d[j].f[l];
					if (f1.f == f2.f)
					{
						int s = -1;
						REP(m, 4)
						{
							if (f1.a[0] == f2.a[m])
							{
								s = m;
								break;
							}
						}
						if (s == -1)
						{
							same = false;
							break;
						}
						REP(m, 4)
						{
							if (f1.a[m] != f2.a[(m + s) % 4])
							{
								same = false;
								break;
							}
						}
						break;
					}
					if (l == 5)
					{
						same = false;
					}
				}
			}
			if (same)
			{
				S = "No";
				break;
			}
		}
	}

	cout << S << endl;
	return 0;
}
