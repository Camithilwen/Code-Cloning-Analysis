#include <bits/stdc++.h>
using namespace std;

int root(vector<int> &r, int a)
{
    if (r[a] == a) return a;
    else return r[a] = root(r, r[a]);
}

int main()
{
    long long N, K, L;
    scanf("%lld%lld%lld", &N, &K, &L);
    vector<int> road, rail;
    for (int i = 0; i <= N; i++) {
        road.push_back(i);
        rail.push_back(i);
    }
    for (int i = 1; i <= K; i++) {
        int p, q;
        scanf("%d%d", &p, &q);
        road[root(road, p)] = root(road, q);
    }
    for (int i = 1; i <= L; i++) {
        int r, s;
        scanf("%d%d", &r, &s);
        rail[root(rail, r)] = root(rail, s);
    }
    map<pair<int, int>, int> mp;
    for (int i = 1; i <= N; i++) {
        mp[make_pair(root(road, i), root(rail, i))]++;
    }
    for (int i = 1; i <= N; i++) {
        printf("%d ", mp[make_pair(root(road, i), root(rail, i))]);
    }
    printf("\n");
}
