#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin>>n;
    vector<ll> c(100005);
    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        c[d]++;
        if(i==0&&d!=0){
            cout<<0<<endl;
            return 0;
        }
    }
    ll ans=0;
    if(c[0]==1) ans=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<c[i];j++){
            ans*=c[i-1];
            ans%=998244353;
        }
    }
    cout<<ans<<endl;
}