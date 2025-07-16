#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {

    int h, w;

    cin >> h >> w;

    vector<vector<bool>> tile(h + 2, vector<bool>(w + 2, false));

    for(int i = 1; i <= h; ++i) {
        for(int j = 1; j <= w; ++j) {
            char ch;
            cin >> ch;

            if(ch == '.')
                tile[i][j] = true;

        }
    }

    bool isTrue = false;

    vector<vector<bool>> visited(h + 2, vector<bool>(w + 2, false));

    struct node {
        vector<pair<int, int>> walked;
        int i, j;
        void AddWalked(int i, int j) {
            walked.emplace_back(make_pair(i, j));
        }

        node(int i = 1, int j = 1) : walked(vector<pair<int, int>>()), i(i), j(j) {}

    };

    queue<node> q;
    q.push(node(1, 1));
    
    node ansNode;

    while(!q.empty()) {

        auto nowNode = q.front(); q.pop();
        int ni = nowNode.i, nj = nowNode.j;

        if(!tile[ni][nj] || visited[ni][nj])
            continue;

        visited[ni][nj] = true;

        if(ni == h && nj == w) {
            isTrue = true;
            ansNode = nowNode;
            break;
        }

        for(int i = 0; i < 4; ++i) {
            if(tile[dx[i] + ni][dy[i] + nj]) {
                node newNode(dx[i] + ni, dy[i] + nj);
                newNode.walked = nowNode.walked;
                newNode.AddWalked(dx[i] + ni, dy[i] + nj);
                q.push(newNode);
            }
        }

    }


    int answerCount = 0;

    if(isTrue) {
        tile[1][1] = false;
        for(int i = 0; i < ansNode.walked.size(); ++i) {
            int ai = ansNode.walked[i].first, aj = ansNode.walked[i].second;
            tile[ai][aj] = false;
        }

        for(int i = 1; i <= h; ++i)
            for(int j = 1; j <= w; ++j)
                if(tile[i][j])
                    answerCount++;

    }


    if(isTrue) 
        cout << answerCount << endl;
    else
        cout << -1 << endl;

}