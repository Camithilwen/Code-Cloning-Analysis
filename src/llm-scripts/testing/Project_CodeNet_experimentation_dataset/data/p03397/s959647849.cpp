#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(a,b,c) for (int a=b;a<=c;a++)
#define per(a,b,c) for (int a=b;a>=c;a--)
#define go(u) for (int o=ft[u],v;v=E[o].t,o;o=E[o].n)
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> par;
typedef double dob;
/*
0:
1:0
2:00
3:1
4:10
5:100
6:11
*/
const int N=300010,P=1000000007;
int n,g[7],f[7],h[7];
char s[N];
void add(int &x,int y){x=(x+y)%P;}
void tran(int k){
	memset(g,0,sizeof(g));
	memset(h,0,sizeof(h));
	add(g[1],f[0]);
	add(g[2],f[1]);
	add(g[1],f[2]);
	add(g[4],f[3]);
	add(g[5],f[4]);
	add(g[4],f[5]);
	add(g[6],f[6]);
	
	add(h[3],f[0]);
	add(h[0],f[1]);
	add(h[1],f[2]);
	add(h[6],f[3]);
	add(h[3],f[4]);
	add(h[4],f[5]);
	add(h[6],f[6]);
	if (k==0) swap(f,g); else
	if (k==1) swap(f,h); else{
		rep(i,0,6) add(g[i],h[i]);
		swap(f,g);
	}
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	f[0]=1;
	rep(i,1,n) tran(s[i]=='?'?2:s[i]-'0');
	LL ans=f[6]+f[3];
	ans=(ans%P+P)%P;
	printf("%lld\n",ans);
	return 0;
}
