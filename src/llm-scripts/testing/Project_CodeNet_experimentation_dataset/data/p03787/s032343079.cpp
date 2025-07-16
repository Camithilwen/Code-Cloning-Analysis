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
int n,m,vis[N],co[N],I,P,Q;
int nedge,Next[N*2],head[N],to[N*2];
#define V to[i]
void add(int a,int b){
	Next[++nedge]=head[a];head[a]=nedge;to[nedge]=b;
}
void add_ne(int a,int b){add(a,b);add(b,a);}
bool dfs(int x){
	vis[x]=1;
	bool num=1;
	go(i,x){
		if (vis[V]) num&=(co[x]!=co[V]);
		else co[V]=co[x]^1,num&=dfs(V);
	}
	return num;
}
signed main(){
	n=read();m=read();
	F(i,1,m){
		add_ne(read(),read());
	}
	F(i,1,n){
		if (!vis[i]){
			if (head[i]==0) I++;
			else if (dfs(i)) Q++;
			else P++;
		}
	}
	wrn(I*I+I*(n-I)*2+P*Q*2+P*P+Q*Q*2);
	return 0;
}