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

int n, S;
int p[MAXN];
int a[MAXN];
int ord[MAXN];
int m[2], sx[2][MAXN], sa[2][MAXN];

void init ();
void input ();
void work ();



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
	
	scanf ( "%d%d", &n, &S );
	lpi ( i, 1, n ) scanf ( "%d%d", &p[i], &a[i] );
}

void work ()
{
	// main work
	
	lpi ( i, 1, n ){
		if ( p[i] < S ){
			++m[0];
			sx[0][m[0]] = i, sa[0][m[0]] = a[i];
		}else break;
	}
	lpd ( i, n, 0 ){
		if ( p[i] > S ){
			++m[1];
			sx[1][m[1]] = i, sa[1][m[1]] = a[i];
		}
	}
	
	if ( !m[0] || !m[1] ){
		cout << ( qmax ( S - p[1], 0 ) + qmax ( p[n] - S, 0 ) ) << endl;
		return;
	}
	
//	lp ( t, 0, 2 ){
//		cerr << t << " : " << endl;
//		lpi ( i, 1, m[t] ) cerr << sx[t][i] << " " << sa[t][i] << endl;
//	}
	
	int ns = 0, np[2] = { 1, 1 }, ka = 0;
	LL ca = sa[1][1];
	while ( np[0] <= m[0] && np[1] <= m[1] ){
		if ( sa[ns][np[ns]] > ca || ( sa[ns][np[ns]] == ca && ns == 0 ) ){
			ord[++ka] = sx[ns^1][np[ns^1]++];
			ca += sa[ns][np[ns]];
			ns ^= 1;
		}else{
			ord[++ka] = sx[ns][np[ns]];
			ca += sa[ns][np[ns]++];
		}
	}
	ord[++ka] = sx[ns^1][np[ns^1]];
//	lpi ( i, 1, ka ) cerr << ord[i] << " "; cerr << endl;
	
	LL ans = 0;
	int cp = S;
	lpd ( i, ka, 0 ){
		ans += qabs ( cp - p[ord[i]] );
		cp = p[ord[i]];
	}
	
	cout << ans << endl;
}