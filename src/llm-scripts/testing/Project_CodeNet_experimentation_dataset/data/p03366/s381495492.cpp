#include <cstdio>
long long x[100001],p[100001],ans,n,s;
int main(){
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&p[i]);
	int i=1,j=n;
	while(i<=j){
		if(s<=x[i]){
			printf("%lld",x[j]-s+ans);
			return 0;
		}else if(s>=x[j]){
			printf("%lld",ans+s-x[i]);
			return 0;
		}
		if(p[i]>=p[j]){
			ans+=x[j]-x[i];
			while(i<j && p[i]>=p[j])p[i]+=p[j--];
		}else{
			ans+=x[j]-x[i];
			while(i<j && p[i]<p[j])p[j]+=p[i++];
		}
	}
}