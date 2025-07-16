#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_end=(a);i>=i##_end;--i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define foe(i,a) for(__typeof(a.begin())i=a.begin();i!=a.end();++i)
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
typedef double ld;
typedef long long L;
typedef vector<int> VI;
typedef pair<int,int> pa;
#ifdef flukehn
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
const int N=1e6+11,mo=998244353;
int fpow(int a,int b){
	int r=1;
	for(;b;b>>=1,a=1ll*a*a%mo)
		if(b&1)r=1ll*r*a%mo;
	return r;
}
int inv(int x){return fpow(x,mo-2);}
int jc[N+1],jcv[N+1];
int C(int a,int b){
	return a<b?0:1ll*jc[a]*jcv[b]%mo*jcv[a-b]%mo;
}
int n,m;
int main(){
#ifdef flukehn
	freopen("c.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	jc[0]=1;
	rep(i,1,N)jc[i]=1ll*jc[i-1]*i%mo;
	jcv[N]=inv(jc[N]);
	per(i,1,N)jcv[i-1]=1ll*jcv[i]*i%mo;
	cin>>n>>m;
	if(n<m)swap(n,m);
	int ans=0;
	rep(i,1,m){
		ans=(ans+1ll*C(2*i,i)*C(n+m-2*i,n-i))%mo;
	}
	ans=1ll*ans*inv(C(n+m,n))%mo;
	ans=1ll*ans*inv(2)%mo;
	printf("%d\n",(ans+n)%mo);
}
