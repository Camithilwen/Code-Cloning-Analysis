#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<functional>
#include<set>
#include<map>
using namespace std;
#define rep(i,l,r) for(register int i=(l);i<=(r);++i)
#define repdo(i,l,r) for(register int i=(l);i>=(r);--i)
#define il inline
typedef double db;
typedef long long ll;

//---------------------------------------
namespace ubospica{

const int nsz=205,vsz=1e5+50;
const ll nmod=1e9+7;
int n;
ll x,li[nsz];
ll ans,dp[vsz];
ll inv[vsz]{0,1};
void init(int bnd){rep(i,2,bnd)inv[i]=inv[nmod%i]*((ll)nmod-nmod/i)%nmod;}//be aware of overflow!

void add(ll &a,ll b){a=(a+b)%nmod;}
void mul(ll &a,ll b){a=a*b%nmod;}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>x;
	rep(i,1,n)cin>>li[i];
	sort(li+1,li+n+1,greater<int>());
	init(1e5+5);
	ll tmp;
	dp[x]=1;
	rep(i,1,n){
		rep(j,0,x){
			tmp=dp[j],dp[j]=0;
			add(dp[j%li[i]],tmp*inv[n-i+1]);
			add(dp[j],tmp*(n-i)%nmod*inv[n-i+1]);
		}
	}
	ans=0;
	rep(i,0,x)
		add(ans,i*dp[i]);
	rep(i,1,n)mul(ans,i);
	cout<<ans<<'\n';
	return 0;
}

}

int main(){return ubospica::main();}









//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);




