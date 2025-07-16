#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <numeric>
#include <cmath>
#include <iomanip> //cout << fixed << setprecision(15) << << endl;
#include <cassert>
//#include "atcoder/all"

using namespace std;
//using namespace atcoder;

typedef long long ll;

#define pb push_back
#define rep(i, n) for(int i=0;i<(n);i++)
#define REP(i, n) for(int i=1;i<=(n);i++)
#define P pair<int,int>
template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }

int mx8[] = {0, 0, 1, -1, -1, 1, -1, 1};
int my8[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int mx4[] = {1, -1, 0, 0};
int my4[] = {0, 0, -1, 1};

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int m=0;

    int n = s.size();
    int a = 0;
    rep(i, n) {
        a += int(s[i])-48;
        m += pow(10,n-i-1) * (int(s[i])-48);
    }

    if(m % a == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}