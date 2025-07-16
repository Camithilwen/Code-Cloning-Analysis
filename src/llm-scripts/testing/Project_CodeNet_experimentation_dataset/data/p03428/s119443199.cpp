#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <random>
#include <cfloat>
#define norm(X) ((X) * (X))
using namespace std;
template<class T, class Compare = less<T> >
using MaxHeap = priority_queue<T, vector<T>, Compare>;
template<class T, class Compare = greater<T> >
using MinHeap = priority_queue<T, vector<T>, Compare>;
using llong = long long;

const llong s = 1000000;
const double R = 1e11;
llong n;
double px[105];
double py[105];
llong cnt[105];
double x, y;
double r;
double sx, sy;
llong indx;

int main() {
    
    cin >> n;
    for (llong i = 0; i < n; i++) {
        cin >> px[i];
        cin >> py[i];

        sx += px[i];
        sy += py[i];
    }
    sx /= n;
    sy /= n;

    for (llong i = 1; i <= s; i++) {
        x = R * cos(i * 2.0 * M_PI / s) + sx;
        y = R * sin(i * 2.0 * M_PI / s) + sy;
        indx = 0;

        r = 1e32;

        //cout << x << ' ' << y << endl;
        for (llong j = 0; j < n; j++) {
            double d = norm(x - px[j]) + norm(y - py[j]);

            if (d < r) {
                indx = j;
                r = d;
            }
        }

        cnt[indx]++;
    }

    for (llong i = 0; i < n; i++) {
        printf("%.*lf\n", DBL_DIG, (double)cnt[i] / (double)s);
    }

    return 0;
}
