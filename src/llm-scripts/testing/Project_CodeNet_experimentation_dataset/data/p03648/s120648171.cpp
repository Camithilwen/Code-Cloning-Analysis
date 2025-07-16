#include <cstdio>
#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <unordered_map>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
LL x[50];

int main() {
    LL K;
    scanf("%lld", &K);
    LL rd = K / 50;
    for (int i = 0; i < 50; i++)
        x[i] = 50 - 1 + rd;
    for (int i = 0; i < (K % 50); i++) {
        int idx = 0;
        for (int j = 0; j < 50; j++)
            if (x[j] <= x[idx]) idx = j;
        for (int j = 0; j < 50; j++) {
            if (j == idx) x[j] += 50;
            else x[j]--;
        }
    }
    printf("%d\n", 50);
    for (int i = 0; i < 50; i++)
        printf("%lld ", x[i]);
    puts("");
    return 0;
}
