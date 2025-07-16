#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    ll x;
    cin>>n>>x;
    vector<ll>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    int ans=0;
    int i=0;
    while(x>0 && i<n){
        x-=a[i];
        if(x>=0)ans++;
        i++;
    }
    if(x>0)ans--;
    cout<<ans<<endl;
    return 0;
}