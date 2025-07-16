#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long ll;
const int N = 1e5+5;
ll minnx[N];
int n;
struct node {
	ll l,r;
}a[N],s[N];

bool cmp(node a,node b){
	return a.l>b.l;
}

int main(){
	cin>>n;
	ll maxx=0,minn=1e17,maxlen=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].r;
		maxx=max(maxx,a[i].l);
		minn=min(minn,a[i].r);
		maxlen=max(maxlen,a[i].r-a[i].l+1);
	}
	ll ans1=maxlen+max(minn-maxx+1,0ll);
	for(int i=1;i<=n;i++){
		s[i].l=max(minn-a[i].l+1,0ll);
		s[i].r=max(a[i].r-maxx+1,0ll);
	}
	sort(s+1,s+n+1,cmp);
	minnx[n+1]=1e18;
	for(int i=n;i>=1;i--) minnx[i]=min(minnx[i+1],s[i].r);
	ll ans2=0;
	for(int i=1;i<=n-1;i++){
//		cout<<s[i].l<<" "<<s[i].r<<endl;
		ans2=max(ans2,s[i].l+minnx[i+1]);
//		cout<<ans2<<endl;
	}
//	cout<<ans1<<" "<<ans2<<endl;
	cout<<max(ans1,ans2)<<endl;
	
	return 0;
}