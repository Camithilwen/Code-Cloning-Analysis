#include <bits/stdc++.h>

struct Point
{
    long long x, y, distance{1000000000000};
    std::vector<std::pair<int, long long>> edge;
};

using pli = std::pair<long long, int>;

int main()
{
    int n;
    Point points[100000];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld%lld", &points[i].x, &points[i].y);
    {
        int sort_p[100000];
        for (int i = 0; i < n; i++)
            sort_p[i] = i;
        std::sort(sort_p, sort_p + n, [&](const int &a, const int &b) { return points[a].x < points[b].x; });
        for (int i = 0; i < n - 1; i++)
            points[sort_p[i]].edge.push_back({sort_p[i + 1], points[sort_p[i + 1]].x - points[sort_p[i]].x});
        for (int i = 1; i < n; i++)
            points[sort_p[i]].edge.push_back({sort_p[i - 1], points[sort_p[i]].x - points[sort_p[i - 1]].x});

        std::sort(sort_p, sort_p + n, [&](const int &a, const int &b) { return points[a].y < points[b].y; });
        for (int i = 0; i < n - 1; i++)
            points[sort_p[i]].edge.push_back({sort_p[i + 1], points[sort_p[i + 1]].y - points[sort_p[i]].y});
        for (int i = 1; i < n; i++)
            points[sort_p[i]].edge.push_back({sort_p[i - 1], points[sort_p[i]].y - points[sort_p[i - 1]].y});
    }

    bool connected[100000]{};
    long long sum{};
    int rest{n - 1};
    std::priority_queue<pli, std::vector<pli>, std::greater<pli>> pq;
    connected[0] = true;
    for (auto &e : points[0].edge)
    {
        points[e.first].distance = e.second;
        pq.push({e.second, e.first});
    }
    while (rest)
    {
        auto next = pq.top();
        pq.pop();
        if (connected[next.second]) continue;
        rest--;
        connected[next.second] = true;
        sum += next.first;
        for (auto &e : points[next.second].edge)
        {
            if (e.second >= points[e.first].distance) continue;
            points[e.first].distance = e.second;
            pq.push({e.second, e.first});
        }
    }

    printf("%lld\n", sum);

    return 0;
}