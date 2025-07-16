#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;
ll gcd(ll x,ll y){
    if(x%y==0)return y;
    return gcd(y,x%y);
}
ll LCM(int a, int b){
    return a*b/gcd(a,b);
}

int main(void)
{
    int n;
    cin>>n;
    map<ll,int,greater<int>> a;
    rep(i,0,n){
        int in;
        cin>>in;
        a[in]++;
    }

    vector<ll> num;
    ll ans=0;
    for(auto i:a){
        if(i.second>=4){
            ans=max(ans,i.first*i.first);
        }
        if(i.second>=2){
            num.push_back(i.first); 
        }
        if(num.size()==2){
            ans=max(ans,num[0]*num[1]);
        }
    }
    cout<<ans<<endl;
    return 0;
}