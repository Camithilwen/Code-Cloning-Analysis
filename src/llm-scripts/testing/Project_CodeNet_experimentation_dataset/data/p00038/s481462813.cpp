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
static const double EPS = 1e-10;
static const double PI = acos( -1.0 );
static const int mod = 1000000007;
static const int INF = 1 << 25;
static const LL LL_INF = 1152921504606846976;
static const int dx[] = { -1, 0, 1, 0, 1, -1, 1, -1 };
static const int dy[] = { 0, -1, 0, 1, 1, 1, -1, -1 };


string _str[ 7 ] = { "null", "one pair", "two pair", "three card", "straight", "full house", "four card" };
int ans = 0;
int _hand[ 5 ];

int main() {
	while ( ~scanf( "%d,%d,%d,%d,%d", &_hand[ 0 ], &_hand[ 1 ], &_hand[ 2 ], &_hand[ 3 ], &_hand[ 4 ] ) ) {
		ans = 0;
		sort( _hand, _hand + 5 );
		bool is_straight = true;
		for ( int i = 0; i < 4; i++ ) {
			if ( _hand[ i + 1 ] - _hand[ i ] != 1 ) {
				is_straight = false;
				break;
			}
		}
		if ( is_straight ) {
			ans = 4;
		}
		for ( int i = 0; i < 5; i++ ) {
			if ( _hand[ i ] == 1 ) {
				_hand[ i ] += 13;
			}
		}
		sort( _hand, _hand + 5 );
		is_straight = true;
		for ( int i = 0; i < 4; i++ ) {
			if ( _hand[ i + 1 ] - _hand[ i ] != 1 ) {
				is_straight = false;
				break;
			}
		}
		if ( is_straight ) {
			ans = 4;
		}

		bool is_three_card = false;
		bool is_one_pair = false;
		for ( int i = 1; i <= 20; i++ ) {
			int many = upper_bound( _hand, _hand + 5, i ) - lower_bound( _hand, _hand + 5, i );
			if ( many == 4 ) {
				ans = 6;
				break;
			}
			if ( many == 3 ) {
				is_three_card = true;
				ans = 3;
				if ( is_one_pair ) {
					ans = 5;
					break;
				}
			}
			if ( many == 2 ) {
				if ( is_one_pair ) {
					ans = 2;
					break;
				}
				if ( is_three_card ) {
					ans = 5;
					break;
				}
				is_one_pair = true;
				ans = 1;
			}
		}
		printf( "%s\n", _str[ ans ].c_str() );
	}
	return 0;
}