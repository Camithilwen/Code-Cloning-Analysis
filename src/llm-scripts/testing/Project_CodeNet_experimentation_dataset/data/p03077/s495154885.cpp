#include <bits/stdc++.h> 
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

int main(){
    ll n;
    cin>>n;
    ll a[5]={};
    rep(i,5)cin>>a[i];
    ll b[5]={};
    rep(i,5){
        ll s=n%a[i];
        ll t=n/a[i];
        if(s!=0)b[i]=t+1+4;
        else b[i]=t+4;
    }
    ll ans=0;
    rep(i,5){
        ans=max(ans,b[i]);
    }
    cout<<ans<<endl;
}
