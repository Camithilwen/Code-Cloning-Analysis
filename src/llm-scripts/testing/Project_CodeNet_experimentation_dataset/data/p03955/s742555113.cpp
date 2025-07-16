/*+lmake
 * STD = c++14
 * DEFINE += WAAUTOMATON
 */
#include <bits/stdc++.h>
using namespace std;
using LL=long long;
using ULL=unsigned long long;
#ifdef WAAUTOMATON
#define debug(args...)            {dbg,args; cerr<<endl;}
#else
#define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
	template<typename T> debugger& operator , (const T& v)
	{
		cerr<<v<<" ";
		return *this;
	}
} dbg;
#define MAXN 100000
int c[MAXN+10];
bool b[MAXN+10];
void solve(long long N, vector<vector<long long>> a){
	int r[2]={0,0},f[2]={0,0};
	for(int i=0; i<N; ++i) {
		c[i]=a[1][i]/3+1;
		if (c[i]%2==i%2) throw 2;
		if (a[0][i]==c[i]*3-2 && a[1][i]==c[i]*3-1 && a[2][i]==c[i]*3) {
		} else if (a[0][i]==c[i]*3 && a[1][i]==c[i]*3-1 && a[2][i]==c[i]*3-2) {
			r[(i+1)&1]^=1;
		} else {
			throw 1;
		}
	}
	memset(b,true,sizeof(b));
	for(int i=1; i<=N; ++i) {
		if (b[i]) {
			int x=c[i-1];
			while(x!=i) {
				debug(x);
				b[x]=false;
				f[i&1]^=1;
				x=c[x-1];
			}
		}
	}
	debug(f[0],f[1]);
	debug(r[0],r[1]);
	if (f[0]!=r[1] || f[1]!=r[0]) throw 3;
	puts("Yes");
}

int main(){
#ifdef WAAUTOMATON
	freopen("in.txt","r",stdin);
#endif
	long long N;
	scanf("%lld",&N);
	vector<vector<long long>> a(3-1+1,vector<long long>(N-1+1));
	for(int i = 0 ; i <= 3-1 ; i++){
		for(int j = 0 ; j <= N-1 ; j++){
			scanf("%lld",&a[i][j]);
		}
	}
	try {
		solve(N, a);
	} catch(int err) {
		puts("No");
		debug(err);
	}
	return 0;
}

