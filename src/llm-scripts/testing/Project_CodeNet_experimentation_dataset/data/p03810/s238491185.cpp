#include<bits/stdc++.h>
using namespace std;
const int maxn=100010,mod=998244353;
const char str[2][10]={"First","Second"};
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,a[maxn]; 
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
	n=read();
	FOR(i,1,n) a[i]=read();
	int t=0;
	while(true){
		int cnt1=0,cnte=0;
		FOR(i,1,n){
			if(a[i]==1) cnt1++;
			if(a[i]%2==0) cnte++;
		}
		if(cnte!=n-1 || cnt1==1){puts(cnte%2?str[t]:str[t^1]);break;}
		FOR(i,1,n) if(a[i]%2!=0){a[i]--;break;}
		int g=0;
		FOR(i,1,n) g=gcd(g,a[i]);
		FOR(i,1,n) a[i]/=g;
		t^=1;
	}
}
// coming soon 2020.5.11