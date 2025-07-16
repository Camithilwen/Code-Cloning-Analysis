#include<stdio.h>
#include<stdlib.h>
#define ll long long

const int Inf=1e9+10;
ll jiu[19];

int gi(){
	int sum=0,f=1;char ch=getchar();
	while(ch>'9' || ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9' && ch>='0'){sum=sum*10+ch-'0';ch=getchar();}
	return sum*f;
}

int d;
ll ans;

ll sm[20];

void dfs(int i,int n,ll N,ll revN,ll cif){
	if(i>n){
		if(revN-N==d){
			ans++;
		}
		return;
	}
	ll maxd=revN*sm[n-i+1]+1-N-sm[n-i+1];
	ll mind=revN*sm[n-i+1]+jiu[n-i+1]-(jiu[n-i+1]*sm[i-1]+N);
	if(N && revN-N+maxd<d)return;
	if(N && revN-N+mind>d)return;
	for(int j=9;j>=(i==n)?1:0;j--)
		dfs(i+1,n,N+j*cif,revN*10+j,cif*10);
}

int main(){
	int i,j,k,n,m;
	scanf("%d",&d);
	if(d%9){
		puts("0");
		return 0;
	}
	d/=9;
	ll len=1,ini=0;
	for(i=1;i<=18;i++)
		sm[i]=sm[i-1]*10;
	for(i=1;i<=17;i++){
		ll tmp=1,D=d;
		ini=ini*10+1;
		ll base=ini,lten=len,rten=1;
		for(int j=0;j<=(i>>1);j++){
			tmp*=10-abs(D%(rten*10)/rten)-(!j?1:0);
			D-=base*(D%(rten*10)/rten);
			base-=lten+rten;
			lten/=10;
			rten*=10;
		}
		len*=10;
		if(!D)ans+=tmp;
	}
	printf("%lld\n",ans);
	return 0;
}
