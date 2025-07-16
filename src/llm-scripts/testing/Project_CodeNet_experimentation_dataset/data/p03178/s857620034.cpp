#include<bits/stdc++.h>
#define llu unsigned long long
#define ll long long
#define INF 0x3f3f3f3f
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define to_lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower);
#define to_upper(s) transform(s.begin(), s.end(), s.begin(), ::toupper);
using namespace std;

// scan vector
template <typename T> 
inline istream &operator>>(istream &in, vector<T> &a) {
    for(auto &x : a) in >> x;
    return in;
}
// print vector
template <typename T> 
inline ostream &operator<<(ostream &out, vector<T> &a) {
    for(auto &x : a) out << x <<" ";
    return out;
}
// scan pair
template <typename T, typename U> 
inline istream &operator>>(istream &in, pair<T,U> &a) {
    in >> a.first >> a.second; 
    return in;
}
const ll mod=1e9 + 7;
string k;
int D;
ll dp[10010][2][105];
ll solve(int pos, bool flag, int sum)
{
    if(pos==k.length())
        return sum==0;
    if(dp[pos][flag][sum]!=-1)
        return dp[pos][flag][sum];
    int limit = (flag)?(k[pos]-'0'):9;
    ll sum_so_far=0;
    for(int i=0; i<=limit; i++)
    {
        sum_so_far+=solve(pos+1,(flag && (i==limit)), (sum+i)%D);
    }
    return dp[pos][flag][sum]=sum_so_far%mod;

}
int main()    
{
    #ifdef SANS
        freopen("ongoingin.txt","r",stdin);
        freopen("ongoingout.txt","w",stdout);
    #endif
    fast
    int t=1;
    // cin>>t;
    while(t--)
    {
        cin>>k>>D;
        memset(dp,-1,sizeof(dp));
        ll ans=solve(0,1,0)-1;
        if(ans==-1)
            ans=mod-1;
        else if(ans>mod)
            ans-=mod;
        cout<<ans;
    }
    #ifdef SANS
        cout<<"\nTime Elapsed:"<<1.0*clock()/CLOCKS_PER_SEC <<"sec\n";
    #endif
}