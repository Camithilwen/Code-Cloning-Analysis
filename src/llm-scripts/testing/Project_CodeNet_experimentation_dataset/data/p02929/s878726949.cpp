#include <bits/stdc++.h>
#define FOR(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define FORUL(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#define FORULE(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)
#if defined(_MSC_VER) || __cplusplus > 199711L
#define AUTOVAR(newvar,v) auto newvar = (v)
#else
#define AUTOVAR(newvar,v) __typeof(newvar) r = (v)
#endif
#define PB(x) push_back(x)
#define MP(x,y) make_pair((x),(y))
#define MEMSET(m,v) memset(m,v,sizeof(m))

typedef long long				 ll;
typedef unsigned long long		ull;

#define DEBUG 0

#if DEBUG
#define DOUT cout<<"["<<__LINE__<<"]:"
#else
#define DOUT 0 && cout
#endif

using namespace std;

#define MAX_N (1000*100)
#define MOD (ll(1E9+7))
int N;
string S;

int W,B;

ll kai[MAX_N+5];

ll kaijo(int n)
{
	DOUT<<"---- kaijo("<<n<<") ----"<<endl;
	if(kai[n]!=0) {
		return kai[n];
	}
	ll i=n;
	for(;i>=1; i--) {
		if (kai[i]!=0) {
			break;
		}
	}
	ll ret = kai[i];
	for(;i<n;i++) {
		DOUT<<"(i+1)* kai[i]=="<<((i+1)* kai[i])<<endl;
		kai[i+1] = ((i+1)* kai[i])%MOD;
	}
	return (kai[n])%MOD;
}

int main(int argc, char *argv[])
{
	kai[0]=1;
	kai[1]=1;
	ios::sync_with_stdio(false);
	cin >> N;
	cin >> S;
	FOR(n,2*N) {
		DOUT << "S["<<n<<"]=="<<S[n]<<endl;
		DOUT << "(2*N-n)%2=="<<(2*N-n)%2<<endl;
		if((2*N-n)%2==0) {
			if(S[n]=='B') { S[n]='W'; }
			else if(S[n]=='W') { S[n]='B'; }
		}
		DOUT << "S["<<n<<"]=="<<S[n]<<endl;
	}
	W=0;
	B=0;
	FOR(n,2*N) {
		DOUT << "S["<<n<<"]=="<<S[n]<<endl;
		if(S[n]=='B') { B++; }
		else if(S[n]=='W') { W++; }
	}
	if(B!=W) {
		cout << 0 << endl;
		return 0;
	}

	int count = 0;
	ll ans = 1;
	count = 0;
	FOR(n,2*N) {
		DOUT << "S["<<n<<"]=="<<S[n]<<", ans="<<ans<<", count=="<<count<<endl;
		if(S[n]=='B') {
			DOUT<<"ans*count="<<(ans*count)%MOD<<endl;
			ans = ans*count%MOD;
			count--;
		}
		else {
			count++;
		}
		DOUT << "ans=="<<ans<<", count=="<<count<<endl;
	}

	cout << ans*kaijo(N)%MOD << endl;

	DOUT << kaijo(1000*100) << endl;

	return 0;
}


