#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
using namespace std;
int main(){
    int L,R;
    cin>>L>>R;
    ll x=2000000000;
    if(R-L+1>=2019){
        cout<<0<<endl;
    }
    else{
        ll w=0;
        for(ll i=L;i<R;i++){
            for(ll j=L+1;j<=R;j++){
                ll a=i%2019;
                ll b=j%2019;
                x=min(x,a*b%2019);
            }
        }
        cout<<x<<endl;
    }
    return 0;
}