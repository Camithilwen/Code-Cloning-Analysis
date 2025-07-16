#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=100005;
int n,m,v,p,a[maxn],ans;
ll b[maxn];
inline int cmp1(int x,int y){
	return x>y;
}
inline int read(){
	int res=0,f_f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f_f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') res=(res<<3)+(res<<1)-'0'+ch,ch=getchar();
	return res*f_f;
}
int main(){
	n=read(),m=read(),v=read(),p=read(),ans=p;
	for (int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1,cmp1);
	for (int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for (int i=p+1;i<=n;i++){
		if(a[i]+m<a[p]) continue;
		ll delta=1ll*max(0,v-(p-1)-(n-i+1))*m;
		if(delta==0){
			ans++;
			continue;
		}
		ll w=1ll*m*(i-p)-(b[i-1]-b[p-1]-1ll*a[i]*(i-p));
		if(w>=delta) ans++;
	}
	printf("%d\n",ans);
	return 0;
}