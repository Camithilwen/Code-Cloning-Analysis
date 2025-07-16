#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<int,int>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int d[4] = {0,1,6,5};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    ll N;
    cin>>N;
    bool s = true;
    vector<vector<ll>> xu(200005),xd(200005),yr(200005),yl(200005);
    vector<vector<vector<ll>>> A(8,vector<vector<ll>>(400005));
    rep(i,N){
        ll X,Y;
        char c;
        cin>>X>>Y>>c;
        if(c=='U') {
            xu[X].push_back(Y);
            A[0][X+Y].push_back(Y-X);
            A[1][X-Y+200000].push_back(X+Y);
        }
        if(c=='D') {
            xd[X].push_back(Y);
            A[2][X+Y].push_back(Y-X);
            A[3][X-Y+200000].push_back(X+Y);
        }
        if(c=='R') {
            yr[Y].push_back(X);
            A[4][X+Y].push_back(Y-X);
            A[5][X-Y+200000].push_back(X+Y);
        }
        if(c=='L') {
            yl[Y].push_back(X);
            A[6][X+Y].push_back(Y-X);
            A[7][X-Y+200000].push_back(X+Y);
        }
    }
    rep(i,200005){
        sort(xu[i].begin(),xu[i].end());
        sort(xd[i].begin(),xd[i].end());
        sort(yr[i].begin(),yr[i].end());
        sort(yl[i].begin(),yl[i].end());
    }
    rep(i,400005){
        rep(j,8){
            sort(A[j][i].begin(),A[j][i].end());
        }
    }
    ll ans = INF;
    rep(x,200005){
        if((!xu[x].empty()&&!xd[x].empty())&&(*xu[x].begin())<(*xd[x].rbegin())){
            for(auto t:xu[x]){
                auto ite = upper_bound(xd[x].begin(),xd[x].end(),t);
                if(ite == xd[x].end()) continue;
                s = false;
                chmin(ans,(*ite-t)*5);
            }
        }
    }
    rep(y,200005){
        if((!yr[y].empty()&&!yl[y].empty())&&(*yr[y].begin())<(*yl[y].rbegin())){
            for(auto t:yr[y]){
                auto ite = upper_bound(yl[y].begin(),yl[y].end(),t);
                if(ite == yl[y].end()) continue;
                s = false;
                chmin(ans,(*ite-t)*5);
            }
        }
    }
    rep(i,400005){
        rep(k,4){
            int j = d[k];
            if(j==0){
                if((!A[0][i].empty()&&!A[4][i].empty())){
                    for(auto p:A[0][i]){
                        auto ite = upper_bound(A[4][i].begin(),A[4][i].end(),p);
                        if(ite == A[4][i].end()) continue;
                        s = false;
                        chmin(ans,(*ite-p)*5);
                    }
                }
            }
            else{
                if((!A[j][i].empty()&&!A[8-j][i].empty())){
                    for(auto p:A[j][i]){
                        auto ite = upper_bound(A[8-j][i].begin(),A[8-j][i].end(),p);
                        if(ite == A[8-j][i].end()) continue;
                        s = false;
                        chmin(ans,(*ite-p)*5);
                    }
                }
            }
        }
    }
    if(s) cout<<"SAFE"<<endl;
    else cout<<ans<<endl;
}