#include<bits/stdc++.h>
using namespace std;

long long dp[200003][3];
long long ara[200003],n;

long long solve(long long idx,long long sta,long long lim)
{

    long long rr=lim-sta;

    if(idx+rr==n)return ara[idx];
    else if(dp[idx][sta]!=-1)return dp[idx][sta];
    else
    {

        long long p;

        p=ara[idx]+solve(idx+2,sta,lim);

        if(sta+1<=lim)
        {
            p=max(p,ara[idx]+solve(idx+3,sta+1,lim));
        }

        dp[idx][sta]=p; return dp[idx][sta];

    }


}

int main()
{

    long long a,i,j,st=1,ans=LLONG_MIN;

    scanf("%lld",&n);

    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a);  ara[i]=a; dp[i][0]=-1; dp[i][1]=-1; dp[i][2]=-1;
    }


    if(n%2==1)
    {
        ans=max(ans,solve(1,0,2));

        st=2;
    }

    if(st==2){memset(dp,-1,sizeof dp);}
    ans=max(ans,solve(st,0,1));

    memset(dp,-1,sizeof dp);
    ans=max(ans,solve(st+1,0,0));

    printf("%lld\n",ans);


    return 0;
}
