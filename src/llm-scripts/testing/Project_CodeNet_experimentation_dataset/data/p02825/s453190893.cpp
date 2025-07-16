#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <random>

using namespace std;

#define int long long

vector<vector<int>> solivoli = 
{
    {1, 2, -1, -1, 3, 3},
    {1, 2, -1, -1, 4, 4},
    {5, 5, 7, 8, -1, -1},
    {6, 6, 7, 8, -1, -1},
    {-1, -1, 9, 9, 11, 12},
    {-1, -1, 10, 10, 11, 12}
};

vector<vector<int>> soli = {
    {1, 1, 3, 4},
    {2, 2, 3, 4},
    {5, 6, 7, 7},
    {5, 6, 8, 8}
};

vector<vector<int>> voli = {
    {1, 1, -1},
    {-1, -1, 2},
    {-1, -1, 2}
};

vector<vector<int>> volians5 {
    {1, 2, 3, -1, -1},
    {1, 2, 3, -1, -1},
    {4, 5, 5, 6, 6},
    {4, -1, 8, 9, 9}, 
    {7, 7, 8, 10, 10}
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> ans(n, vector<int> (n, -1));
    if (n == 7) {
        cout << "aabbcc." << endl;
        cout << "dd.ee.f" << endl;
        cout << "..a..cf" << endl;
        cout << "..a..cb" << endl;
        cout << "ll.jj.b" << endl;
        cout << "..a..ch" << endl;
        cout << "..a..ch" << endl;
        return 0;
    }
    if (n % 3 == 0) {
        for (int i = 0; i < n; i += 3) {
            for (int di = 0; di < 3; di++) {
                for (int dj = 0; dj < 3; dj++) {
                    ans[i + di][i + dj] = voli[di][dj];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (ans[i][j] == -1) {
                    cout << '.'; 
                } else {
                    cout << (char)(ans[i][j] + 'a');
                }
            }
            cout << endl;
        }
        return 0;
    }
    int wn = n;
    if (n % 2 == 1 && n >= 5) {
        for (int i = n - 5; i < n; i += 5) {
            for (int di = 0; di < 5; di++) {
                for (int dj = 0; dj < 5; dj++) {
                    ans[i + di][i + dj] = volians5[di][dj];
                }
            }
        }
        n -= 5;
    }   
    if (n % 2 == 0 && n != 2) {
        int c1 = 0;
        int c2 = 0;
        int ln = n;
        while (ln % 4) {
            ln -= 6;
            c2++;
        }
        c1 = ln / 4;
        for (int i = 0; i < 4 * c1; i += 4) {
            for (int di = 0; di < 4; di++) {
                for (int dj = 0; dj < 4; dj++) {
                    ans[i + di][i + dj] = soli[di][dj];
                }
            }
        }
        for (int i = 4 * c1; i < n; i += 6) {
            for (int di = 0; di < 6; di++) {
                for (int dj = 0; dj < 6; dj++) {
                    ans[i + di][i + dj] = solivoli[di][dj];
                }
            }
        }
       for (int i = 0; i < wn; i++) {
            for (int j = 0; j < wn; j++) {
                if (ans[i][j] == -1) {
                    cout << '.'; 
                } else {
                    cout << (char)(ans[i][j] + 'a');
                }
            }
            cout << endl;
        }
        return 0;
    }
    cout << -1 << endl;
}
