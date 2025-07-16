#include<bits/stdc++.h>
using namespace std;

long long dp[2][3003];

int main()
{

        long long n,m,a,b,c,d,e,f,g,h,p,q,r,fr,sc,tr,sz,tz,i,j,k,mx=LLONG_MIN,mn=LLONG_MAX;
        long long x=0,y=0,cnt=0,res=0,ttl=0,ans=0,sum=0; long long flg=0,flag=1,na=0,as=1;
        vector<long long>u,v,w; vector< pair<long long,long long> >vct; vector<string>vst;
        set<long long>st,nt,tt; map<long long,long long>mp,nq,qr; string str,ttr,ntr;

        scanf("%lld %lld",&n,&k);

        for(i=1;i<=n;i++)
        {
            scanf("%lld %lld",&a,&b); vct.push_back(make_pair(a,b));
        }


        sort(vct.begin(),vct.end());

        long long idx,cap;

        for(idx=n-1;idx>=0;idx--)
        {
            for(cap=1;cap<=k;cap++)
            {
                fr=idx%2; sc=(idx+1)%2; a=vct[idx].first; b=vct[idx].second;

                p=0; q=0;

                if(idx==n-1 || cap-a<=0){  p=b; }
                else{  p=b+dp[sc][cap-a];   }

                if(idx!=n-1){  q=dp[sc][cap];  }

                dp[fr][cap]=max(p,q);


            }
        }

        printf("%lld\n",dp[0][k]);








    return 0;
}



