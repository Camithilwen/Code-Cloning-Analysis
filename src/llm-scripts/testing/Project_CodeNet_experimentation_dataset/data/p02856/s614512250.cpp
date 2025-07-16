#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<int,int>;
using graph = vector<vector<int>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    vector<vector<P>> v(10);
    rep(i,10){
        v[i].push_back(make_pair(0,0));
        v[i].push_back(make_pair(0,i));
    }
    rep(i,10){
        while(true){
            P p = *v[i].rbegin();
            int t = i*10 + p.second;
            int cnt = 0;
            while(t>=10){
                t = t/10+t%10;
                cnt++;
            }
            v[i].push_back(make_pair(p.first+cnt,t));
            if(t==i) break;
        }
    }
    v[0][2].first = 1;
    ll M;
    cin>>M;
    vector<ll> d(M),c(M);
    rep(i,M) cin>>d[i]>>c[i];
    ll ans = 0;
    vector<ll> rest(M);
    rep(i,M){
        ll t = d[i],s=c[i];
        ll l = v[t].size();
        ans+=v[t][l-1].first*((s-1)/(l-2));
        s = s - ((s-1)/(l-2))*(l-2);
        ans += v[t][s].first;
        rest[i]=v[t][s].second;
    } 
    ll cnt = 0;
    while(cnt!=M-1){
        while(rest[cnt]!=0){
            ll a = rest[cnt],b=rest[cnt+1];
            rest[cnt] = (a+b)/10;
            rest[cnt+1] = (a+b)%10;
            ans++;
        }
        cnt++;
    }
    cout<<ans<<endl;
}