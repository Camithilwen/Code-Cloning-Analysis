#include <iostream>
#include <vector>
#define INF (int)1e9

int bellman_ford(int m, int p, int q, std::vector<std::vector<std::pair<int, int> > > v) {
    std::vector<int> rvec(m, INF);
    bool flag;
    rvec[p] = 0;
    int value;
    int target;

    do{
        flag = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < v[i].size(); j++) {
                value = v[i][j].first;
                target = v[i][j].second;
                if (rvec[target] > rvec[i] + value) {
                    rvec[target] = rvec[i] + value;
                    flag = true;
                }
            }
        }
    } while(flag);

    return rvec[q];
}

int main(void) {
    int n;
    int m;

    int a;
    int b;
    int cost;
    int time;

    int k;

    int p;
    int q;
    int r;

    int res;

    while (true) {
        std::cin >> n >> m;
        if (n == 0 && m == 0) {
            break; 
        }

        std::vector<std::vector<std::pair<int, int> > > vcost(m);
        std::vector<std::vector<std::pair<int, int> > > vtime(m);

        for (int i = 0; i < n; i++) {
            std::cin >> a >> b >> cost >> time;
            --a;
            --b;
            vcost[a].push_back(std::make_pair(cost, b));
            vcost[b].push_back(std::make_pair(cost, a));
            vtime[a].push_back(std::make_pair(time, b));
            vtime[b].push_back(std::make_pair(time, a));
        }

        std::cin >> k;

        for (int i = 0; i < k; i++) {
            std::cin >> p >> q >> r;
            --p;
            --q;

            // ????????????????????????
            if (r == 0) {
                res = bellman_ford(m, p, q, vcost);
            } else {
                res = bellman_ford(m, p, q, vtime);
            }
            std::cout << res << std::endl;
        }
    }
    return 0;
}