#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x); i<=(y); i++)
#define ll long long
#define ld long double
#define inf 1000000000
#define N 100005
int n,s; ll a[N],b[N],ans;
int main(){
	scanf("%d%d",&n,&s);
	rep (i,1,n) scanf("%d%d",&a[i],&b[i]);
	int l=1,r=n; ans=0;
	while (l<=r){
		if (s<=a[l]){ ans+=a[r]-s; break; }
		if (s>=a[r]){ ans+=s-a[l]; break; }
		if (b[l]>=b[r]){
			ans+=a[r]-a[l];
			while (l<r && b[l]>=b[r]) b[l]+=b[r--];
		} else{
			ans+=a[r]-a[l];
			while (l<r && b[l]<b[r]) b[r]+=b[l++];
		}
	}
	printf("%lld\n",ans);
	return 0;
}