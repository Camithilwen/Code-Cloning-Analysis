#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
 
 
int main(){
    ll l,r;cin>>l>>r;
    vector<int> vec;
    int ans=2020;
    for(int i=l;i<=min(r,l+2040)-1;i++){
        for(int j=i+1;j<=min(r,l+2040);j++){
            ans=min(ans,((i%2019)*(j%2019))%2019);
        }
    }
    cout<<ans<<endl;
}