#include<bits/stdc++.h>
using namespace std;

long long ara[57],dp[52][52][101];

long long solve(long long fr,long long sc,long long cap)
{

    if(sc<fr || cap==0)return 0;
    else if(dp[fr][sc][cap]!=-1)return dp[fr][sc][cap];
    else
    {

        long long p=-99999999999999;

        if(cap-1>=0)
        {
            p=max(p,ara[fr]+solve(fr+1,sc,cap-1));
            p=max(p,ara[sc]+solve(fr,sc-1,cap-1));
        }

        if(cap-2>=0)
        {

            p=max(p,solve(fr+1,sc,cap-2));
            p=max(p,solve(fr,sc-1,cap-2));
        }


        dp[fr][sc][cap]=p;  return dp[fr][sc][cap];



    }

}

int main()
{

        long long n,m,a,b,c,d,e,f,g,h,p,q,r,tr,sz,tz,i,j,k,mx=LLONG_MIN,mn=LLONG_MAX;
        long long x=0,y=0,cnt=0,res=0,ttl=0,ans=0,sum=0; long long flg=0,flag=1,na=0,as=1;
        vector<long long>u,v,w; vector< pair<long long,long long> >vct; vector<string>vst;
        set<long long>st,nt,tt; map<long long,long long>mp,nq,qr; string str,ttr,ntr;

        scanf("%lld %lld",&n,&k);

        for(i=1;i<=n;i++)
        {
            scanf("%lld",&a); ara[i]=a;

        }

        memset(dp,-1,sizeof dp);

        for(i=0;i<=k;i++)
        {
            ans=max(ans,solve(1,n,i));

        }

        printf("%lld\n",ans);





    return 0;
}



