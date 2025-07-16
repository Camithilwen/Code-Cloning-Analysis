#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
#define N 500005
#define ll long long
ll n;
double a[N];
ll cnt2[N],cnt5[N],ten[N];
ll sum[5005][5005],ans;
ll len1,len2;
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lf",a+i);
		ten[i]=9;
		ll JZY=llround(a[i]*1000000000);
//		printf("%lld\n",JZY);
		while(JZY%2==0&&JZY) JZY>>=1,cnt2[i]++;
		while(JZY%5==0&&JZY) JZY/=5,cnt5[i]++;
//		for(ll j=0,mul=1;j<=10;j++,mul*=10){
////			if(i==n)printf("read %lf %lld %lld\n",a[i]*mul,(ll)(a[i]*mul),(a[i]*mul)-(ll)(a[i]*mul)<1e-9);
//			if(a[i]*mul==llround(a[i]*mul)){
//				ten[i]=j;
////				printf("%lld %lld %lld\n",cnt2[i],cnt5[i],ten[i]);
//				break;
//			} 
//		}
	}
	for(ll i=1;i<=n;i++)
		len1=max(len1,cnt2[i]),len2=max(len2,cnt5[i]);
	len1+=20,len2+=20;
//	printf("border %lld %lld\n",len1,len2);
	for(ll i=1;i<=n;i++){
//		printf("num %lf\n",a[i]);
//		printf("check %lld %lld\n",ten[i]-cnt2[i]+10,ten[i]-cnt5[i]+10);
		for(ll x=ten[i]-cnt2[i]+20;x<=len1;x++)
			for(ll y=ten[i]-cnt5[i]+20;y<=len2;y++)
				ans+=sum[x][y];
//		printf("add %lld %lld\n",cnt2[i]-ten[i]+10,cnt5[i]-ten[i]+10);
		sum[cnt2[i]-ten[i]+20][cnt5[i]-ten[i]+20]++;
	}
	printf("%lld",ans);
}
/*
7
0.9
1
1
1.25
2.3
5
70
*/