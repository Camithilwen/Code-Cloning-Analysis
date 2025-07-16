#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
#define mem(a) memset((a),0,sizeof(a))
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
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=305;
int n,a[N<<1][N<<1];
void hf(int x,int de){
	int t=0;
	while(x%4==0){x/=4; t++;}
	if(x%4==2){
		For(i,0,2*n-1){
			For(j,0,2*n-1)if(i>>t&1)a[i][j]|=de;
		}
	}else {
		For(i,0,2*n-1){
			For(j,0,2*n-1)if(((i>>t)+(j>>t))&1)a[i][j]|=de;
		}
	}
}
vector<PI> v[4];
int main(){
	n=read(); int d1=read(),d2=read();
	hf(d1,1);
	hf(d2,2);
	For(i,0,2*n-1)For(j,0,2*n-1)v[a[i][j]].pb(mp(i,j));
	For(i,0,3)if(v[i].size()>=n*n){
		For(j,0,n*n-1)wri(v[i][j].fi),writeln(v[i][j].se); return 0;
	}
}