#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main() {
    int n;
    cin>>n;
    vector<ll> l(n);
    rep(i,0,n)cin>>l[i];

    sort(l.begin(),l.end());

    int ans=0;
    rep(i,0,n){
        rep(j,i+1,n){
            rep(k,j+1,n){
                if(l[i]+l[j]<=l[k])continue;
                if(l[i]<l[j]&&l[j]<l[k]){ans++;}
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}