#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;++i)
#define INF (1ll<<60)
#define mod 1000000007
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll mypow(ll a,ll b){
    ll ret=1;
    while(b--){
        ret*=a;
    }
    return ret;
}

int main(){
    ll n;cin>>n;
    vector<ll> ans;

    if(n==0){
        cout<<0<<endl;
        return 0;
    }

    ll num=0;
    while(n){
        ans.push_back(abs(n%2));
        n-=abs(n%2)*mypow(-1,num);
        n/=2;
        num++;

        //cout<<n<<endl;
        //if(num==10) break;
    }
    
    reverse(ans.begin(),ans.end());
    rep(i,ans.size()) cout<<ans[i];
    cout<<endl;
    return 0;
}