#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

ll sp[100010],sm[100010];

int main(){
    int n,k;
    cin>>n>>k;

    int z=0;
    vector<ll> x(n);

    vector<ll> p,m;

    rep(i,n){
        cin>>x[i];
        if(x[i]==0) z++;
        else if(x[i]>0){
            p.push_back(x[i]);
        }
        else{
            m.push_back(-x[i]);
        }
    }

    reverse(all(m));
    ll ans=1LL<<60;
    if(z==1){
        k--;
        if(k==0){
            cout<<0<<endl;
            return 0;
        }
    }
    if(p.size()>=k){
        ans=min(ans,p[k-1]);
    } 
    if(m.size()>=k){
        ans=min(ans,m[k-1]);
    }

    for(int i=1;i<k;i++){
        if(m.size()<i) break;
        if(p.size()<k-i) continue;
        ans=min(ans,2*m[i-1]+p[k-i-1]);
    }

    for(int i=1;i<k;i++){
        if(p.size()<i) break;
        if(m.size()<k-i) continue;
        ans=min(ans,2*p[i-1]+m[k-i-1]);
    }

    cout<<ans<<endl;
}
