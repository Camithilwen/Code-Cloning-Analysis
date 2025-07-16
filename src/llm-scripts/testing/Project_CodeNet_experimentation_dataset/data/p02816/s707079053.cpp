#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int n,a[200005],b[200005],p[600005],dp[600005]; 
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];for(int i=0;i<n;i++)cin>>b[i];
	for(int i=0;i<n;i++){
		p[i]=b[i]^b[(i+1)%n];
		p[i+n]=a[i]^a[(i+1)%n];p[i+n*2]=p[i+n];
	}
	int l=0;
	FOR(i,1,n*3-1){
		if(i+dp[i-l]<dp[l]+l){
			dp[i]=dp[i-l];
		}else{
			int t=max(0,l+dp[l]-i);
			while(t+i<3*n&&p[t]==p[t+i])t++;
			dp[i]=t;
			l=i;
		}
	}
	FOR(i,n,2*n-1){
		if(dp[i]>=n){
			cout<<i-n<<' '<<(b[0]^a[i-n])<<'\n';
		}
	}
	RE 0;
}


