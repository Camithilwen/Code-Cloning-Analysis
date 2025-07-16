
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <functional>
#include <queue>
#include <deque>
#include <stack>
#include <limits>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <fstream>
#include <iterator>
#include <random>
#include <chrono>
 
 
#define forr(i,start,count) for (int i = (start); i < (start)+(count); ++i)
#define set_map_includes(set, elt) (set.find((elt)) != set.end())
#define readint(i) int i; cin >> i
#define readll(i) ll i; cin >> i
#define readdouble(i) double i; cin >> i
#define readstring(s) string s; cin >> s
 
typedef long long ll;
 
using namespace std;

ll modd = 1000*1000*1000+7;

 
int main()   {

    ios_base::sync_with_stdio(false);

    cout.precision(17);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> rand_gen(0, 1000);   // rand_gen(rng) gets the rand no
 
//    auto start = chrono::steady_clock::now();

//    readint(test_cases);
    int test_cases = 1;
    forr(t, 1, test_cases) {
        readint(h); readint(w); readint(a); readint(b);
        vector<string> grid(h, string(w, '0'));
        forr(i,0,b) {
            forr(j,0,a) {
                grid[i][j] = '1';
            }
        }
        for(int i = b; i < h; ++i) {
            for(int j = a; j < w; ++j) {
                grid[i][j] = '1';
            }
        }
        for (auto s : grid) {
            cout << s << endl;
        }
    }
 
//    auto end = chrono::steady_clock::now();
//    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;
 
    return 0;
}