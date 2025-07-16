#include <stdio.h>
#include <cctype>
#include <limits.h>
#include <math.h>
#include <complex>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <iostream>

#define VARIABLE(x) cerr << #x << "=" << x << endl
#define BINARY(x) static_cast<bitset<16> >(x)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for (int i=m;i<(int)(n);i++)
#define if_range(x, y, w, h) if (0<=(int)(x) && (int)(x)<(int)(w) && 0<=(int)(y) && (int)(y)<(int)(h))
#define ALL(a) (a).begin(),(a).end()
const int INF = 1e9;
int dx[4]={0, 1, 0, -1}, dy[4]={-1, 0, 1, 0};
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

int cost[100][100];
int main()
{
	int N, M;
	while (cin>>N>>M, N) {
		rep(i, N) rep(j, N) cost[i][j] = (i==j?0:INF);
		
		rep(i, M) {
			int q; cin>>q;
			if (q==0) {
				int a, b;
				cin>>a>>b; a--, b--;
				
				cout << (cost[a][b] < INF ? cost[a][b] : -1) << endl;
			} else {
				int a, b, c;
				cin>>a>>b>>c; a--, b--;
				
				for (int i=0; i<N; i++) {
					for (int j=0; j<N; j++) {
						cost[i][j] = min({cost[i][j], cost[i][a] + cost[j][b] + c, cost[i][b]+ cost[j][a] + c});
					}
				}
			}
		}
	}
}