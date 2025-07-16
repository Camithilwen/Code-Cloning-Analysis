
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;


#define LETS_GET_SCHWIFTY ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
#define ff              first
#define ss              second
//#define int             long long
#define ll              long long
#define pb              push_back
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define vpii            vector<pair<int,int> >
#define all(x)          x.begin(),x.end()
#define matrixprint(arr,a,b,c,d) for(int i=a;i<=c;i++){for(int j=b;j<=d;j++){cout<<arr[i][j]<<" ";}cout<<"\n";}
#define show(arr,x,y)   for(int i=x;i<=y;i++){cout<<arr[i]<<" ";}cout<<"\n"
#define sz(x)           (int)x.size()
#define db(x)           cout<<x<<"\n";

const int N = 2e5 + 5;

#define TRACE
#ifdef TRACE
#define deb(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
#else
#define deb(...)
#endif

	
//////////////////////////////code//////////////////////////////

string s;
int n;

int dp[10001][100][2][2]; // digitnum, digitval , modval , sameask , greatrthanzero


int sol(int i,int k,int l,int m)
{  
   // deb(i,j,k,l,m);
    
    if(i==sz(s))
    {
        if(m && k==0)
        { 
        return 1;
        }
        else
        return 0;
    }
    
    if(dp[i][k][l][m]!=-1)
    return dp[i][k][l][m];
    
    int ans = 0;
    
    if(l)
    {
        for(int digit=0;digit<10;digit++)
        {
            int now = s[i] - '0';
            
            if(now > digit)
            { 
            if(digit > 0)
            ans  = (ans +  sol(i+1,(k+digit)%n,0,1))%mod;
            else
            ans = (ans + sol(i+1,(k+digit)%n,0,m))%mod;
            }
            else if(now == digit)
            {
                if(now == 0)
                ans = (ans + sol(i+1,(k+digit)%n,1,m))%mod;
                else
                ans  = (ans + sol(i+1,(k+digit)%n,1,1))%mod;
            }
            
          //  deb(i,j,k,l,m,ans,digit);
        }
    }
    else
    {
        for(int digit=0;digit<10;digit++)
        {   
            if(digit==0)
            ans  = (ans + sol(i+1,(k+digit)%n,0,m))%mod;
            else
            ans = (ans + sol(i+1,(k+digit)%n,0,1))%mod;
            
           //  deb(i,j,k,l,m,ans,digit);
        }
    }
    
    
    
    return dp[i][k][l][m]=ans;
}


void solve()
{
  //  cout << "-------------------" << "\n";
    
    cin>>s>>n;
    
    memset(dp,-1,sizeof(dp));
    
    cout<<sol(0,0,1,0);


   // cout << "-------------------" << "\n";

}

int32_t main()
{

    LETS_GET_SCHWIFTY;

    int t = 1;
    //cin >> t;

    while (t--)
        solve();

}

// check out for following mistakes-
// if using pb operation on vector and then trying to access index..check if sizeof that vec could remain 0 only
// is using prime sieve make sure it fits
// when using factorial template or combinatorics make sure that you edit fillfac fun values and array values
