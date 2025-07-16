#include<bits/stdc++.h>
using namespace std;
#define lli long long int
# define rep(i,n) for(int i=0;i<n;i++)
void solve(){
   int n;
   cin>>n;
   int a[n];
   rep(i,n)
   cin>>a[i];
   lli sum=0;
   for(int i=1;i<n;i++){
       if(a[i-1]>a[i]){
           sum+=(a[i-1]-a[i]);
           a[i]=a[i-1];
       }
   }
   cout<<sum<<endl;
}
int main()
{
    int t;
   // cin>>t;
    t=1;
    while(t--){
        solve();
    }
}