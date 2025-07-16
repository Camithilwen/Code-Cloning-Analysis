#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
using namespace std;

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN=200;
const int MAXX=100000;
const int MOD=1000000007;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

int n,sx;
int a[MAXN];

int ways[MAXN+1][MAXX+1];


int solve() {
	sort(a,a+n); reverse(a,a+n);
	memset(ways,0,sizeof(ways)); ways[0][sx]=1;
	REP(i,n) REPE(x,sx) if(ways[i][x]!=0) {
		inc(ways[i+1][x],(ll)(n-i-1)*ways[i][x]%MOD);
		inc(ways[i+1][x%a[i]],ways[i][x]);
	}
	int ret=0; REPE(x,sx) inc(ret,(ll)x*ways[n][x]%MOD); return ret;
}

void run() {
	scanf("%d%d",&n,&sx);
	REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}