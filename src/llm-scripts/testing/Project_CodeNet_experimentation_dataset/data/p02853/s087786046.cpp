//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    int x,y,ans=0; cin>>x>>y;
    if(x<=3) ans+=(4-x)*100000;
    if(y<=3) ans+=(4-y)*100000;
    if(x==1 && y==1) ans+=400000;
    cout<<ans<<endl;
}
