#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <iostream>
#include <string>
#include <bitset>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

#define ALL(g) (g).begin(), (g).end()
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define pb push_back
#define mp make_pair

typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef long long ll;

const int INF = INT_MAX;

int main(void) {
    int v, e, s, t, d;
    scanf("%d %d", &v, &e);

    int g[v][v];
    rep(i, v) rep(j, v) g[i][j] = INF;
    rep(i, v) g[i][i] = 0;

    rep(i, e) {
        scanf("%d %d %d", &s, &t, &d);
        g[s][t] = d;
    }
    
    rep(k, v) {
        rep(i, v) {
            if (g[i][k] == INF) continue;
            rep(j, v) {
                if (g[k][j] == INF) continue;
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    int flag = 1;
    rep(i, v) {
        if (g[i][i] < 0) {
            flag = 0;
            break;
        }
    }

    if (flag) {
        rep(i, v) {
            rep(j, v) {
                if (j) printf(" ");
                if (g[i][j] == INF) printf("INF");
                else printf("%d", g[i][j]);
            }
            printf("\n");
        }
    }
    else printf("NEGATIVE CYCLE\n");

    return 0;
}