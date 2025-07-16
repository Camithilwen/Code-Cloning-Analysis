/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#include<bits/stdc++.h>
#define ll long long
#define inf 1000000005
#define put putchar('\n')
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,t) for (int i=head[t];i;i=Next[i])
#define sqr(x) ((x)*(x))
#define re register
#define mp make_pair
#define fi first
#define se second
#define pa pair<int,int>
#define pb push_back
#define be begin()
#define en end()
#define ret return puts("-1"),0;
#define mod 1000000007
#define N 500055
#define int ll
using namespace std;
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){char c=getchar();int tot=1;while ((c<'0'|| c>'9')&&c!='-') c=getchar();if (c=='-'){tot=-1;c=getchar();}
int sum=0;while (c>='0'&&c<='9'){sum=sum*10+c-'0';c=getchar();}return sum*tot;}
inline void wr(int x){if (x<0) {putchar('-');wr(-x);return;}if(x>=10)wr(x/10);putchar(x%10+'0');}
inline void wrn(int x){wr(x);put;}inline void wri(int x){wr(x);putchar(' ');}
inline void wrn(int x,int y){wri(x);wrn(y);}inline void wrn(int a,int b,int c){wri(a);wrn(b,c);}
int n,m,x[N],p[N],l,r,ans,s,tot,z[N];
signed main(){
	n=read();s=read();
	F(i,1,n){
		x[i]=read();p[i]=read();
	}
	l=1;r=n;
	while (x[l]<s&&x[r]>s&&l<r){
		if (p[l]>=p[r]){
			p[l]+=p[r];z[++tot]=r;r--;
		}
		else{
			p[r]+=p[l];z[++tot]=l;l++;
		}
	}
	if (s>x[r]) F(i,l,r) z[++tot]=i;
	else D(i,r,l) z[++tot]=i;
	ans+=abs(s-x[z[tot]]);
	D(i,tot,2) ans+=abs(x[z[i]]-x[z[i-1]]);
	wrn(ans);
	return 0;
}