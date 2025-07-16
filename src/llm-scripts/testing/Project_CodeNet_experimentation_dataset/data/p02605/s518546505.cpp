#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,char> Q;

ll N;
vector<Q> v;
vector<vector<P>> V,H;
set<P> S;
vector<vector<ll>> LU,LD,RU,RD;

int main(){
    cin >> N;
    V.resize(200010);
    H.resize(200010);
    LU.resize(400010);
    LD.resize(400010);
    RU.resize(400010);
    RD.resize(400010);
    ll offset = 200000;
    for(int i=0;i<N;i++){
        ll x,y;
        char u;
        cin >> x >> y >> u;
        v.push_back({{x,y},u});
    }
    for(auto &e : v){
        ll x = e.first.first;
        ll y = e.first.second;
        if(S.find({x,y}) != S.end()){
            cout << 0 << endl;
            return 0;
        }
        S.insert({x,y});
    }
    for(auto &e : v){
        ll x = e.first.first;
        ll y = e.first.second;
        if(e.second == 'U'){
            V[x].push_back({y,0});
            RU[x+y].push_back(x);
            LU[x-y+offset].push_back(x);
        }
        if(e.second == 'D'){
            V[x].push_back({y,1});
            LD[x+y].push_back(x);
            RD[x-y+offset].push_back(x);
        }
        if(e.second == 'R'){
            H[y].push_back({x,0});
        }
        if(e.second == 'L'){
            H[y].push_back({x,1});
        }
    }
    ll ans = 1e18;
    for(int i=0;i<=200000;i++) sort(V[i].begin(),V[i].end());
    for(int i=0;i<=200000;i++) sort(H[i].begin(),H[i].end());
    for(int i=0;i<=200000;i++){
        ll tmp = -1;
        for(auto &e : V[i]){
            ll x = e.first;
            ll d = e.second;
            if(d == 0) tmp = x;
            else{
                if(tmp == -1) continue;
                ans = min(ans, (x-tmp) * 5);
            }
        }
    }
    for(int i=0;i<=200000;i++){
        ll tmp = -1;
        for(auto &e : H[i]){
            ll y = e.first;
            ll d = e.second;
            if(d == 0) tmp = y;
            else{
                if(tmp == -1) continue;
                ans = min(ans, (y-tmp) * 5);
            }
        }
    }
    for(int i=0;i<=400000;i++) sort(LU[i].begin(),LU[i].end());
    for(int i=0;i<=400000;i++) sort(LD[i].begin(),LD[i].end());
    for(int i=0;i<=400000;i++) sort(RU[i].begin(),RU[i].end());
    for(int i=0;i<=400000;i++) sort(RD[i].begin(),RD[i].end());
    for(auto &e : v){
        ll x = e.first.first;
        ll y = e.first.second;
        if(e.second == 'U'){
            continue;
        }
        if(e.second == 'D'){
            continue;
        }
        if(e.second == 'R'){
            auto itr_d = upper_bound(RD[x-y+offset].begin(),RD[x-y+offset].end(),x);
            if(itr_d != RD[x-y+offset].end()) ans = min(ans,((*itr_d) - x)*10);
            auto itr_u = upper_bound(RU[x+y].begin(),RU[x+y].end(),x);
            if(itr_u != RU[x+y].end()) ans = min(ans,((*itr_u) - x)*10);
        }
        if(e.second == 'L'){
            auto itr_d = upper_bound(LD[x+y].begin(),LD[x+y].end(),x);
            if(itr_d != LD[x+y].begin() && LD[x+y].size() != 0) ans = min(ans,(x - *(itr_d-1))*10);
            auto itr_u = upper_bound(LU[x-y+offset].begin(),LU[x-y+offset].end(),x);
            if(itr_u != LU[x-y+offset].begin() && LU[x-y+offset].size() != 0) ans = min(ans,(x - *(itr_u-1))*10);
        }
    }
    if(ans == 1e18) cout << "SAFE" << endl;
    else cout << ans << endl;
    return 0;
}