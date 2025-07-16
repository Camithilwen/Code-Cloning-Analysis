#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int n,s,x[N];long long p[N],ans;
int main(){
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;++i)scanf("%d%lld",&x[i],&p[i]);
	for(int l=1,r=n,las=0;;){
		if(s<x[l]){ans+=x[r]-s;break;}
		if(x[r]<s){ans+=s-x[l];break;}
		if(p[l]>=p[r]){
			if(las!=1)las=1,ans+=x[r]-x[l];
			p[l]+=p[r];--r;
		}else{
			if(las!=2)las=2,ans+=x[r]-x[l];
			p[r]+=p[l];++l;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
