#include<bits/stdc++.h>
using namespace std;
int main(){
    int match[10]={0,2,5,5,4,5,6,3,7,6};
    int n,m;
    cin>>n>>m;
    int a[m],x[m];
    for(int i=0;i<m;i++)cin>>a[i];
    sort(a,a+m,greater<int>());
    for(int i=0;i<m;i++)x[i]=match[a[i]];
    vector<int>dp(n+1,-1000000000);
    dp[0]=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++)if(i+x[j]<=n)dp[i+x[j]]=max(dp[i+x[j]],dp[i]+1);
    }
    while(n){
        for(int i=0;i<m;i++){
            if(n-x[i]>=0 && dp[n-x[i]]==dp[n]-1){
                cout<<a[i];
                n-=x[i];
                break;
            }
        }
    }
    cout<<endl;
    return 0;
}
