#include "bits/stdc++.h"

using namespace std;

void Main() {
    long long N;
    cin >> N;
    map<long long, set<pair<long long, long long> > > tree;
    for (long long i = 0; i < N - 1; ++i) {
        long long a, b, c;
        cin >> a >> b >> c;
        if (tree.count(a) == 0) {
            tree.insert(make_pair(a, set<pair<long long, long long> >()));
        }
        tree[a].insert(make_pair(b, c));
        if (tree.count(b) == 0) {
            tree.insert(make_pair(b, set<pair<long long, long long> >()));
        }
        tree[b].insert(make_pair(a, c));
    }

    long long Q, K;
    cin >> Q >> K;
    vector<long long> distanceFromK(N + 1, -1LL);
    distanceFromK[K] = 0LL;
    queue<long long> q;
    q.push(K);
    while (!q.empty()) {
        long long f = q.front();
        q.pop();
        long long distanceFromTop = distanceFromK[f];
        const set<pair<long long, long long> >& nextNodes = tree[f];
        for (auto e : nextNodes) {
            if (distanceFromK[e.first] < 0) {
                q.push(e.first);
                distanceFromK[e.first] = e.second + distanceFromTop;
            }
        }
    }

    for (long long i = 0; i < Q; ++i) {
        long long x, y;
        cin >> x >> y;
        long long dx = distanceFromK[x];
        long long dy = distanceFromK[y];
        cout << (dx + dy) << endl;
    }

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
