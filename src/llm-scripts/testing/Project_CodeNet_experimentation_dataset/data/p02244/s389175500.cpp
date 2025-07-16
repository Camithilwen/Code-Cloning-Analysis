#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
  
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
  
using namespace std;
  
typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      pii;
  
const int INF=1<<29;
const double EPS=1e-9;
  
const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

bool ok(int x, int y) {
    if (x < 0 || x >= 8 || y < 0 || y >= 8) return false;
    return true;
}

bool check(int nowmap[8][8]) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (nowmap[i][j] == 1) {
                count++;
            }
        }
    }
    if (count >= 9) {
        return false;
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (nowmap[i][j] == 1) {
                int dx[] = {1,1,-1,-1};
                int dy[] = {1,-1,-1,1};
                for (int k = 0; k < 4; k++) {
                    int px = j;
                    int py = i;
                    while(ok(px + dx[k], py + dy[k])) {
                        px += dx[k];
                        py += dy[k];
                        if (nowmap[py][px] == 1) {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

void print(int nowmap[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (nowmap[i][j] == 1) {
                cout << "Q";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[]) {
    int N;
    cin >> N;
    int map[8][8] = {{0}};
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
    }

    std::vector<int> perm;
    for (int i = 0; i < 8; i++) {
        perm.push_back(i);
    }

    do {
        int nowmap[8][8] = {{0}};
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                nowmap[i][j] = map[i][j];
            }
        }
        for (int i = 0; i < 8; i++) {
            int x = i;
            int y = perm[i];
            
            nowmap[y][x] = 1;

        }
        if (check(nowmap)) {
            print(nowmap);
            return 0;
        }
    } while(next_permutation(perm.begin(), perm.end()));
 
    return 0;
}