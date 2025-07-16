#include <bits/stdc++.h>

using namespace std;

#define FOR(i,k,n) for(int i = (k); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define INF 114514810
#define ll long long
#define ALL(a) (a).begin(),(a).end()
#define SORT(v) sort(ALL(v))
//#define scanf scanf_s
typedef pair<int, int> P;

int n,m,q;
int a[105];
int main()
{
	while (cin >> n >> q, n)
	{
		memset(a, 0, sizeof(a));
		REP(i, n)
		{
			cin >> m;
			int d;
			REP(j, m)
			{
				cin >> d;
				a[d]++;
			}
		}
		int* max = max_element(a,a+104);
		if (*max >= q) cout << max-a << endl;
		else cout << 0 << endl;
	}
	return 0;
}