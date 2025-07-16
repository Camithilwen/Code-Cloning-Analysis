#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    double n,m,d;
    cin>>n>>m>>d;
    double ans=(d*2+(n-(d*2))*2)/(n*n);
    ans*=(m-1);
    if(d==0) ans/=2;
    cout<<fixed<<setprecision(10)<<ans<<endl;

}