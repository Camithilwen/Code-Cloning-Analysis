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
    string s; cin>>s;
    int n=s.size(),ans=inf;
    rep(i,n-2){
        int num=100*(s[i]-'0')+10*(s[i+1]-'0')+s[i+2]-'0';
        ans=min(ans,abs(753-num));
    }
    cout<<ans<<endl;
}
