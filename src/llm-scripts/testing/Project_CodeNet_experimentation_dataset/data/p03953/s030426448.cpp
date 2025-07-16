#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define poly vector<ll>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
inline char gc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x=0;char ch=gc();bool positive=1;
	for(;!isdigit(ch);ch=gc()) if(ch=='-') positive=0;
	for(;isdigit(ch);ch=gc()) x=x*10+ch-'0';
	return positive?x:-x;
}
inline void write(ll x){
	if(x<0){
		x=-x;putchar('-');
	}
	if(x>=10) write(x/10);
	putchar('0'+x%10);
}
inline void writeln(ll x){write(x);puts("");}
inline void writep(ll x){write(x);putchar(' ');}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=1e5+5;
int a[N],nxt[65][N];
ll id[N];
int main(){
	int n=read();
	For(i,1,n) a[i]=read(),id[i]=i;
	int m=read();ll k=read();
	For(i,1,m){
		int x=read();
		swap(id[x],id[x+1]);
	}
	For(i,1,n) nxt[0][i]=id[i];
	For(i,1,63){
		For(j,1,n) nxt[i][j]=nxt[i-1][nxt[i-1][j]];
	}
	For(i,1,n){
		id[i]=i;
		Rep(j,63,0) if(k>>j&1) id[i]=nxt[j][id[i]];
		id[i]=a[id[i]]-a[id[i]-1];
	}
	For(i,1,n){
		id[i]+=id[i-1];
		printf("%lld.0\n",id[i]);
	}
}