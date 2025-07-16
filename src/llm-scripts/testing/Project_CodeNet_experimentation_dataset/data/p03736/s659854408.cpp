#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=200005;
int n,q,x,y,a[N];
ll sum[N],dp[N],ans;
#define lowbit(i) i&-i
struct BIT{
	ll c[N];
	void change(int pos,ll de){
		for(int i=pos;i<=n;i+=lowbit(i))c[i]=min(c[i],de);
	}
	ll ask(int pos){
		ll ans=4e18;
		for(int i=pos;i;i-=lowbit(i))ans=min(ans,c[i]);
		return ans;
	}
}T[2];
void insert(ll de,int pos){
	T[0].change(pos,de-pos);
	T[1].change(n-pos+1,de+pos);
}
int main(){
	n=read(); q=read(); x=read(); y=read();
	for(int i=1;i<=q;i++)a[i]=read();
	for(int i=2;i<=q;i++)sum[i]=sum[i-1]+abs(a[i-1]-a[i]);
	for(int i=1;i<=n;i++)T[0].c[i]=T[1].c[i]=4e18;
	insert(abs(x-a[1]),y);
	insert(abs(y-a[1]),x);
	ans=sum[q]+min(abs(x-a[1]),abs(y-a[1]));
	for(int i=1;i<q;i++){
		dp[i]=min(T[0].ask(a[i+1])+sum[i]+a[i+1],T[1].ask(n-a[i+1]+1)+sum[i]-a[i+1]);
		//if(i==3)cout<<dp[i]<<" "<<i<<" "<<T[0].ask(a[i+1])<<endl;
		//cout<<ans<<endl;
		ans=min(ans,dp[i]+sum[q]-sum[i+1]);
		insert(dp[i]-sum[i+1],a[i]);
	}
	cout<<ans<<endl;
}
/*
dp[i]=dp[j]+sum[i]-sum[j+1]+abs(a[i+1]-a[j])
*/