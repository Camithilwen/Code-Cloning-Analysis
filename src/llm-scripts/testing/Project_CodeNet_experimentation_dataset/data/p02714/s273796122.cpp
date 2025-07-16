#include<bits/stdc++.h>
 
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define rep(i,a,b)    for(int i=a;i<b;i++)
#define repn(i,a,b)   for(int i=a;i>=b;i--)
#define F first
#define S second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define pb push_back
#define mp  make_pair
#define all(v) (v).begin(), (v).end()
#define mod 998244353
#define inf 1e18 
 
using namespace std;
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    #endif
    
    IOS;
    int n,i,j,k;
    cin>>n;
    string s;
    cin>>s;
    vi r,g,b;
    for(i=0;i<n;i++)
    {
        if(s[i]=='R') r.pb(i);
        else if(s[i]=='G') g.pb(i);
        else b.pb(i);
    }
    int ans=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(s[i]==s[j]) continue;
            int x=0,y=0,z=0;
            if(s[i]=='R'||s[j]=='R') x++;
            if(s[i]=='G'||s[j]=='G') y++;
            if(s[i]=='B'||s[j]=='B') z++;
            // cout<<x<<" "<<y<<" "<<z<<endl;
            if(x==0)
            {
                auto it=upper_bound(r.begin(),r.end(),j);
                ans+=r.end()-it;
                int num=j+j-i;
                auto it1=lower_bound(r.begin(),r.end(),num);
                if(it1!=r.end()&&*it1==num) ans--;
            }
            else if(y==0)
            {
                auto it=upper_bound(g.begin(),g.end(),j);
                ans+=g.end()-it;
                int num=j+j-i;
                auto it1=lower_bound(g.begin(),g.end(),num);
                if(it1!=g.end()&&*it1==num) ans--;
            }
            else
            {
                auto it=upper_bound(b.begin(),b.end(),j);
                ans+=b.end()-it;
                int num=j+j-i;
                auto it1=lower_bound(b.begin(),b.end(),num);
                if(it1!=b.end()&&*it1==num) ans--;
            }
        }
    }
    cout<<ans;
}