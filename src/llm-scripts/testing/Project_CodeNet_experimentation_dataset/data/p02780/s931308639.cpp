#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


int main(){
    int n,k;
    cin>>n>>k;
    vector<int> p(n);

    rep(i,n){
        cin>>p[i];
        p[i]++;
    }
    vector<int> s(n+1,0);
    rep(i,n) s[i+1]=s[i]+p[i];

    int tmp=0;
    rep(i,n){
        tmp=max(tmp,s[min(n,i+k)]-s[i]);
    }

    double ans=tmp/2.0;
    cout<<fixed<<setprecision(10)<<ans<<endl;
}

