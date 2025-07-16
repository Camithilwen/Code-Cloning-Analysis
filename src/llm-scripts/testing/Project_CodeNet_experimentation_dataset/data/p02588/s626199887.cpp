#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    double a[n];
    pair<int,int>p[n];
    int fac[20][20]={};
    for(int i=0;i<n;i++){
        cin>>a[i];
        long long x=(a[i]+0.0000000001)*1000000000;
        int two=0,five=0;
        while(x%2==0)two++,x/=2;
        while(x%5==0)five++,x/=5;
        two=min(18,two),five=min(18,five);
        fac[two+1][five+1]++;
        p[i]={18-two,18-five};
    }
    for(int i=0;i<20;i++)for(int j=0;j<19;j++)fac[i][j+1]+=fac[i][j];
    for(int i=0;i<20;i++)for(int j=0;j<19;j++)fac[j+1][i]+=fac[j][i];
    long long ans=0;
    for(int i=0;i<n;i++){
        int x=fac[19][19]-fac[p[i].first][19]-fac[19][p[i].second]+fac[p[i].first][p[i].second];
        if(p[i].first<10 && p[i].second<10)x--;
        ans+=x;
}
    cout<<ans/2<<endl;
    return 0;
}