#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    for(int i=0;i<tx-sx;i++) cout << 'R';
    for(int i=0;i<ty-sy;i++) cout << 'U';
    for(int i=0;i<tx-sx;i++) cout << 'L';
    for(int i=0;i<ty-sy;i++) cout << 'D';
    for(int i=0;i<1;i++) cout << 'D';
    for(int i=0;i<tx-sx+1;i++) cout << 'R';
    for(int i=0;i<ty-sy+1;i++) cout << 'U';
    for(int i=0;i<1;i++) cout << 'L';
    for(int i=0;i<1;i++) cout << 'U';
    for(int i=0;i<tx-sx+1;i++) cout << 'L';
    for(int i=0;i<ty-sy+1;i++) cout << 'D';
    for(int i=0;i<1;i++) cout << 'R';
    return 0;
}
