#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> x(n);
    for(int i=0;i<n;i++) cin>>x[i];
    ll ans=1e10;
    for(int i=0;i+k<=n;i++){
        ll l=abs(x[i])+abs(x[i+k-1]-x[i]);
        ll r=abs(x[i+k-1])+abs(x[i+k-1]-x[i]);
        ans=min(ans,min(l,r));
    }
    cout<<ans<<endl;
}