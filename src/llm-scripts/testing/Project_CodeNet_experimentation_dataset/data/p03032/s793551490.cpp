#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod ll(1e9+7)
ll exp(ll a,ll b)
{
  if(b==0)
    return 1;
  if(b%2==0)
    return exp(a*a%mod,b/2);
  return a*exp(a*a%mod,(b-1)/2)%mod;
}
int main()
{
  #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
  #endif
   int n,k;
   cin>>n>>k;
   vector<int>arr(n+1);
   for(int i=1; i<=n; i++){
    cin>>arr[i];
   }
   int mx=0;
   for(int i=0; i<=k; i++){
    for(int j=0; j<=(k-i); j++){
      if(i+j>=n){
        vector<int>ans;
        int sum=0;
        for(int x=1; x<=n; x++){
          sum+=arr[x];
          ans.push_back(arr[x]);
        }
        sort(ans.begin(),ans.end());
        int num=min(n,k-n);
        for(int x=0; x<num; x++){
          if(ans[x]>=0)
            break;
          sum-=ans[x];
        }
        mx=max(sum,mx);
      }
      else{
        vector<int>ans;
        int sum=0;
        for(int x=1; x<=i; x++){
          ans.push_back(arr[x]);
          sum+=arr[x];
        }
        for(int x=n; x>=(n-j+1); x--){
          ans.push_back(arr[x]);
          sum+=arr[x];
        }
        int num=min(i+j,k-(i+j));
        sort(ans.begin(),ans.end());
        for(int x=0; x<num; x++){
          if(ans[x]>=0)
            break;
          sum-=ans[x];
        }
        mx=max(sum,mx);
      }
    }
   }
   cout<<mx;
   return 0;
}