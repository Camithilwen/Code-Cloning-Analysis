#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define PI pair<int,int>
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
const int N=505,M=100005,x[4]={1,-1,0,0},y[4]={0,0,1,-1};
ll ans[N][N],tot;
int n,p[M],vis[M],q[M];
#define ld long double
ll lcm(ll x,ll y){
	if(x==0)return y; if(y==0)return x;//cout<<x<<" "<<y<<endl;
	//if((ld)x/__gcd(x,y)*y>(1e15))while(1);
	return x/__gcd(x,y)*y;
}
signed main(){
	n=500;
	for(int i=2;i<M;i++)if(!vis[i]){
		q[++tot]=i; for(int j=i;j<M;j+=i)vis[j]=1;
	}
	for(int i=1;i<=1000;i++)if(i&1)p[i]=q[(i+1)/2]; else p[i]=q[1001-i/2];
	int tx=248,ty=249;
	for(int i=1;i<=n*2;i+=2){
		if(i<=n){tx+=2; ty+=1;} else {tx++; if(i!=n+1)ty--;}
		int x=i<=n?1:i-n+1,y=i<=n?n-i+1:1;
		int t=min(n-x+1,n-y+1); 
		for(int j=0;j<t;j++){
			ans[x+j][y+j]=p[tx]*p[ty-j]; //if(x+j==500)cout<<y+j<<" "<<tx<<" "<<ty-j<<endl;
			//if(abs(x+j-2)+abs(y+j-2)==1)cout<<tx<<" "<<ty-j<<endl;
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if((i+j)%2==0){
	//cout<<i<<" "<<j<<endl;
		for(int k=0;k<4;k++)ans[i][j]=lcm(ans[i][j],ans[i+x[k]][j+y[k]]);
		ans[i][j]++;
	}
	//set<ll> s;
	//for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){ s.insert(ans[i][j]);}
	//cout<<s.size()<<endl;
	n=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			write(ans[i][j]); putchar(' ');
		}
		puts("");
	}
}
/*

 
*/