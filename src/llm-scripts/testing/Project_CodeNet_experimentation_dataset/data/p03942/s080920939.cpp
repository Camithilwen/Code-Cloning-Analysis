#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL) INF;

const int MAX = 1001000;

char S[MAX];
char T[MAX];

int A[MAX];

int main()
{
	//freopen("in.txt", "r", stdin);
	//ios::sync_with_stdio(false); cin.tie(0);

	int n;
	scanf("%d", &n);
	scanf("%s", S);
	scanf("%s", T);

	if ((string)(S) ==(string(T)))
	{
		cout<<0<<endl;
		return 0;
	}

	FILL(A, -1);
	int ind = n-1;
	RFOR(i, n, 0)
	{
		while (ind > i) ind--;
		while(ind >= 0 && S[ind] != T[i])
		{
			ind--;
		}

		if (ind == -1)
		{
			cout<<-1<<endl;
			return 0;
		}

		if (A[ind] == -1) A[ind] = i;
	}

	vector<PII> a;
	FOR (i, 0, n)
	{
		if (A[i] != -1) a.PB(MP(i, A[i]));
	}

	/*FOR (i, 0, SZ(a))
	{
		cout<<a[i].first<<' '<<a[i].second<<endl;
	}
	cout<<endl;*/

	int res = 0;

	ind = 0;
	int ind2 = 0;
	FOR (i, 0, SZ(a))
	{
		while(true)
		{
			if (ind2 == SZ(a)) break;
			if (a[ind2].first <= a[i].second)
			{
				ind2++;
				continue;
			}
			break;
		}
		while(true)
		{
			if (ind == SZ(a)) break;
			if (a[ind].first - (ind - i - 1) <= a[i].second)
			{
				ind++;
				continue;
			}
			break;
		}

		res = max(res, ind - i);
	}

	cout<<res<<endl;

}

