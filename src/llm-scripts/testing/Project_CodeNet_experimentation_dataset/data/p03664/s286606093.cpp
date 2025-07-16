#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define poly vector<ll>
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
inline ll read(){
	ll x=0;char ch=getchar();bool d=1;
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') d=0;
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return d?x:-x;
}
inline void write(ll x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) write(x/10);
	putchar('0'+x%10);
}
inline void writeln(ll x){write(x);puts("");}
inline void writep(ll x){write(x);putchar(' ');}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=20,M=(1<<15)+5;
ll f[M][N],g[M];
vector<pii> v[N];
void upd(ll &x,ll y){
	x=max(x,y);
}
int main(){
	int n=read(),m=read();ll tot=0;
	For(i,1,m){
		int x=read(),y=read(),z=read();tot+=z;
		v[x].pb(mp(y,z));v[y].pb(mp(x,z));
	}
	int st=(1<<n)-1;
	For(s,0,st){
		For(i,1,n) if(!(s>>(i-1)&1)){
			if(!g[s|(1<<(i-1))]){
				g[s|(1<<(i-1))]=g[s];
				for(auto x:v[i]){
					if(s>>(x.fi-1)&1){
						g[s|(1<<(i-1))]+=x.se;
					}
				}
			}
		}
	}
	memset(f,-1,sizeof(f));
	f[1][1]=0;
	For(s,1,st){
		For(i,1,n) if(s>>(i-1)&1){
			if(f[s][i]==-1) continue;
			for(auto x:v[i]){
				if(!(s>>(x.fi-1)&1)){
					upd(f[s|(1<<(x.fi-1))][x.fi],f[s][i]+x.se);
				}
			}
			int ss=(st^s)|(1<<(i-1));
			for(int t=ss;t;t=(t-1)&ss){
				if(t>>(i-1)&1){
					upd(f[s|t][i],f[s][i]+g[t]);
				}
			}
		}
	}
	cout<<tot-f[st][n];
}