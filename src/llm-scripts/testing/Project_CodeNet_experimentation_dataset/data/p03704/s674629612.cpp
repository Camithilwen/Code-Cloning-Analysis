#include<cstdio>
#define int long long
int D;
int calc(int A,int t,int first){
	if(!t)return A==0;
	int v=(A%10+10)%10;
	int res=0;
	res+=(10-v-first)*calc((A-t*v)/10,t/100,0);
	res+=(v-first)*calc((A+(10-v)*t)/10,t/100,0);
	return res;	
}
signed main() {
    scanf("%lld",&D);
    if(D%9)return puts("0"),0;
	D/=9;
	int ans=0,p10=10;
	for(int i=2;i<=18;i++){
		int tot=(i%2)*9+1;
		ans+=tot*calc(D,p10/9,1);
		p10*=10;
	} 
	printf("%lld\n",ans);
}