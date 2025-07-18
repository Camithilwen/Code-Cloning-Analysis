//pragma
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define YOU using
#define DONT namespace
#define SAY std

YOU DONT SAY;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define REPP(i,a,b,d) for(int i=a;i<=b;i+=d)
#define REP(i,a,b) REPP(i,a,b,1)
#define REVV(i,a,b,d) for(int i=a;i>=b;i-=d)
#define REV(i,a,b) REVV(i,a,b,1)

#define FOR(i,a) for(int i=0; i<a; i++)
#define FORD(i,a) for(int i=(int)a-1; i>=0; i--)

#define pb push_back
#define F first
#define S second

const int OO = 1e9;
const ll INF = 1e18;

const int irand(int lo,int hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

const ll lrand(ll lo,ll hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

#define getc getchar
template<typename T>
T getnum(){
	int sign = 1;
	T ret = 0;
	char c;

	do{
		c = getc();
	}while(c == ' ' || c == '\n');
	if(c == '-')sign = -1;
	else ret = c-'0';
	while(1){
		c = getc();
		if(c < '0' || c > '9')break;
		ret = 10*ret + c-'0';
	}
	return sign * ret;
}

inline void ini(int& x){
	x = getnum<int>();
}

inline void scani(int& x){
	scanf("%d",&x);
}

//end of macro

const ll MOD = 1e9 + 7;
inline ll addmod(ll a, ll b){
	if(a+b<MOD)return a+b;
	return a+b-MOD;
}
inline ll mulmod(ll a, ll b){
	return (a*b)%MOD;
}
inline ll expmod(ll a, ll e){
	ll ret = 1;
	while(e){
		if(e&1)ret = mulmod(ret, a);
		a = mulmod(a, a);
		e >>= 1;
	}
	return ret;
}
inline ll divmod(ll a, ll b){
	return mulmod(a, expmod(b, MOD-2));
}

int n,x,y,z;
int tmask;
int m1, m2, m3;

int memo[40][1<<16][2];
int dp(int now, int mask, bool ok){
	if(now == n)return ok;

	int& ret = memo[now][mask][ok];
	if(ret != -1)return ret;
	ret = 0;

	int nmask = mask<<1|1;
	REP(i,1,10){
		bool nok = ok;
		if((nmask & m1) && (nmask & m2) && (nmask & m3)){
			nok = true;
		}
		ret = addmod(ret, dp(now+1, nmask & tmask, nok));
		nmask <<= 1;
	}
	// if(ret > 0){
	// 	printf("%d %d %d = %d\n",now,mask,ok,ret);
	// }
	return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    cin>>n>>x>>y>>z;
    tmask = (1 << (x + y + z - 1)) - 1;
    m1 = 1<<(z-1);
    m2 = 1<<(y+z-1);
    m3 = 1<<(x+y+z-1);

    memset(memo, -1, sizeof memo);
    cout << dp(0, 0, false) << endl;

    return 0;
}
