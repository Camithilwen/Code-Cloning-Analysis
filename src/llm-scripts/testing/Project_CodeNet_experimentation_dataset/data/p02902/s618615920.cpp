#include<cstdio>
#include<utility>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> P;

const int INF = 1050;
struct vertex {
    vector<int> to;
    int dist = INF;
};

int n, m;
int sd[1000], prv[1000];
vertex ver[1000];
priority_queue<P, vector<P>, greater<P>> q;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        ver[a - 1].to.emplace_back(b - 1);
    }
    for (int i = 0; i < n; i++) sd[i] = INF;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) ver[j].dist = INF;
        ver[i].dist = 0;
        q.emplace(0, i);
        while(!q.empty()) {
            P p = q.top(); q.pop();
            if (p.second != i && ver[p.second].dist != p.first) continue;
            if (p.second == i && p.first != 0 && sd[i] != p.first) continue;
            for (auto &j : ver[p.second].to) {
                if (j != i && p.first + 1 < ver[j].dist) {
                    ver[j].dist = p.first + 1;
                    q.emplace(ver[j].dist, j);
                }
                if (j == i && p.first + 1 < sd[i]) {
                    sd[i] = p.first + 1;
                    q.emplace(sd[i], i);
                }
            }
        }
    }
    
    int minsd = INF, ind;
    for (int i = 0; i < n; i++) {
        if (sd[i] < minsd) {
            minsd = sd[i];
            ind = i;
        }
    }
    if (minsd == INF) {
        printf("-1\n");
        return 0;
    }
    
    for (int i = 0; i < n; i++) ver[i].dist = INF; 
    ver[ind].dist = 0;
    sd[ind] = INF;
    q.emplace(0, ind);
    while(!q.empty()) {
        P p = q.top(); q.pop();
        if (p.second != ind && ver[p.second].dist != p.first) continue;
        if (p.second == ind && p.first != 0 && sd[ind] != p.first) continue;
        for (auto &i : ver[p.second].to) {
            if (i != ind && p.first + 1 < ver[i].dist) {
                ver[i].dist = p.first + 1;
                q.emplace(ver[i].dist, i);
                prv[i] = p.second;
            }
            if (i == ind && p.first + 1 < sd[ind]) {
                sd[ind] = p.first + 1;
                q.emplace(sd[ind], ind);
                prv[i] = p.second;
            }
        }
    }

    printf("%d\n", minsd);
    for (int i = 0, j = ind; i < minsd; i++) {
        printf("%d\n", j + 1);
        j = prv[j];
    }
    return 0;
}
