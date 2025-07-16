#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[5]={0};
long double dp[305][305][305];

long double solve(int n1,int n2,int n3)
{
    if( (n1<0) || (n2<0) || (n3<0))
        return 0;
    if(n1==0 && n2==0 && n3==0)
        return 0;
    if(dp[n1][n2][n3]!=0)
        return dp[n1][n2][n3];
    long double &ans=dp[n1][n2][n3];
    int cnt=0;
    int x=n-n1-n2-n3;
    long double nn=n1+n2+n3;
    long double nn1=(long double)n1/nn;
    long double nn2=(long double)n2/nn;
    long double nn3=(long double)n3/nn;
    long double c=solve(n1-1,n2,n3);
    if(c>0)
    {
        long double xx= (long double)(((long double)n1+(long double)x*nn1)/((long double)n1));
        //cout<<xx<<" "<<c<<"\n";
        xx+=c;
        xx*=nn1;
        ans+=xx;
    }
     c=solve(n1+1,n2-1,n3);
    if(c>0)
    {
        long double xx= (long double)(((long double)n2+(long double)x*nn2)/((long double)n2));
        //cout<<xx<<" ";
        xx+=c;
        xx*=nn2;
        ans+=xx;
        //cnt++;
    }
    c=solve(n1,n2+1,n3-1);
    if(c>0)
    {
        long double xx= (long double)(((long double)n3+(long double)x*nn3)/((long double)n3));
        //cout<<xx<<" ";
        xx+=c;
        xx*=nn3;
        ans+=xx;
        //cnt++;
    }
    //ans=ans/cnt;
    //cout<<n1<<" "<<n2<<" "<<n3<<" "<<ans<<" "<<cnt<<"\n";
    return ans;

}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp,0,sizeof(dp));
    cin>>n;
    dp[1][0][0]=n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a[x]++;
    }
    //cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<"\n";
    std::cout << std::setprecision(15) << solve(a[1],a[2],a[3]) << '\n';
}
