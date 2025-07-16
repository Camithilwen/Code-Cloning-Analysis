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

vector<ll> sum;
void pre_process(vector<ll> &a,vector<ll> &s){//累積和のvector
    ll n=(ll)a.size();
    s.assign(n+1,0);
    for(ll i=0;i<n;i++){
        s[i+1]=s[i]+a[i];
    }
}
ll query(ll i,ll j,vector<ll> &s){//区間[i,j]の和
    return (s[j]-s[i]);
}

int main(){
    ll n,m;cin>>n>>m;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];

    pre_process(a,sum);

    vector<ll> cnt;
    rep(i,n+1){
        if(i==0) continue;
        cnt.push_back(sum[i]%m);
    }
    sort(cnt.begin(),cnt.end());
    cnt.push_back(-1ll);

    ll num=1;
    ll answer=0;
    rep(i,cnt.size()-1){
        if(cnt[i]==cnt[i+1]){
            num++;
        }else{
            if(cnt[i]==0){
                answer+=num*(num+1)/2;
            }else{
                answer+=(num-1)*num/2;
            }
            num=1;
        }
    }



    cout<<answer<<endl;
    return 0;
}