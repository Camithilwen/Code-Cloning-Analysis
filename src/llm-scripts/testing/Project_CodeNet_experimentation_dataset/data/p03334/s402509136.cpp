#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int field[606][606][2];
int D[2];
int N;
vector<int> dx[2];
vector<int> dy[2];

void bfs(int x, int y, int index, int val) {
    if(x < 0 || x >= 2 * N || y < 0 || y >= 2 * N) return;
    if(field[x][y][index] != 0) return;
    field[x][y][index] = val;
    for(int i = 0; i < dx[index].size(); i++) {
        bfs(x+dx[index][i], y+dy[index][i], index, 3 - val);
    }
}

void print(vector<l_l> in) {
    for(int i = 0; i < N * N; i++) {
        cout << in[i].first << " " << in[i].second << endl;
    }
}

int main() {
    //cout.precision(10);
    cin >> N >> D[0] >> D[1];
    for(int index = 0; index < 2; index++) {
        for(int x = 0; x < 2 * N; x++) {
            for(int y = 0; y < 2 * N; y++) {
                if(x * x + y * y == D[index]) {
                    dx[index].push_back(x);
                    dx[index].push_back(x);
                    dx[index].push_back(-x);
                    dx[index].push_back(-x);
                    dy[index].push_back(y);
                    dy[index].push_back(-y);
                    dy[index].push_back(y);
                    dy[index].push_back(-y);
                }
            }
        }
    }
    for(int index = 0; index < 2; index++) {
        for(int x = 0; x < 2 * N; x++) {
            for(int y = 0; y < 2 * N; y++) bfs(x, y, index, 1);
        }
    }
    /*
    for(int index = 0; index < 2; index++) {
        for(int x = 0; x < 2 * N; x++) {
            for(int y = 0; y < 2 * N; y++) cerr << field[x][y][index] << " ";
            cerr << endl;
        }
        cerr << endl;
    }
    */
    vector<l_l> ans;
    for(int val = 1; val <= 2; val++) {
        ans.clear();
        for(int x = 0; x < 2 * N; x++) {
            for(int y = 0; y < 2 * N; y++) {
                if(field[x][y][0] == 1 && field[x][y][1] == val) ans.push_back({x, y});
            }
        }
        if(ans.size() >= N * N) {
            print(ans);
            return 0;
        }
    }
    return 0;
}
