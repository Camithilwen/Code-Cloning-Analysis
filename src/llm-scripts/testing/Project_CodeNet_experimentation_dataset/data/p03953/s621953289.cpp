#include <bits/stdc++.h>
#define maxn 100010
#define ll long long
using namespace std;

int n,m,vis[maxn];

ll ans[maxn],a[maxn],k,cnt,q[maxn],pos[maxn];

template <class T>
void read(T &x){
	char s=getchar();int f=0;x=0;
	while(s<'0'||s>'9'){if(s=='-') f=1;s=getchar();}
	while(s>='0'&&s<='9') x=(x<<3)+(x<<1)+s-'0',s=getchar();
	x=f?-x:x;
}

int main(){
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
		pos[i]=1ll*i;
	}
	read(m);read(k);
	for(int i=n;i>=1;i--) a[i]=a[i]-a[i-1];
	for(int i=1,x;i<=m;i++){
		read(x);
		swap(pos[x],pos[x+1]);
	}
	for(int i=1;i<=n;i++){
		ll p=i;cnt=0;
		if(vis[i]) continue;
		q[++cnt]=p;
		vis[p]=1;
		p=pos[p];
		while(p!=i){
			q[++cnt]=p;
			vis[p]=1;
			p=pos[p];
		}
		for(int j=1;j<=cnt;j++) ans[q[j]]=a[q[(j+k-1)%cnt+1]];
	}
	for(int i=1;i<=n;i++){
		ans[i]+=ans[i-1];
		printf("%lld.0\n",ans[i]);
	}
	return 0;
}