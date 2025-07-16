#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <algorithm>
#define ii pair<int, int>
#define iii pair<ii, int>
#define pq priority_queue

using namespace std;

int bfs(vector<vector<char>> graph, ii start, ii goal, int h, int w) {
    queue<iii> possible;
    set<ii> visited;
    possible.push(make_pair(start, 0));
    while (!possible.empty()) {
        ii xy = possible.front().first;
        int dist_from_start = possible.front().second;
        possible.pop();
        if (visited.find(xy) == visited.end()) {
            if (xy == goal) {
                return dist_from_start;
            }
            if (xy.first + 1 < h && graph[xy.first + 1][xy.second] == '.') {
                possible.push(make_pair(make_pair(xy.first + 1, xy.second), dist_from_start + 1));
            }
            if (xy.first - 1 >= 0 && graph[xy.first - 1][xy.second] == '.') {
                possible.push(make_pair(make_pair(xy.first - 1, xy.second), dist_from_start + 1));
            }
            if (xy.second - 1 >= 0 && graph[xy.first][xy.second - 1] == '.') {
                possible.push(make_pair(make_pair(xy.first, xy.second - 1), dist_from_start + 1));
            }
            if (xy.second + 1 < w && graph[xy.first][xy.second + 1] == '.') {
                possible.push(make_pair(make_pair(xy.first, xy.second + 1), dist_from_start + 1));
            }
            visited.insert(xy);
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;
    vector<vector<char>> graph(h, vector<char>(w));
    cin.get();
    int no_black = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin.get(graph[i][j]);
            if (graph[i][j] == '#') {
                no_black++;
            }
        }
        cin.get(); //get \n character
    }
    int answer = bfs(graph, make_pair(0, 0), make_pair(h - 1, w - 1), h, w);
    if (answer >= 0) {
        answer = h * w - answer - no_black - 1;
    }
    cout << answer;
}