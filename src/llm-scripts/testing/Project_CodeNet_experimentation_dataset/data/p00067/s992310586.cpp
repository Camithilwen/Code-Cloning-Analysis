#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
using namespace std;
#define INF 100000000
typedef long long ll;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

string s[12];
bool used[12][12];

void dfs(int y, int x) {
    used[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < 12 && 0 <= ny && ny < 12 && s[ny][nx] == '1' && used[ny][nx] == false) {
            dfs(ny, nx);
        }
    }
}

int main(void) {
    while (1) {
        bool flag = false;
        for (int i = 0; i < 12; i++) {
            if (!(cin >> s[i])) flag = true;
        }
        if (flag) break;
        for (int i = 0; i < 12; i++)
            for (int j = 0; j < 12; j++) 
                used[i][j] = false;
        int ans = 0;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 12; j++) {
                if (s[i][j] == '1' && !used[i][j]) {
                    ans++;
                    dfs(i, j);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}