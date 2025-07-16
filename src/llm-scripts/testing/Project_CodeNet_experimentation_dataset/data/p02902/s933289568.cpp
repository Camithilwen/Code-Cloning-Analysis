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

using pv = pair<P,vector<int>>;
vector<int> graph[1005];

int main(){
    int n,m;
    cin >> n >> m;
    vector<P> edge(m);
    rep(i,m){
        cin >> edge[i].first >> edge[i].second;
        --edge[i].first;--edge[i].second;
        graph[edge[i].first].push_back(edge[i].second);
    }
    int id = -1;
    int mn = INF;
    vector<int> ans;
    rep(i,m){
        vector<bool> seen(n,false);
        queue<pv> q;
        q.push(pv(P(edge[i].second,0),{}));
        while(!q.empty()){
            int now = q.front().first.first;
            int c = q.front().first.second;
            vector<int> way = q.front().second;
            q.pop();
            if(now==edge[i].first){
                if(c < mn){
                    id = i;
                    mn = c;
                    way.push_back(now);
                    ans = way;
                    break;
                }else{
                    break;
                }
            }
            if(seen[now]) continue;
            seen[now] = true;
            way.push_back(now);
            for(int j:graph[now]){
                if(seen[j]) continue;
                q.push(pv(P(j,c+1),way));
            }
        }
    }
    if(mn==INF){
        cout << -1 << endl;
    }else{
        cout << (int)ans.size() << endl;
        rep(i,ans.size()) cout << ans[i]+1 << endl;
    }
    return 0;
}