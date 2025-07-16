#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	long long n,k;
	cin>>n>>k;
	long double ch[200010];
	for(ll i=0;i<n;i++){
		cin>>ch[i];
	}
	long double ans=0;
	for(ll i=0;i<k;i++){
		long double now=ch[i];
		now=(ch[i]+1)/2;
		ans+=now;
	}
	//printf("%.10Lf\n",ans);	
	long double cnt=ans;
	for(ll i=0;i+k<n;i++){
		cnt+=-(ch[i]+1)/2+(ch[i+k]+1)/2;
		ans=max(ans,cnt);
	}
	printf("%.10Lf",ans);
	// your code goes here
	return 0;
}