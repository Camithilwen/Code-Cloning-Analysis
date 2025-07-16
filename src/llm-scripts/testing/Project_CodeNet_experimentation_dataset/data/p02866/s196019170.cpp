#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;



int main() {
    int N;
    cin>>N;
    int zero;
    cin>>zero;
    if(zero!=0){cout<<0<<endl;return 0;}
    vector<int> D(N-1);
    rep(i,N-1){cin>>D.at(i);}
    sort(D.begin(),D.end());
    int num=1,before=1,now=0;
    ll ans=1;
    rep(i,N-1){
        if(D.at(i)==num){
            now++;
            ans*=before;
            ans%=MOD2;
        }
        else{
            num++;
            before=now;
            ans*=before;
            ans%=MOD2;
            now=0;
            if(D.at(i)==num){
                now++;
            }
            else{cout<<0<<endl;return 0;}
        }
        //cout<<ans<<" "<<endl;
    }
    cout<<ans<<endl;
    return 0;
}