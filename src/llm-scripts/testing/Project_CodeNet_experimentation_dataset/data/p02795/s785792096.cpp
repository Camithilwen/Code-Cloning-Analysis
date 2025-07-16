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
    int h,w,n,ans=inf; cin>>h>>w>>n;
    rep(i,h+1)rep(j,w+1){
        if(h*w-(h-i)*(w-j)>=n) ans=min(ans,i+j);
    }
    cout<<ans<<endl;
}
