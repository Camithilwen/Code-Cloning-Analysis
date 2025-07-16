#include<bits/stdc++.h>

using namespace std;
#define REPP(i,a,b,c) for(int i=a; i<=b; i+=c)
#define REP(i,a,b) REPP(i,a,b,1)
#define REVV(i,a,b,c) for(int i=a; i>=b; i-=c)
#define REV(i,a,b) REVV(i,a,b,1)
#define FOR(i,a) REP(i,0,(int)a-1)
#define FORD(i,a) REV(i,(int)a-1,0)
#define MP make_pair
#define PB push_back
#define POB pop_back
#define FI first
#define SE second
typedef long long ll;
typedef unsigned long long ull;
typedef pair < int , int > pii;
typedef vector < int > vi;
typedef vector < pii > vii;
typedef vector < ll > vl;

const double PI = acos(-1);
const double EPS = 1e-9;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

///////////////////////////////////////////////////////

const int N = 1e5;

ll h,w,a,b;
ll fact[2*N + 5];
ll addMod(ll a, ll b){
	return (a +b ) % MOD;
}

ll mulMod(ll a, ll b){
	return (a*b) % MOD;
}

ll fast(ll a, ll b){
	if(b == 0) return 1;
	ll tmp = fast(a,b/2);
	tmp = mulMod(tmp,tmp);
	if(b % 2 == 1) tmp = mulMod(tmp,a);
	return tmp;
}

ll combin(int n, int k){
	return mulMod(fact[n], fast(mulMod(fact[n-k], fact[k]), MOD-2));
}

ll solve(){
	ll ret = 0;
	REP(i,1,h-a){
		int y = i;
		int x = b;
		ll val = combin(y+x-2,y-1);
		x++;
		val = mulMod(val, combin(h+w-y-x, h-y));
		ret = addMod(ret, val);
	}
	return ret;
}

int main(){
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	fact[0] = 1;
	REP(i,1,2*N) fact[i] = mulMod(fact[i-1], i);
	cin >> h >> w >> a >> b;
	cout << solve() << endl;
	return 0;
} 