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

    int n;
    cin >> n;

    int mx = 55555;

    vector<vector<int>> G(10);

    vector<bool> isPrime(mx + 2, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= mx; ++i) {
        if (isPrime[i]) {
            G[i % 10].push_back(i);
            for (int j = i + i; j <= mx; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (auto x : G[1]) {
        cout << x;
        if (--n == 0) {
            cout << '\n';
            break;
        } else {
            cout << ' ';
        }
    }

    return 0;
}