#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast<t>(x)
#define AR(t) vector < t >
#define PII pair < int, int >
#define PLL pair < LL, LL >
#define PIL pair < int, LL >
#define PLI pair < LL, int >
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define PRF first
#define PRS second
#define INIT(ar,val) memset ( ar, val, sizeof ( ar ) )
#define lp(loop,start,end) for ( int loop = start; loop < end; ++loop )
#define lpd(loop,start,end) for ( int loop = start; loop > end; --loop )
#define lpi(loop,start,end) for ( int loop = start; loop <= end; ++loop )
#define lpdi(loop,start,end) for ( int loop = start; loop >= end; --loop )
#define qmax(a,b) (((a)>(b))?(a):(b))
#define qmin(a,b) (((a)<(b))?(a):(b))
#define qabs(a) (((a)>=0)?(a):(-(a)))

const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 100007;

int n;
int a[MAXN];

void init ();
void input ();
void work ();

int getcur ()
{
	int cc = 0;
	lpi ( i, 1, n ) cc ^= ( a[i] - 1 ) & 1;
	return cc;
}

int gcd ( int x, int y )
{
	return y ? gcd ( y, x%y ) : x;
}



int main()
{
	init();
	input();
	work();
}



void init ()
{
	// Init Everything Here
	
	ios::sync_with_stdio ( false );
}

void input ()
{
	// input method
	
	scanf ( "%d", &n );
	lpi ( i, 1, n ) scanf ( "%d", &a[i] );
}

void work ()
{
	// main work
	
	if ( n == 1 ){
		cout << "Second" << endl;
		return;
	}else if ( n == 2 ){
		cout << ( ( ( a[1] ^ a[2] ) & 1 ) ? "First" : "Second" ) << endl;
		return;
	}
	
	if ( getcur () ) cout << "First" << endl;
	else{
		int t = 0, cc, g;
		while ( 1 ){
			cc = 0;
			if ( getcur () ){
				cout << ( t ? "Second" : "First" ) << endl;
				break;
			}
			lpi ( i, 1, n ) cc += a[i] & 1;
			if ( cc > 1 || ( *min_element ( a+1, a+1+n ) == 1 ) ){
				cout << ( t ? "First" : "Second" ) << endl;
				break;
			}
			lpi ( i, 1, n ) if ( a[i] & 1 ) --a[i];
			g = a[1];
			lpi ( i, 2, n ) g = gcd ( g, a[i] );
			lpi ( i, 1, n ) a[i] /= g;
			t ^= 1;
		}
	}
}