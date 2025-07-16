#include <bits/stdc++.h>
using namespace std;
#define FOR(i, s, n) for(int i = s; i < (int)n; i++)
#define per(i, n) for(int i = n; i >= 0; i--)
#define ROF(i, s, n) for(int i = s; i >= (int)n; i--)
#define FORIT(i, A) for (auto i : A)
#define PRINT(x) cout << (x) << "\n"
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define MP make_pair
#define EACH(i, n) for (__typeof((n).begin()) i = (n).begin(); i != (n).end(); ++i)
#define SZ(a) int((a).size())
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define CLR(a) memset((a), 0 ,sizeof(a))
#define NCLR(a) memset((a), -1 ,sizeof(a))
#define dump(x) cout << #x << " = " << (x) << "\n";
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << "\n";
#define sq(n) (n) * (n)
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef priority_queue<int> maxpq;
typedef priority_queue< int, vector<int>, greater<int> > minpq;
typedef complex<double> P;
static const double EPS = 1e-10;
static const double PI = acos( -1.0 );
static const int mod = 1000000007;
static const int INF = 1 << 29;
static const LL LL_INF = 1152921504606846976;
static const int dx[] = { -1, 0, 1, 0, 1, -1, 1, -1 };
static const int dy[] = { 0, -1, 0, 1, 1, 1, -1, -1 };

int n, m;
int cl[ 100 ][ 100 ];

int main() {
	queue<PII> q;
	set<PII> s;
	while ( ~scanf("%d %d", &n, &m) && n && m ) {
		CLR( cl );
		bool can = false;
		int sx, sy, gx, gy;
		scanf( "%d %d", &sx, &sy );
		--sx;
		--sy;
		scanf( "%d %d", &gx, &gy );
		--gx;
		--gy;
		int k;
		scanf( "%d", &k );
		for ( int i = 0; i < k; i++ ) {
			int c, d, x, y;
			scanf( "%d %d %d %d", &c, &d, &x, &y );
			--x;
			--y;
			if ( d ) {
				for ( int i = 0; i < 4; i++ ) {
					for ( int j = 0; j < 2; j++ ) {
						cl[ y + i ][ x + j ] = c;
					}
				}
			}
			else {
				for ( int i = 0; i < 2; i++ ) {
					for ( int j = 0; j < 4; j++ ) {
						cl[ y + i ][ x + j ] = c;
					}
				}
			}
		}
		q.push( MP( sx, sy ) );
		while ( q.size() ) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if ( s.count( MP( x, y ) ) ) {
				continue;
			}
			s.insert( MP( x, y ) );
			if ( x == gx && y == gy ) {
				can = true;
				break;
			}
			for ( int i = 0; i < 4; i++ ) {
				if ( x + dx[ i ] < 0 || x + dx[ i ] == n || y + dy[ i ] < 0 || y + dy[ i ] == m || cl[ y ][ x ] != cl[ y + dy[ i ] ][ x + dx[ i ] ] ) {
					continue;
				}
				q.push( MP( x + dx[ i ], y + dy[ i ] ) );
			}
		}
		printf( "%s\n", can ? "OK" : "NG" );
		while ( q.size() ) {
			q.pop();
		}
		s.clear();
	}
	return 0;
}