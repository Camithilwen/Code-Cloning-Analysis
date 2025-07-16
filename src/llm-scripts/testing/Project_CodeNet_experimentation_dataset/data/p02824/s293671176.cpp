#include<bits/stdc++.h>
using namespace std;
template<typename T>inline T read(){
	T f=0,x=0;char c=getchar();
	while(!isdigit(c)) f=c=='-',c=getchar();
	while(isdigit(c)) x=x*10+c-48,c=getchar();
	return f?-x:x;
}
#define int long long
namespace run{
	const int N=2e5+9;
	int a[N],m,v,p,n,ans,sum[N];
	int main(){
		n=read<int>(),m=read<int>(),v=read<int>(),ans=p=read<int>();
		for(int i=1;i<=n;i++) a[i]=read<int>();
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	//	for(int i=1;i<=n;i++) cout<<a[i]<<" ";cout<<endl;
		for(int i=1;i<=n-p;i++){
			if(m+a[i]<a[n-p+1]) continue;
			else{
				int tmp=(p-1+i)*m+((n-p+1-i)*(a[i]+m)-(sum[n-p+1]-sum[i]));
			//	cout<<tmp<<endl;
				if(tmp>=m*v) ans++;
			}
		}
		printf("%lld\n",ans);
		return 0;
	}
}
#undef int
int main(){
#ifdef my
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	return run::main();
}