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

ll f[100][100];

int main(){
	int n=read();
	For(i,1,n){
		double x;
		scanf("%lf",&x);
		ll y=(ll)(x*1e9+0.5);
		int a=0,b=0;
		while (y%2==0) y/=2,a++;
		while (y%5==0) y/=5,b++;
		f[a][b]++;
	}
	ll ans=0,ans2=0;
	For(i,0,60) For(j,0,60) if (f[i][j]){
		For(_i,0,60) For(_j,0,60) if (f[_i][_j]&&min(i+_i,j+_j)>=18){
			if (i!=_i||j!=_j) ans+=f[i][j]*f[_i][_j];
				else ans2+=f[i][j]*(f[i][j]-1)/2;
		}
	}
	printf("%lld\n",ans/2+ans2);
}