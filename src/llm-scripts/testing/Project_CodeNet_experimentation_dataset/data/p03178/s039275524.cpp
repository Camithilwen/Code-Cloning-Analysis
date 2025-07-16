#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define deb(x) cout<< #x << " " << x << "\n";
#define MAX 9223372036854775807
#define MIN -9223372036854775807
#define PI 3.141592653589
#define setbits(n) __builtin_popcountll(n)
const ll mod=1e9+7;

const int N=1e5+1;
ll dp[N][101][2],d,n;
string s;

ll go(ll pos, ll k, ll mx){
    if(pos==n){
        if(k==0) return 1;
        else return 0;
    }
    if(dp[pos][k][mx]!=-1)
        return dp[pos][k][mx];
    ll ans=0,lim=s[pos]-'0';
    if(mx==0) lim=9;
    for(int i=0;i<lim;i++)
        ans=(ans+go(pos+1,(k+i)%d,0))%mod;
    if(mx==1) ans=(ans+go(pos+1,(k+lim)%d,1))%mod;
    else ans=(ans+go(pos+1,(k+lim)%d,0))%mod;
    return dp[pos][k][mx]=ans;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();
    
    cin>>s;
    cin>>d;
    n=s.size();
    memset(dp,-1,sizeof(dp));
    cout<<(go(0,0,1)-1+mod)%mod;

    cerr<<"\n\nTIME: "<<(double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}