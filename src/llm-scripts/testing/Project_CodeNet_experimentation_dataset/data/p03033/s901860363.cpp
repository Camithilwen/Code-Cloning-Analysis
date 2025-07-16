#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
    int N, Q;
    cin>>N>>Q;
    vector<pair<ll, ll> > sarr(N), tarr(N);
    multiset<ll> xset;
    ll S, T, X;
    for(int i=0;i<N;++i){
        cin>>S>>T>>X;
        sarr[i] = mp(S-X, X);
        tarr[i] = mp(T-X, X);
    }
    sort(sarr.begin(), sarr.end());
    sort(tarr.begin(), tarr.end());
    ll D[Q];
    for(int i=0;i<Q;++i){
        cin>>D[i];
    }
    ll ans[Q];
    int sindex = 0, tindex = 0;
    for(int i=0;i<Q;++i){
        while(sindex<N && sarr[sindex].fi<=D[i]){
            xset.insert(sarr[sindex].se);
            sindex++;
        }
        while(tindex<N && tarr[tindex].fi<=D[i]){
            xset.erase(xset.find(tarr[tindex].se));
            tindex++;
        }
        if(sindex==tindex) ans[i] = -1;
        else ans[i] = *xset.begin();
    }
    for(int i=0;i<Q;++i){
        cout<<ans[i]<<endl;
    }
}

