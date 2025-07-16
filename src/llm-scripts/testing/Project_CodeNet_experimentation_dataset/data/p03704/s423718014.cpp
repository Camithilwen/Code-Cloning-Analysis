#include<cstdio>
#include<cmath>
typedef long long LL;
int D;
LL ans=0;
LL solve(int len){
	LL now=0,ans=1;
	for(int l=0,r=len-1;l<r;++l,--r){
		LL dw=(LL)pow(10,l),qaq=((LL)pow(10,r)-dw)/9;
		if(now<D){
			int wg=(D-now)/dw%10;
			now+=qaq*wg;
			ans=ans*(10-wg-(l==0));
		}else{
			int wg=(now-D)/dw%10;
			now-=qaq*wg;
			ans=ans*(10-wg-(l==0));
		}
	}
	if(len&1)ans*=10;
	if(now==D)return ans;
	return 0;
}
int main(){
	scanf("%d",&D);
	if(D%9)return puts("0"),0;
	D/=9;
	for(int i=1;i<=18;++i)
	if(pow(10,i)>D)ans+=solve(i);
	printf("%lld\n",ans);
	return 0;
}