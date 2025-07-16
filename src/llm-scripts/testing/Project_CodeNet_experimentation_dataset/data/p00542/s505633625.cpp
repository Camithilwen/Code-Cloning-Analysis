#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
 
//const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
//const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
 
int main()
{
	vector<int> a(4);
	REP(i, 4) cin >> a[i];

	vector<int> b(2);
	REP(i, 2) cin >> b[i];

	sort(ALL(a), greater<int>());
	sort(ALL(b), greater<int>());

	int sum = 0;

	REP(i, 3) sum += a[i];
	sum += b[0];

	cout << sum << endl;

}

