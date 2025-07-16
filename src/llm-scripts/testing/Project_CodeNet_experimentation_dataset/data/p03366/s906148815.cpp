#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define ld long double
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
const int N=100005;
int dq,n,s,tot,q[N];
ll sum,ans;
int x[N],p[N];
signed main(){
	n=read(); s=read();
	for(int i=1;i<=n;i++){
		x[i]=read(); p[i]=read();
	}
	int l=1,r=n;
	int pos=lower_bound(&x[1],&x[n+1],s)-x;
	dq=0;
	if(pos==1){
		cout<<x[n]-s<<endl; return 0;
	}
	if(pos>n){
		cout<<s-x[1]<<endl; return 0;
	}
	if(p[1]<p[n]){dq=1; sum=p[1]; q[++tot]=x[1]; l++;}else {sum=p[n]; q[++tot]=x[n]; r--;}
	while(1){
		if(dq){
			if(r<pos)break;
			if(p[r]>sum){
				dq^=1; q[++tot]=x[r];
			}
			sum+=p[r];
			r--;
		}else{
			if(l>=pos)break;
			if(p[l]>=sum){
				dq^=1; q[++tot]=x[l];
			}
			sum+=p[l];
			l++;
		}
	}
	reverse(&q[1],&q[tot+1]);
	q[0]=s; for(int i=1;i<=tot;i++)ans+=abs(q[i]-q[i-1]);
	cout<<ans<<endl;
}