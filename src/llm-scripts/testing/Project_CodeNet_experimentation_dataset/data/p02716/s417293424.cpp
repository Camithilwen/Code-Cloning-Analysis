#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
#define INF -1000000000000000
#define pb push_back
#define sz(a) int((a).size())
#define all(c) c.begin(), c.end()
#define tr(c, i) for (typeof(c).begin() i = c.begin(); i != c.end(); i++)
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c), x) != c.end())

ll n,ara[200005];
vector< vector<ll> > dp(200005, vector<ll> (5,INF));



ll f(ll i, ll j){

  

    if(i>n) return 0;

    if(dp[i][j]!=INF) return dp[i][j];

    if(j==0){ 
        if(i>=n) return 0;  
        dp[i][j] = ara[i] + max(max(f(i+2,0),f(i+3,3)),f(i+4,1));
        return dp[i][j];
    }
    if(j==2) return dp[i][j] = ara[i] + max(f(i+2,2),f(i+3,1)); 
    if(j==3) return dp[i][j] = ara[i] + max(f(i+2,3),f(i+3,1));
    else     return  dp[i][j] = ara[i] + f(i+2,1);
    


}







int main(){
	
    ll i;
    cin>>n;
    for(i=1;i<=n;i++) cin>>ara[i];
    if(n%2==1){  
    cout<<max(max(f(1,0),f(2,2)),f(3,1))<<endl;
    }
    else{
        cout<<max(f(1,2),f(2,1))<<endl;
    }

	return 0;
}