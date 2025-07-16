#pragma GCC optimize("O3")
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;

using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;

#define all(a) (a).begin(), (a).end()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin>>n>>m;

    int head = 2, tail = n;
    vector<P> ans;
    if(n % 2 == 1){
        for(int i=0; i<m; i++){
            ans.emplace_back(head, tail);
            head++, tail--;
        }
    }
    else{
        set<int> length;
        for(int i=0; i<m; i++){
            int over = (n - tail) + head, under = tail - head;
            if(over == under || length.count(over) || length.count(under)) tail--;

            ans.emplace_back(head, tail);
            length.emplace(over);
            length.emplace(under);
            head++, tail--;
        }
    }

    for(auto i : ans) cout << i.first << " " << i.second << endl;

    return 0;
}