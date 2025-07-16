#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define lowbit(i) i&-i
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
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
inline ull rnd(){
	ull ans=0; For(i,0,5)ans=ans<<15^rand(); return ans;
}
ll ycl[20],f[10],ans,d,L;
ll xqz(ll x,ll y){
	if(x>=0)return x/y;
	x=-x;
	x--; return -x/y-1;
}
void dfs(int p,ll xs,ll d){
	if(p==L/2){
		if(d==0)ans+=xs*((L&1)?10:1); return;
	}
	ll cz=ycl[L-1-p]-ycl[p],t=xqz(d,cz);
	//cout<<d<<" "<<cz<<" "<<t<<" "<<L/2<<endl;
	if(abs(t)<=9){
		dfs(p+1,xs*(f[abs(t)]-(p==0&&t>=0)),d-t*cz);
	}
	t++;
	if(abs(t)<=9){
		dfs(p+1,xs*(f[abs(t)]-(p==0&&t>=0)),d-t*cz);
	}
}
void get(int len,ll d){
	L=len;
	dfs(0,1,d);
}
int main(){
	For(i,0,9)For(j,0,i)f[i-j]++;
	d=read();
	int ws=1;
	For(i,ycl[0]=1,18){ycl[i]=ycl[i-1]*10; if(d>=ycl[i])ws++;}
	//get(2,d); cerr<<ans<<endl; return 0;
	For(i,max(2,ws),2*ws){
		get(i,d);
	}
	cout<<ans<<endl;
}