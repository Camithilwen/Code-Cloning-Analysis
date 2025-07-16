#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int> > >edge(n + 3);
    vector<vector<int> >rails(n + 3);
    for(int i = 1; i <= m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        edge[u].push_back({c, v});
        edge[v].push_back({c, u});
        rails[u].push_back(c);
        rails[v].push_back(c);
    }
    for(int i = 1; i <= n; i++){
        sort(edge[i].begin(), edge[i].end());
    }
    deque<pair<int, pair<int, int> > >dq;
    vector<map<int, int> >mp(n + 3);
    mp[1][0] = 0;
    dq.push_back({0, {1, 0}});
    while(!dq.empty()){
        int d = dq.front().first;
        int now = dq.front().second.first;
        int rail = dq.front().second.second;
        dq.pop_front();
        if(rail == 0){
            for(int i = 0; i < rails[now].size(); i++){
                int nrail = rails[now][i];
                if(mp[now].find(nrail) != mp[now].end() && mp[now][nrail] <= d + 1){
                    continue;
                }
                mp[now][nrail] = d + 1;
                dq.push_back({d + 1, {now, nrail}});
            }
        }
        else{
            pair<int, int>p = make_pair(rail, 0);
            int x = lower_bound(edge[now].begin(), edge[now].end(), p) - edge[now].begin();
            while(x != edge[now].size() && edge[now][x].first == rail){
                int nxt = edge[now][x].second;
                if(mp[nxt].find(rail) != mp[nxt].end() && mp[nxt][rail] <= d){
                    x++;
                    continue;
                }
                mp[nxt][rail] = d;
                dq.push_front({d, {nxt, rail}});
                x++;
            }
            if(mp[now].find(0) != mp[now].end() && mp[now][0] <= d){
                continue;
            }
            mp[now][0] = d;
            dq.push_front({d, {now, 0}});
        }
    }
    if(mp[n].empty()){
        cout << "-1";
        return 0;
    }
    int ans = 1e8;
    for(int i = 0; i < rails[n].size(); i++){
        int x = rails[n][i];
        ans = min(ans, mp[n][x]);
    }
    cout << ans;
    return 0;
}