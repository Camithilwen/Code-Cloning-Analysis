#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(12);


    int sx, sy;
    int tx, ty;
    cin >> sx >> sy >> tx >> ty;


    string res;

    int x = tx - sx;
    int y = ty - sy;

    res += string(y, 'U');
    res += string(x, 'R');
    res += string(y, 'D');
    res += string(x, 'L');
    res += 'L';
    res += string(y + 1, 'U');
    res += string(x + 1, 'R');
    res += 'D';
    res += 'R';
    res += string(y + 1, 'D');
    res += string(x + 1, 'L');
    res += 'U';

    // cout << res.length() << endl;
    cout << res << '\n';

    return 0;
}