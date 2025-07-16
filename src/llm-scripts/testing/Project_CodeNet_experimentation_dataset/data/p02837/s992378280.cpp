#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

vector<vector<pair<int,int>>> G(20);

int main(){
    int n;
    cin>>n;

    rep(i,n){
        int a;
        cin>>a;
        rep(j,a){
            int x,y;
            cin>>x>>y;
            x--;
            G[i].push_back({x,y});
        }
    }

    int ans=0;
    rep(bit,1<<n){
        int tmp=0;
        bool ok=true;
        rep(i,n){
            if(bit & 1<<i){
                tmp++;
                rep(j,G[i].size()){
                    int x=G[i][j].first;
                    int y=G[i][j].second;
                    if(y==0 && bit & 1<<x) ok=false;
                    else if(y==1 && !(bit & 1<<x)) ok=false;
                }
            }
        }

        if(ok) ans=max(ans,tmp);
    }

    cout<<ans<<endl;
}
