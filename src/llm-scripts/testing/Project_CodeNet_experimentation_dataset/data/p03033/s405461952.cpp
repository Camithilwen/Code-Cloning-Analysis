#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

struct event{
    int t,id,x;
};

int main(){
    int n,q;
    cin >> n >> q;
    vector<event> events;
    rep(i,n){
        int s,t,x;
        cin >> s >> t >> x;
        events.push_back({s-x,-1,x});
        events.push_back({t-x,0,x});
    }
    map<int,int> ans;
    rep(i,q){
        int d;
        cin >> d;
        ans[d] = -1;
        events.push_back({d,1,0});
    }

    sort(events.begin(),events.end(),[](const event &l,const event &r){
        if(l.t != r.t) return l.t < r.t;
        else return l.id < r.id;
    });

    set<int> st;
    map<int,int> cnt;

    rep(i,2*n+q){
        if(events[i].id == -1){
            st.insert(events[i].x);
            cnt[events[i].x] ++;
        }else if(events[i].id == 0){
            cnt[events[i].x] --;
            if(cnt[events[i].x]==0) st.erase(events[i].x);
        }else{
            if(!st.empty()) ans[events[i].t] = *st.begin();
        }
    }

    for(auto p:ans) cout << p.second << endl;
    return 0;
}