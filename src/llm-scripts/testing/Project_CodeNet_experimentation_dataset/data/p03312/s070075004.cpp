#include <iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll sum[200010];
int bin_s(int l,int r) {
	ll g=(sum[l]+sum[r])/2;
	int ok=l,ng=r;
	while(ok+1<ng){
		int mid=(ok+ng)/2;
		if (sum[mid]<=g)ok=mid;
		else ng=mid;
	}
	if(g-sum[ok]<sum[ng]-g)return ok;
	else return ng;
}

int main() {
	int N;cin>>N;
	for(int i=0;i<N;++i){
		ll A; cin>>A;
		sum[i+1]=sum[i]+A;
	}
	ll ans=1e15;
	for(int i=2;i+2<=N;++i){
		int form=bin_s(0,i),latt=bin_s(i,N);
		ll mn=min(sum[form],sum[i]-sum[form]),mx=max(sum[form],sum[i]-sum[form]);
		mn=min(mn,min(sum[latt]-sum[i],sum[N]-sum[latt]));
		mx=max(mx,max(sum[latt]-sum[i],sum[N]-sum[latt]));
		ans=min(ans,mx-mn);
	}
	cout<<ans<<endl;
	return 0;
}