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
const int N=1e5+5;
int fa[N],m,ans;
poly v[N];
int dfs(int u,int dep){
	int mx=dep;
	for(auto k:v[u]){
		mx=max(mx,dfs(k,dep+1));
	}
	if(fa[u]!=1&&mx-dep==m-1) return ans++,0;
	return mx;
}
int main(){
	int n=read();m=read();
	For(i,1,n) fa[i]=read();
	For(i,2,n) v[fa[i]].pb(i);
	if(fa[1]!=1) ans=fa[1]=1;
	dfs(1,0);cout<<ans;
}