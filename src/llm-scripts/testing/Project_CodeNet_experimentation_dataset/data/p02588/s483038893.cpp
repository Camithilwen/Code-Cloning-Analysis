#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<ll,ll>
#define poly vector<ll>
#define mem(a) memset((a),0,sizeof(a))
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x.size()))
#define re resize
#define PB pop_back
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
ll rnd(){
	ull ans=0;
	For(i,0,4)ans=ans<<15^rand();
	return ans%((ull)1<<63);
}
const ll fm=1e9;
int n;
ll ans;
map<pair<PI,PI>,ll> M;
bool zc(PI a,PI b){
	return a.fi>=b.fi&&a.se>=b.se;
}
bool bao(pair<PI,PI> a,pair<PI,PI> b){
	return zc(a.fi,b.se)&&zc(b.fi,a.se);
}
PI get(ll t){
	PI a=mp(0,0);
	while(t%2==0){
		t/=2; a.fi++;
	}
	while(t%5==0){
		t/=5; a.se++;
	}
	return a;
}
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	n=read();
	For(i,1,n){
		ll a;
		cin>>a;
		a=a*fm;
		if(getchar()=='.'){
			ll b=0;
			string s;
			cin>>s;
			For(j,0,s.size()-1)b=b*10+s[j]-'0';
			For(j,1,9-s.size())b*=10;
			a+=b;
		}
		ll x=a,gc=__gcd(x,fm),y=fm/gc;
		x/=gc;
		PI X=get(x),Y=get(y);
		M[mp(X,Y)]++;
		if(y==1)ans--;
	}
	for(auto i:M){
		for(auto j:M)if(bao(i.fi,j.fi)){
			ans+=i.se*j.se;
		}
	}
	cout<<ans/2<<endl;
}
