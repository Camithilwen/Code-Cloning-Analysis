#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
#define chmin(a, b) ((a)=min((a), (b)))
#define chmax(a, b) ((a)=max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};

int main(){
    int n, m; cin>>n>>m;
    vector<int> p(m), q(m), c(m);
    vector<P> v;
    for(int i=0; i<n; i++){
        v.push_back(P(i, -1));
    }

    for(int i=0; i<m; i++){
        cin>>p[i]>>q[i]>>c[i];
        p[i]--, q[i]--;
        v.push_back(P(p[i], c[i]));
        v.push_back(P(q[i], c[i]));
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int nn = v.size();

    map<P, int> p2v;
    for(int i=0; i<nn; i++){
        p2v[v[i]] = i;
    }

    vector<vector<P>> edge(nn);
    for(int i=0; i<nn; i++){
        if(v[i].second == -1) continue;

        int station = v[i].first;
        int out = p2v[P(station, -1)];
        edge[i].push_back(P(out, 0));
        edge[out].push_back(P(i, 1));
    }

    for(int i=0; i<m; i++){
        int s = p2v[P(p[i], c[i])];
        int t = p2v[P(q[i], c[i])];
        edge[s].push_back(P(t, 0));
        edge[t].push_back(P(s, 0));
    }

    int s = p2v[P(0, -1)];
    int g = p2v[P(n-1, -1)];
    vector<int> dist(nn, 1e9);
    dist[s] = 0;

    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, 0));
    while(que.size()){
        int cdist, cv;
        tie(cdist, cv) = que.top();
        que.pop();

        if(dist[cv] < cdist) continue;

        for(auto i:edge[cv]){
            int nv, ndist;
            tie(nv, ndist) = i;

            if(dist[cv] + ndist < dist[nv]){
                dist[nv] = dist[cv] + ndist;
                que.push(P(dist[nv], nv));
            }
        }
    }

    cout << (dist[g] == 1e9 ? -1 : dist[g]) << endl;
}