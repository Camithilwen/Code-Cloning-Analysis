#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) printf("%lld ",i);puts("")
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define fil(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pa;
typedef pair<ll,ll> PA;
typedef vector<int> poly;
inline ll read(){
    ll x=0,f=1;char c=getchar();
    while ((c<'0'||c>'9')&&(c!='-')) c=getchar();
    if (c=='-') f=-1,c=getchar();
    while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*f;
}

const int N = 1<<20|3, mod = 1e9+7;
int n,maxn,a[N],pre[N],s[N],s2[N],f[N];
poly v[N];

inline int Mod(int x){
	return x>=mod?x-mod:x;
}

int main(){
	n=read(),pre[0]=1;
	For(i,1,n){
		a[i]=read(),a[i]=a[i-1]^a[i],v[a[i]].pb(i);
		pre[i]=pre[i-1]+(a[i]==0);
	}
	int ans=0;
	if (a[n]==0){
		int x=1;
		For(i,1,pre[n]-2) x=x*2%mod;
		ans=Mod(ans+x);
	}
	FOR(i,1,1<<20) if (!v[i].empty()){
		f[0]=1,s[0]=1,s2[0]=pre[v[i][0]];
		FOR(j,1,siz(v[i])){
			f[j]=(1ll*s[j-1]*pre[v[i][j]]+mod-s2[j-1]+1)%mod;
			s[j]=Mod(s[j-1]+f[j]),s2[j]=(s2[j-1]+1ll*f[j]*pre[v[i][j]])%mod;
		}
		if (a[n]==0) ans=Mod(ans+s[siz(v[i])-1]);
		else if (a[n]==i) ans=Mod(ans+f[siz(v[i])-1]);
	}
	printf("%d\n",ans);
}