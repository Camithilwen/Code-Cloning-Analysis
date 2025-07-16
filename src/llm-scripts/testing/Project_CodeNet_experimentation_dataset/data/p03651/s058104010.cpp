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
#define ArraySizeOf(array)     (sizeof(array) / sizeof(array[0]))
#define res(i,n) for(int i=n;;i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define REV(i,n) for(int i=n-1;i>0;i--)
#define req(i,n,m) for(int i=n;i<m;i++)
#define REQ(i,n,m,l) for(int i=n;i<m;i+=l) 
#define _GLIBCXX_DEBUG
int INF = 1e9 + 7;
unsigned NthDayOfWeekToDay(unsigned n, unsigned dow, unsigned dow1)
{
    unsigned day;
    if (dow < dow1) dow += 7;
    day = dow - dow1;
    day += 7 * n - 6;
    return day;
}
signed gcd(int x, int y) {
    if (y == 0)return x;
    return gcd(y, x % y);
}
signed lcm(int x, int y) {
    return x / gcd(x, y) * y;
}
unsigned DayToWeekNumber(unsigned day)
{
    return (day - 1) / 7 + 1;
}
unsigned AnotherDayOfWeek(unsigned day, unsigned day0, unsigned dow0)
{
    return (dow0 + 35 + day - day0) % 7;
}
using namespace std;
int main() {
    int N, K; cin >> N >> K;
    vector<int>A(N);
    rep(i, N) {
        cin >> A[i];
        if (A[i] == K) {
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    if (N == 1) {
        if (A[0] != K)cout << "IMPOSSIBLE" << endl;
        else cout << "POSSIBLE" << endl;
        return 0;
    }
    sort(A.begin(), A.end());
    int B=gcd(A[0],A[1]);
    REP(i, N - 1)B = gcd(B, A[i + 1]);
    rep(i,N){
        if (A[i] % B == K % B && K <= A[i]) {
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}