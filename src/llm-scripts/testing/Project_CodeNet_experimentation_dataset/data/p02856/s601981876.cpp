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

const int N = 2e5+10;
int n;

inline PA Get(int d,ll c){
	if (c==1) return {d,0};
	PA tmp=Get(d,c/2);
	tmp.se=(tmp.se*2+1+(tmp.fi*2>=10));
	if (tmp.fi*2>=10) tmp.fi=(tmp.fi*2)/10+(tmp.fi*2)%10;
		else tmp.fi*=2;
	if (c&1){
		tmp.se=tmp.se+1+(tmp.fi+d>=10);
		tmp.fi=(tmp.fi+d)/10+(tmp.fi+d)%10;
	}
	return tmp;
}

int main(){
	n=read();
	ll x=0,ans=0;
	For(i,1,n){
		ll d=read(),c=read();
		PA tmp=Get(d,c);
		ans+=tmp.se;
		if (i!=1) ans++;
		ans+=(x+tmp.fi>=10);
		x=(x+tmp.fi)/10+(x+tmp.fi)%10;
		//printf(" %lld %lld\n",x,ans);
	}
	printf("%lld\n",ans);
}