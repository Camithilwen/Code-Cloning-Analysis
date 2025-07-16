#include<iostream>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    while(cin>>n){
        ll ans,x;
        ans=n/11<<1;
        x=n%11;
        if(x>6)
            ans+=2;
        else if(x)
            ans++;
        cout<<ans<<endl;
    }
    return 0;
}
