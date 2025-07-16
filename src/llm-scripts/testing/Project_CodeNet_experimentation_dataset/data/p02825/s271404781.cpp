#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <chrono>
#include <tuple>
#include <random>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e6 * 2 + 10, INF = 1e9 * 1e9 + 10;

char grid[1002][1002];

int main()
{
    fastInp;
    ll n;
    cin >> n;
    if (n == 2) {
        cout << "-1";
        return 0;
    }

    if (n == 3) {
        cout << "aa.\n..b\n..b";
        return 0;
    }

    if (n == 6) {
        cout << "aa....\n";
        cout << "..b...\n";
        cout << "..b...\n";
        cout << "...aa.\n";
        cout << ".....b\n";
        cout << ".....b\n";
        return 0;
    }

    if (n == 7) {
        cout << ".aabbcc\n";
        cout << "d.eett.\n";
        cout << "dc....k\n";
        cout << "rc....k\n";
        cout << "rf....d\n";
        cout << "kf....d\n";
        cout << "k.aabb.\n";
        return 0;
    }

    if (n == 11) {
        cout << "laabbccddee\n";
        cout << "lmmrqqx...z\n";
        cout << "hf.rs.x...z\n";
        cout << "hfjjsmm...x\n";
        cout << "g...tkkdllx\n";
        cout << "g...t.fd.hy\n";
        cout << "f...eefrrhy\n";
        cout << "fbgg...vuut\n";
        cout << "ab.q...v.pt\n";
        cout << "awwq...sspu\n";
        cout << "ddccbbooiiu\n";
        return 0;
    }

    for (int i = 0; i <= n; i++) {
        if (4 * i <= n) {
            ll left = n - 4 * i;
            if (left % 5 == 0) {
                ll i2 = left / 5, prevX = 0;
                for (int j = 0; j < i; j++) {
                    grid[prevX][prevX] = 'a'; grid[prevX + 1][prevX] = 'a'; grid[prevX + 2][prevX] = 'b'; grid[prevX + 3][prevX] = 'c';
                    grid[prevX][prevX + 1] = 'd'; grid[prevX + 1][prevX + 1] = 'd'; grid[prevX + 2][prevX + 1] = 'b'; grid[prevX + 3][prevX + 1] = 'c';
                    grid[prevX][prevX + 2] = 'a'; grid[prevX + 1][prevX + 2] = 'b'; grid[prevX + 2][prevX + 2] = 'y'; grid[prevX + 3][prevX + 2] = 'y';
                    grid[prevX][prevX + 3] = 'a'; grid[prevX + 1][prevX + 3] = 'b'; grid[prevX + 2][prevX + 3] = 'x'; grid[prevX + 3][prevX + 3] = 'x';
                    prevX += 4;
                }

                for (int j = 0; j < i2; j++) {
                    grid[prevX][prevX] = 'a'; grid[prevX + 1][prevX] = 'a'; grid[prevX + 2][prevX] = 'b'; grid[prevX + 3][prevX] = 'b'; grid[prevX + 4][prevX] = 'c';
                    grid[prevX][prevX + 1] = 'd'; grid[prevX + 1][prevX + 1] = '.'; grid[prevX + 2][prevX + 1] = 'f'; grid[prevX + 3][prevX + 1] = 'f'; grid[prevX + 4][prevX + 1] = 'c';
                    grid[prevX][prevX + 2] = 'd'; grid[prevX + 1][prevX + 2] = 'r'; grid[prevX + 2][prevX + 2] = '.'; grid[prevX + 3][prevX + 2] = '.'; grid[prevX + 4][prevX + 2] = 'z';
                    grid[prevX][prevX + 3] = 't'; grid[prevX + 1][prevX + 3] = 'r'; grid[prevX + 2][prevX + 3] = '.'; grid[prevX + 3][prevX + 3] = '.'; grid[prevX + 4][prevX + 3] = 'z';
                    grid[prevX][prevX + 4] = 't'; grid[prevX + 1][prevX + 4] = 'k'; grid[prevX + 2][prevX + 4] = 'k'; grid[prevX + 3][prevX + 4] = 'y'; grid[prevX + 4][prevX + 4] = 'y';
                    prevX += 5;
                }

                for (int i= 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (grid[i][j] == 0) grid[i][j] = '.';
                        cout << grid[i][j];
                    }
                    cout << "\n";
                }
                return 0;
            }
        }
    }

    return 0;
}