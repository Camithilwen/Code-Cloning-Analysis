#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int INF = 1000000000;

int main()
{
    int n, m;
    int d[512];
    vector<int> f[512];

    while (scanf("%d %d", &n, &m), n != 0){
        for (int i = 1; i <= n; i++) f[i].clear();
        for (int i = 0; i < m; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            f[a].push_back(b);
            f[b].push_back(a);
        }

        fill(d + 1, d + n + 1, INF);
        priority_queue<P, vector<P>, greater<P> > q;
        q.push(P(0, 1));
        d[1] = 0;
        while (!q.empty()){
            P p = q.top();
            q.pop();

            if (d[p.second] < p.first) continue;
            for (int i = 0; i < f[p.second].size(); i++){
                int v = f[p.second][i];
                if (d[v] > d[p.second] + 1){
                    d[v] = d[p.second] + 1;
                    q.push(P(d[v], v));
                }
            }
        }

        int cnt = 0;
        for (int i = 1; i <= n; i++){
            cnt += (d[i] == 1 || d[i] == 2);
        }
        printf("%d\n", cnt);
    }

    return 0;
}