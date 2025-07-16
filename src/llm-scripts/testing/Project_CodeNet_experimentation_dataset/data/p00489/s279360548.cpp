#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int,int> > team(N);
    for (int i = 0; i < N; i++) {
        team[i].second = i + 1;
    }

    for (int i = 0; i < N * (N - 1) / 2; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (c < d) team[b-1].first+=3;
        if (c > d) team[a-1].first+=3;
        if (c == d) {
            team[a-1].first++;
            team[b-1].first++;
        }
    }

    sort(team.begin(), team.end());
    reverse(team.begin(), team.end());

    vector<int> rank(N);
    rank[team[0].second-1] = 1;
    for (int i = 1, count = 1, r = 1; i < N; i++) {
        if (team[i].first == team[i-1].first) {
            rank[team[i].second-1] = r;
            count++;
        }
        else {
            r += count;
            rank[team[i].second-1] = r;
            count = 1;
        }
    }

    for (auto i : rank) cout << i << endl;

    return 0;
}