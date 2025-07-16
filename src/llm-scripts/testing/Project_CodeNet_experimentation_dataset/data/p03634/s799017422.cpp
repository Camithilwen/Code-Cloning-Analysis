#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    vector<vector<int>> edge(n, vector<int>());
    vector<vector<int>> weight(n, vector<int>());
    for(int i=0; i<n-1; i++){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--; c[i];
        edge[a[i]].push_back(b[i]);
        edge[b[i]].push_back(a[i]);
        weight[a[i]].push_back(c[i]);
        weight[b[i]].push_back(c[i]);
    }

    int q, k;
    cin >> q >> k;
    k--;

    vector<int> dis(n, -1);
    #if 0
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, k));
    while(!pq.empty()){
        int d = pq.top().first;
        int p = pq.top().second;
        pq.pop();
        if(dis[p] != -1) continue;
        dis[p] = d;
        for(int i=0; i<edge[p].size(); i++){
            int next = edge[p][i];
            if(dis[next] == -1){
                pq.push(make_pair(d + weight[p][i], next));
            }
        }
    }
    #else
    stack<int> s;
    s.push(k);
    dis[k] = 0;
    while(!s.empty()){
        int p = s.top();
        s.pop();
        for(int i=0; i<edge[p].size(); i++){
            int next = edge[p][i];
            if(dis[next] == -1){
                s.push(next);
                dis[next] = dis[p] + weight[p][i];
            }
        }
    }
    #endif


    for(int i=0; i<q; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        cout << dis[x] + dis[y] << endl;
    }
    return 0;
}