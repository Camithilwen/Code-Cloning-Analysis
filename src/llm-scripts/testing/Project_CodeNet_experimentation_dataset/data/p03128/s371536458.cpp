#include "bits/stdc++.h"
using namespace std;
///////////////////////////////////////////
const long long int INF = 1LL<<60;
const long long int Mod = 1000000007;
using ll = long long int; using ci = const int;
using vi = vector<int>;  using Vi = vector<long long int>;
using P = pair<int, int>;  using PLL = pair<ll, ll>;
using matrix = vector<vector<ll>>;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define rep(i,N) for(ll i = 0; i < (ll)N; i++)
#define repi(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
template<class T>bool chmax(T &former, const T &b) { if (former<b) { former=b; return true; } return false; }
template<class T>bool chmin(T &former, const T &b) { if (b<former) { former=b; return true; } return false; }
template<class T>T sqar(T x){ return x*x; }//sqrt(x)は平方根;
#define Sort(v) std::sort(v.begin(), v.end(), std::greater<decltype(v[0])>()) //降順でVをソート
#define p_queue(v) priority_queue<v, vector<v>, greater<v> >
template<class T> inline void princ(T x){cout<<x<<" ";}; 
template<class T> inline void print(T x){cout<<x<<"\n";};
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
///////////////////////////////////////////////////////////////////////////////////

ll n,m;
Vi a;
ll cal(ll n){
	switch(n){
		case 1:
			return 2;
			break;
		case 2:
		case 3:
		case 5:
			return 5;
			break;
		case 4:
			return 4;
			break;
		case 6:
			return 6;
			break;
		case 7:
			return 3;
			break;
		case 8:
			return 7;
			break;
		case 9:
			return 6;
			break;
		default:
			return 0;
			break;
	}
}

vector<string> dp;

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	std::cout<<std::fixed<<std::setprecision(30);
	cin>>n>>m;
	a.resize(m);
	rep(i,m){
		cin>>a[i];
	}
	dp.resize(n+10,"-1");
	dp[0]="";
	rep(i,n){
		if(dp[i]=="-1")continue;
		rep(j,a.size()){
			ll tmp = i+cal(a[j]);
			string fig = dp[i]+(char)('0'+a[j]);
			string now = dp[tmp];
			if(now=="-1" || now.size()<fig.size()){
				dp[tmp] = fig;
			}else if(now.size()>fig.size()){

			}else{
				chmax(dp[tmp],fig);
			}
		}
	}
	print(dp[n]);
	return 0;
}