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
const int MAXN = 1000007;
const int MOD = 998244353;

int n, m;
LL frac[MAXN], rf[MAXN];

void init ();
void input ();
void work ();

void addv ( int &x, int y )
{
	x += y;
	if ( x >= MOD ) x -= MOD;
}

int qpow ( int a, int b )
{
	LL base = a, ans = 1;
	while ( b ){
		if ( b & 1 ) ( ans *= base ) %= MOD;
		( base *= base ) %= MOD;
		b >>= 1;
	}
	return SC ( int, ans );
}

int C ( int n, int m )
{
	return SC ( int, frac[n] * rf[m] % MOD * rf[n-m] % MOD );
}

int getmd ( int n, int m )
{
	return C ( n + m, n );
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
	
	frac[0] = 1;
	lp ( i, 1, MAXN ) frac[i] = frac[i-1] * i % MOD;
	rf[MAXN-1] = qpow ( frac[MAXN-1], MOD-2 );
	lpdi ( i, MAXN-2, 0 ) rf[i] = rf[i+1] * ( i + 1 ) % MOD;
}

void input ()
{
	// input method
	
	scanf ( "%d%d", &n, &m );
}

void work ()
{
	// main work
	
	int ans = 0;
	lpi ( i, 1, qmin ( n, m ) ) addv ( ans, SC ( LL, getmd ( n-i, m-i ) ) * getmd ( i, i ) % MOD );
	ans = SC ( LL, ans ) * qpow ( getmd ( n, m ) * 2 % MOD, MOD-2 ) % MOD;
	addv ( ans, qmax ( n, m ) );
	cout << ans << endl;
}