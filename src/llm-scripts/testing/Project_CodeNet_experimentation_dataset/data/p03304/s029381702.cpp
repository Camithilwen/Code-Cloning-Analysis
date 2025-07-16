#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    ll n,m,d;
    cin>>n>>m>>d;
    cout<<fixed<<setprecision(10)<<((d==0)?1.:2.)*(n-d)/n*(m-1)/n;
}
