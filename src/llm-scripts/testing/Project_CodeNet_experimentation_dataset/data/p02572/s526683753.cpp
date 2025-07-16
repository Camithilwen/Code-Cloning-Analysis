//hail to jwalaji
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define mod 1000000007
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
//lli t;
//cin>>t;
//while(t--){
    lli n;
    cin>>n;
    vector<lli> arr(n),store(n);
    for(lli i=0;i<n;i++){
        cin>>arr[i];
    }
    store[0]=arr[0]%mod;
    for(lli i=1;i<n;i++){
        store[i]=(arr[i]+store[i-1])%mod;
    }
    lli ans=0;
    for(lli i=1;i<n;i++){
        ans=(ans+store[i-1]*arr[i])%mod;
    }
    cout<<ans<<endl;
//}
return 0;
}
