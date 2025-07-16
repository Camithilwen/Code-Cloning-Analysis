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

    int n, K;
    cin >> n >> K;
    vector<int> bad(10, false);
    for (int i = 0; i < K; ++i) {
        int x;
        cin >> x;
        bad[x] = true;
    }

    int mn = 10;
    for (int k = 0; k < 10; ++k) {
        if (!bad[k]) {
            mn = k;
            break;
        }
    }

    string s = to_string(n);
    n = s.length();
    for (int i = 0; i < n; ++i) {
        int d = s[i] - '0';
        if (bad[d]) {
            while (i >= 0) {
                bool done = false;
                d = s[i] - '0';
                for (int j = d + 1; j < 10; ++j) {
                    if (!bad[j]) {
                        s[i] = (char) ('0' + j);
                        for (int k = i + 1; k < n; ++k) {
                            s[k] = (char)('0' + mn);
                        }
                        done = true;
                        break;
                    }
                }
                if (done) {
                    break;
                }
                --i;
            }

            if (i < 0) {
                for (int j = 1; j < 10; ++j) {
                    if (!bad[j]) {
                        s = string(1, (char)('0' + j));
                        break;
                    }
                }
                s += string(n, (char)('0' + mn));
            }

            break;
        }
    }


    cout << s << '\n';


    return 0;
}