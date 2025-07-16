#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    int n,k;
    cin>>n>>k;
    vector<ld> p(n),a(n-k+1);
    ld ans=0;
    rep(i,n){
        cin>>p[i];
        p[i]=(1+p[i])/2;
        if(i-k<0) a[0]+=p[i];
        else{
            a[i-k+1]=a[i-k]-p[i-k]+p[i];
            ans=max(ans,a[i-k]);
        }
    }
    ans=max(ans,a[n-k]);
    cout<<fixed<<setprecision(10)<<ans;
}