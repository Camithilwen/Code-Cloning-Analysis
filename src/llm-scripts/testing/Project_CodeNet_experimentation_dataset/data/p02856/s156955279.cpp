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

ll m;
map<ll,ll> ma;
Vi d,c;

bool ck(){
	ll sum = 0;
	rep(i,10){
		sum += ma[i];
		if(sum>=2)return true;
	}
	return false;
}

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	std::cout<<std::fixed<<std::setprecision(30);
	cin>>m;
	d.resize(m);
	c.resize(m);
	rep(i,m){
		cin>>d[i]>>c[i];
		ma[d[i]] += c[i];
	}
	ll ans = 0;
	while(ck()){
		rep(i,10){
			ll sum = 0;
			if(i==0){
				if(ma[i]<2)continue;
				ans += ma[i]-1;
				ma[i] = 1;
			}else{
				while(ma[i]>1){
				if(ma[i]*i<10){
					sum = ma[i]*i;
					ans += ma[i]-1;
					ma[i] = 0;
					ma[sum]++;
				}else{
					ll tmp = 10/i;
					if(10%i==0){
						tmp--;
					}
					tmp++;
					ll ret = ma[i]/tmp;
					ma[i]%=tmp;
					sum = tmp*i;
					sum = sum%10 + sum/10;
					ans += tmp*ret;
					ma[sum]+=ret;
				}
				}
			}
		}
		rep(i,10){
			if(ma[i]==0)continue;
			repi(j,i+1,10){
				if(ma[i]==0)continue;
				if(ma[j]==0)continue;
				ll sum = i+j;
				ans++;
				if(sum>=10)ans++;
				sum = sum/10 + sum%10;
				ma[i]--;
				ma[j]--;
				ma[sum]++;
			}
		}
	}
	print(ans);
	return 0;
}