#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define chmin(a,b) if((a)>(b)) (a)=(b);
#define chmax(a,b) if((a)<(b)) (a)=(b);
#define vi vector<int>
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define pb push_back
#define pf push_front
int gcd(int a,int b){/*a>=0,b>=0,￢(a=b=0)*/
  while(min(a,b)>0){if(a<b)swap(a,b);a%=b;}return max(a,b);
}
int dx[]={1,0,-1,0,1,-1,-1,1};
int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const long long INF = 1e18+10;

/*--------------------------------------------------------------------*/
signed main(){
	int n;
	cin>>n;
	int a[17];
	int x[17][17];
	int y[17][17];
	rep(i,n){
		cin>>a[i];
		rep(j,a[i]){
			cin>>x[i][j]>>y[i][j];
		}
	}
	int ans=0;
	rep(bit,1<<n){
		int shoujiki[17];
		rep(i,n){
			if(bit&(1<<i)) shoujiki[i]=1;
			else shoujiki[i]=0;
		}
		int to[17][17];
		int ok=1;
		rep(i,n){
			if(shoujiki[i]){
				rep(j,a[i]){
					if(y[i][j]){
						if(shoujiki[x[i][j]-1]==0) ok=0;
					}else{
						if(shoujiki[x[i][j]-1]==1) ok=0;
					}

				}
			}
		}
		if(ok){
			int cnt=0;
			rep(i,n){
				if(shoujiki[i]==1) cnt++;
			}
			chmax(ans,cnt);
		}
	}

	cout<<ans<<endl;
	return 0;
}

