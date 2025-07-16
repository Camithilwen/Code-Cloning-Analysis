#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define M 1000000007
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define f first
#define s second
#define b begin
#define e end
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for(i=a;i<b;i++)
#define RFOR(i,a,b) for(i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define itfr(it,x) for(it=x.begin();it!=x.end();it++)
#define flash ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main()
{
    flash;
    //sieve();
    int T=1,t,n,m,k,i;
    // cin>>T;
    while(T--)
    {
        cin>>n>>k;
        int a[10]={0};
        FOR(i,0,k){
          cin>>t;
          a[t]=1;
        }
        vector<int> vs;
        FOR(i,0,10)
            if(a[i]==0)
                vs.pb(i);
        // for(auto it:vs)cout<<it<<" ";cout<<endl;
        int dg=0;
        for(i=n;i>0;i/=10)dg++;
        ll ans=0;
        k = pow(10,dg-1);
        int fl=0;
        int num=n;
        // cout<<dg<<" "<<k<<endl;
        while(ans<num)
        {
            if(k==0){
                ans = ans*10 + vs[0];
                continue;
            }
            m = n/k;
            n = n%k;
            k/=10;
            if(a[m]==0&fl==0){
                ans = ans*10 + m;
                continue;
            }
            dg=0;
            if(fl==0)
            {
                for(auto it:vs)
                    if(it>=m)
                    {
                        dg=it;
                        break;
                    }
                if(dg==0)
                {
                    if(vs[0]!=0)
                        dg=vs[0];
                    else
                    {
                        if(ans==0)
                            dg=vs[1];
                        else
                            dg=vs[0];
                    }
                }
                ans = ans*10+dg;
                fl=1;
            }
            else
            {
                ans = ans*10 + vs[0];
            }
        }
        cout<<ans<<endl;
    }
}