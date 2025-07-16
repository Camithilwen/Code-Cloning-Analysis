#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <list>
#include <limits>
#include <set>
#include <map>
#include <functional>

#include <inttypes.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;
typedef long long ll;

#ifndef PRId64
#define PRId64 "lld"
#endif
#ifndef SCNd64
#define SCNd64 "lld"
#endif
#define SC sc()
#define PT pr()
#define FORi(i,b,e) for (int i = (b), _ = (e); i < _; ++i)
#define FORe(i,b,e) for (int i = (b), _ = (e); i <= _; ++i)
#define FORre(i,b,e) for (int i = (b), _ = (e); i >= _; --i)

static int sc_ret = 0;
struct sc
{
    sc& operator()(char& v) { v = sc_ret = getchar(); return *this; }
    sc& operator()(int& v) { sc_ret = scanf("%d", &v); return *this; }
    sc& operator()(unsigned& v) { sc_ret = scanf("%u", &v); return *this; }
    sc& operator()(double& v) { sc_ret = scanf("%lf", &v); return *this; }
    sc& operator()(char* v) { sc_ret = scanf("%s", v); return *this; }
    sc& operator()(string& v) { sc_ret = (bool)(cin >> v); return *this; }
    sc& operator()(ll& v) { sc_ret = scanf("%" SCNd64, &v); return *this; }
    sc& ch(char& v) { sc_ret = scanf(" %c", &v); return *this; }
    sc& gets(char* v) { sc_ret = fgets(v, INT_MAX, stdin) != 0; v[strlen(v) - 1] = 0; return *this; }
    operator bool() const { return sc_ret > 0; }
    void read(int& v)
    {
        int x = 0, k = 1;
        char c = getchar();
        while (c < '0' || c > '9')
        {
            if (c == '-') k = -1;
            c = getchar();
        }
        while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c - 48), c = getchar();
        v = x * k;
    }
};
struct pr
{
    pr& ln() { putchar('\n'); return *this; }
    pr& operator()(char v) { putchar(v); return *this; }
    pr& operator()(int v) { printf("%d", v); return *this; }
    pr& operator()(double v) { printf("%.2f", v); return *this; }
    pr& operator()(const char* fmt, double v) { printf(fmt, v); return *this; }
    pr& operator()(const char* v) { printf("%s", v);return *this; }
    pr& operator()(string v) { printf("%s", v.c_str());return *this; }
    pr& operator()(ll v) { printf("%" PRId64, v);return *this; }

    void write(int v)
    {
        int cnt = 0; char c[15];
        if (v == 0)
        {
            putchar('0');
            return;
        }
        if (v < 0) putchar('-'), v = -v;
        while (v) c[++cnt] = (v % 10) + 48, v /= 10;
        while (cnt > 0) putchar(c[cnt--]);
    }
    template <typename T>
    void ln(T* arr, int size)
    {
        if (size > 0)
        {
            (*this)(arr[0]);
            for (int i = 1; i < size; ++i)
            {
                putchar(' ');
                (*this)(arr[i]);
            }
            putchar('\n');
        }
    }

    template <typename T>
    void muln(T* arr, int size)
    {
        for (int i = 0; i < size; ++i)
        {
            (*this)(arr[i]);
            putchar('\n');
        }
    }
};

const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
const int maxn = 200000 + 10;
const int maxm = 100000 + 10;

ll a[maxn];

int main()
{
    int n, t, k;
    SC(n);
    FORe(i, 1, n)
    {
        int v;
        SC.read(v);
        a[i] = v + a[i - 1];
    }
    int l = 1, r = 3; ll ret = a[n];
    FORi(i, 2, n - 1)
    {
        for (; l < i - 1; ++l)
        {
            if (min(a[l], a[i] - a[l]) >= min(a[l + 1], a[i] - a[l + 1]))
                break;
        }
        for (; r < n - 1; ++r)
        {
            if (min(a[r] - a[i], a[n] - a[r]) >= min(a[r + 1] - a[i], a[n] - a[r + 1]))
                break;
        }
        ret = min(ret, max(max(a[r] - a[i], a[n] - a[r]), max(a[l], a[i] - a[l]))
            - min(min(a[l], a[i] - a[l]), min(a[r] - a[i], a[n] - a[r])));
    }
    PT(ret);
    return 0;
}
