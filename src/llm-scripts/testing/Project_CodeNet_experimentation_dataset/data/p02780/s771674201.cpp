#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;

int main()
{
    int k,n;
    double sum=0;
    cin>>n>>k;
    vector<double> p(n+1); //累積和
    for(int i=1;i<=n;i++){
        double a;
        cin>>a;
        a=(a+1)/2;
        sum+=a;
        p[i]=sum;
    }
    double ans=0;
    rep(i,n-k+1){
        ans=max(ans,p[i+k]-p[i]);
    }
    printf("%.10f",ans);
}