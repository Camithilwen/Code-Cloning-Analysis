/* Author: Dhruv Rastogi */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define all(sdk) sdk.begin(),sdk.end()
#define mll map<int, int>
#define pb push_back
#define rep(i,a,b) for(int i=a;i<b;++i)
#define repd(i,a,b) for(int i=a;i>=b;--i)
#define mp make_pair
#define hell 1000000007
#define endl '\n'
#define vvll vector<vector<int> >
#define vll vector<int>
#define mint map<int,int> 
#define sz(x) (int)x.size()
#define sll set<int>
#define pll pair<int,int>
#define F first
#define S second
const long double PI = acos(-1.0);

int dp[45][2][1<<18];

void solve(){  
	dp[0][0][1]=1;
	int n,x,y,z;
	cin>>n>>x>>y>>z;
	int reqd_mask = 1|(1<<z)|(1<<(y+z))|(1<<(x+y+z));
	rep(i,0,n){
		rep(j,0,2){
			rep(k,0,1<<18){
				rep(d,1,11){
					int new_mask = ((k<<d)|1)&((1<<18)-1);
					int new_j = j;
					if((new_mask&reqd_mask)==reqd_mask) new_j=1;
					dp[i+1][new_j][new_mask]+=dp[i][j][k];
					dp[i+1][new_j][new_mask]%=hell;
				}
			}
		}
	}  
	int ans=0;
	rep(i,0,1<<18){
		ans+=dp[n][1][i];
		ans%=hell;
	}
	cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}