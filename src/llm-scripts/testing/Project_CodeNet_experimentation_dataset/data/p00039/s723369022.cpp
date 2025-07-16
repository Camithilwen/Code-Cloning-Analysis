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

int ans;
string str;


int main() {
	while ( ( cin >> str ) ) {
		ans = 0;
		for ( int i = 0; i < str.size(); i++ ) {
			if ( str[ i ] == 'M' ) {
				if ( ans % 1000 ) {
					ans += 800;
				}
				else {
					ans += 1000;
				}
			}
			else if ( str[ i ] == 'D' ) {
				if ( ans % 500 ) {
					ans += 300;
				}
				else {
					ans += 500;
				}
			}
			else if ( str[ i ] == 'C' ) {
				if ( ans % 100 ) {
					ans += 80;
				}
				else {
					ans += 100;
				}
			}
			else if ( str[ i ] == 'L' ) {
				if ( ans % 50 ) {
					ans += 30;
				}
				else {
					ans += 50;
				}
			}
			else if ( str[ i ] == 'X' ) {
				if ( ans % 10 ) {
					ans += 8;
				}
				else {
					ans += 10;
				}
			}
			else if ( str[ i ] == 'V' ) {
				if ( ans % 5 ) {
					ans += 3;
				}
				else {
					ans += 5;
				}
			}
			else {
				ans++;
			}
		}
		printf( "%d\n", ans );
	}
	return 0;
}