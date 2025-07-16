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
static const double EPS = 1e-10;
static const double PI = acos( -1.0 );
static const int mod = 1000000007;
static const int INF = 1 << 25;
static const LL LL_INF = 1152921504606846976;

int n, m, a, b, c;
LL d;
int main() {
	while ( ~scanf( "%d %d", &n, &m ) && n && m ) {
		LL mp[ 100 ][ 100 ];
		for ( int i = 0; i < n; i++ ) {
			for ( int j = 0; j < n; j++ ) {
				mp[ i ][ j ] = LL_INF;
			}
		}
		for ( int i = 0; i < n; i++ ) {
			mp[ i ][ i ] = 0;
		}
		for ( int i = 0; i < m; i++ ) {
			scanf( "%d", &a );
			switch ( a ) {
				case 0:
					scanf( "%d %d", &b, &c );
					if ( mp[ b - 1 ][ c - 1 ] == LL_INF ) {
						printf( "-1\n" );
					}
					else {
						printf( "%lld\n", mp[ b - 1 ][ c - 1 ] );
					}
					break;
				case 1:
					scanf( "%d %d %lld", &b, &c, &d );
					if ( mp[ b - 1 ][ c - 1 ] > d ) {
						mp[ b - 1 ][ c - 1 ] = mp[ c - 1 ][ b - 1 ] = min( d, mp[ b - 1 ][ c - 1 ] );
						for ( int j = 0; j < n; j++ ) {
							for ( int k = 0; k < n; k++ ) {
								for ( int l = 0; l < n; l++ ) {
									mp[ k ][ l ] = mp[ l ][ k ] = min( mp[ k ][ l ], mp[ k ][ j ] + mp[ j ][ l ] );
								}
							}
						}
					}
					break;
			}
		}
	}
	return 0;
}