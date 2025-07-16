#include <iostream>
#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>
#define int long long
using namespace std;
using Graph = vector<vector<int>>;
// Californium:Paken
vector<bool> seen;
void dfs(const Graph& G, int v) {
    seen[v] = true; // v を訪問済にする
 
    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
    }
}
signed main() {
    int L, R; cin >> L >> R;
    int M = 2019;
    if (L / 2019 == R / 2019 && L % 2019 != 0) {
        for (int X = L; X < min(L+2019,R); X++) {
            for (int Y = X+1; Y <= min(L+2019,R); Y++) {
                M = min(M,X*Y%2019);
            }
        }
        cout << M << endl;
    }
    else {
        cout << 0 << endl;
    }
}
