#include <bits/stdc++.h>
using namespace std;
long long M=1000000007;
vector<int> num;
int isprime[105];
int n,m,d;
string a,b;
long long dp[10005][2][2][105];
long long solve(int idx,int flag,int flag2,int rem)
{
    //cout<<rem<<endl;
    if(idx==b.size())
        {
            if(rem==0)
                return 1;
            else
                return 0;
        }
    if(dp[idx][flag][flag2][rem]!=-1)
        return dp[idx][flag][flag2][rem];

    int lim=flag?9:(b[idx]-'0');
    int lim1=flag2?0:(a[idx]-'0');
    long long ans=0;
    for(int i=lim1;i<=lim;i++)
    {
        ans=(ans+solve(idx+1,flag||(i<lim),flag2||(i>lim1),(rem+i)%m)%M)%M;

    }
    return dp[idx][flag][flag2][rem]=ans%M;
}

 
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//ios_base& scientific (ios_base& str);
{
    memset(dp,-1,sizeof(dp));
    a="1";
    cin>>b;
    cin>>m;
    n=b.size();
    for(int i=0;i<n-1;i++)
        a="0"+a;
    cout<<solve(0,0,0,0)<<endl;
 
 
    
}
 
return 0;
} 