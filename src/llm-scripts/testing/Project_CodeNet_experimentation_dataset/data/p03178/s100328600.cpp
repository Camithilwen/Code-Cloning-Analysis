#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define ar array<int,2>
#define inf 1000000000000000000 
int mod=1e9+7;
int min(int a,int b){return (a<b)?a:b;}
int max(int a,int b){return (a>b)?a:b;}
int fp(int a,int b){if(b==0) return 1;int x=fp(a,b/2);x=(x*x)%mod;if(b&1) x=(x*a)%mod;return x;}


const int N=1e4+5;
int d;
string s,tmp;
int sz;

int dp[N][2][101];
int pw[N];

void solve(int pos,int lm)
{
  
  if(dp[pos][lm][0]!=-1)
        return;
    
    if(pos==s.size())
    {
    //    cout<<tmp<<endl;
        for(int i=0;i<d;i++)
        dp[pos][lm][i]=0;
        dp[pos][lm][0]=1;
        return;
    }
  

    for(int i=0;i<d;i++)
        dp[pos][lm][i]=0;

    int l=0;
    int r=9;

    if(lm)
        r=s[pos]-'0';

    for(int i=l;i<=r;i++)
    {
       // tmp.push_back(i+'0');
        int nlm=0;
        if(lm&&i==r)
            nlm=1;
        solve(pos+1,nlm);
        for(int j=0;j<d;j++)
        {
            int x=(i+j)%d;
            dp[pos][lm][x]+=dp[pos+1][nlm][j];
            if(dp[pos][lm][x]>=mod)
                dp[pos][lm][x]-=mod;
        }
    }
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 memset(dp,-1,sizeof(dp));
 int n;
 cin>>s>>d;
 sz=s.size();
 pw[0]=1;
 for(int i=1;i<=sz;i++)
    pw[i]=(pw[i-1]*10)%d;
 solve(0,1);
 int ans=(dp[0][1][0]-1+mod)%mod;
 cout<<ans<<endl;
}