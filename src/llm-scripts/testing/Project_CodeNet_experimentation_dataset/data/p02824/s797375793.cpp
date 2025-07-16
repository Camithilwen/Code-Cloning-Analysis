#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+10;
int n,m,a[N],ans,v,p;
LL sum[N];
bool ck(int x){
	if(n-x+1<=p)return true;
	if(x+p-1>=v){
		int pos=a[n-p+1];
		return (a[x]+m>=pos);
	}
	int lft=v-(x+p-1);
	LL mid=0,num=0;
	for(int i=x+1;i<=n-p+1;i++){
		if(a[i]>a[x]+m)return false;
		mid+=a[i];num++;
	}
	mid+=1ll*m*lft;
	LL tmp=(mid+num-1)/num;
	//cout<<x<<" "<<lft<<" "<<a[x]+m<<" "<<tmp<<endl;
	return a[x]+m>=tmp;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&v,&p);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int L=1,R=n;
	while(L<=R){
		int mid=(L+R)>>1;
		if(ck(mid))ans=mid,R=mid-1;
		else L=mid+1;
	}
	printf("%d\n",(n-ans+1));
}
	