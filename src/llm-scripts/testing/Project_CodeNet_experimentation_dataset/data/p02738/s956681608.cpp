#include <bits/stdc++.h>
using namespace std;

typedef long long Int;
typedef pair<Int,Int> PII;
typedef vector<int> VInt;
 
#define FOR(i, a, b) for(i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(i = (a) - 1; i >= (b); --i)
#define EACH(it, a) for(auto it = (a).begin(); it != (a).end(); ++it)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define SIZE(a) int((a).size())
#define ALL(a) (a).begin(),(a).end()
#define MP make_pair

#define MAX (6 << 10)

Int R[MAX][MAX + MAX];

int main()
{
	int n, m;
	cin >> n >> m;

	CLEAR(R, 0);
	R[0][MAX] = 1;
	int i, j;
	FOR(i, 0, 3*n)
	FOR(j, 0, MAX + MAX)
	if(R[i][j] != 0)
	{
		R[i + 1][j + 1] = (R[i + 1][j + 1] + R[i][j]) % m;
		if(i + 2 <= 3*n) R[i + 2][j - 1] = (R[i + 2][j - 1] + R[i][j]*(i + 1)) % m;
		if(i + 3 <= 3*n) R[i + 3][j] = (R[i + 3][j] + R[i][j]*(i + 1)*(i + 2)) % m;
	}

	Int res = 0;
	FOR(i, MAX, MAX + MAX) res += R[3*n][i];
	res %= m;
	cout << res << endl;
	return 0;
}