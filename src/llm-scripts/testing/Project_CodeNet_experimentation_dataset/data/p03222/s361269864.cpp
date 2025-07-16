#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <queue>
#include <iomanip>
#include <iterator>

#define MOD 1000000007
#define INF 1000000001

using namespace std;
typedef unsigned long long ull;
typedef long long ll;


template <class T>
ostream &operator<<(ostream &o, const vector<T>&obj) {
    o << "["; for (int i = 0; i < (int)obj.size(); ++i) o << (i > 0 ? ", " : "") << obj[i]; o << "]"; return o;
}
template <class T, class U>
ostream &operator<<(ostream &o, const pair<T, U>&obj) {
    o << "(" << obj.first << ", " << obj.second << ")"; return o;
}
template <class T, class U>
ostream &operator<<(ostream &o, const map<T, U>&obj) {
    o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;
}
template <class T>
ostream &operator<<(ostream &o, const set<T>&obj) {
    o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;
}
template <class T>
ostream &operator<<(ostream &o, const queue<T>&obj) {
    queue<T> obj_cp = obj;
    bool first = true;
    o << "{";
    while (!obj_cp.empty()) { o << (!first ? ", " : "") << obj_cp.front(); obj_cp.pop(); first = false; }
    o << "}"; return o;
}

void print() {
    cout << "\n";
}
template<class Head, class... Body>
void print(Head head, Body... body) {
    cout << head << " ";
    print(body...);
}


int H, W, K;
vector<int> pattern_nums;

void init_pnums() {
    pattern_nums.resize(W);
    pattern_nums[0] = 1;
    pattern_nums[1] = 2;
    for (int i = 0; i <= W-2; ++i) {
        pattern_nums[i+2] = pattern_nums[i] + pattern_nums[i+1];
    }
}

int get_pnum(int h) {
    if (h < 0) return 1;
    return pattern_nums[h];
}

int main(int argc, char const *argv[]) {
    cin >> H >> W >> K;
    init_pnums();
    // print(pattern_nums);

    vector<vector<ull>> dp(H+1, vector<ull>(W, 0));
    dp[0][0] = 1;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            dp[i+1][j] = (dp[i][j] * get_pnum(j-1) * get_pnum(W-j-2)) % MOD;
            // print(i, j, "center", dp[i][j] * get_pnum(j-1) * get_pnum(W-j-2));
            if (j > 0) {
                dp[i+1][j] = (dp[i+1][j] + dp[i][j-1] * get_pnum(j-2) * get_pnum(W-j-2)) % MOD;
                // print(i, j, "left", dp[i][j-1] * get_pnum(j-2) * get_pnum(W-j-2));
            }
            if (j < W-1) {
                dp[i+1][j] = (dp[i+1][j] + dp[i][j+1] * get_pnum(j-1) * get_pnum(W-j-3)) % MOD;
                // print(i, j, "right", dp[i][j+1] * get_pnum(j-1) * get_pnum(W-j-3));
            }
        }
        // print(i+1, dp[i+1]);
    }

    cout << dp[H][K-1] << endl;

    return 0;
}
