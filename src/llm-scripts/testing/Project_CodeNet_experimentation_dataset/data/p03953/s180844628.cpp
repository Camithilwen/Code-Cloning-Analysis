/*************************************
 * problem:      AT2164 Rabbit Exercise.
 * user ID:      63720.
 * user name:    Jomoo.
 * time:         2019-08-14.
 * language:     C++.
 * upload place: Luogu.
*************************************/ 

#include <bits/stdc++.h>
using namespace std;
#define puts_return(x) { puts(x); return 0; }
#define write_return(x) { write(x); return 0; }

typedef signed char          int8;
typedef unsigned char       uint8;
typedef short                int16;
typedef unsigned short      uint16;
typedef int                  int32;
typedef unsigned            uint32;
typedef long long            int64;
typedef unsigned long long  uint64;

template <typename Int>
inline Int read()       
{
    Int flag = 1;
    char c = getchar();
    while ((!isdigit(c)) && c != '-') c = getchar();
    if (c == '-') flag = -1, c = getchar();
    Int init = c & 15;
    while (isdigit(c = getchar())) init = (init << 3) + (init << 1) + (c & 15);
	return init * flag;
}

template <typename Int>
inline void write(Int x)
{
    if (x < 0) putchar('-'), x = ~x + 1;
    if (x > 9) write(x / 10);
    putchar((x % 10) | 48);
}  

template <typename Int>
inline void write(Int x, char nextch)
{
    write(x);
    putchar(nextch);
}

uint64 n, m, k;
vector<int32> x, a, to, ans;
vector<bool> vis;

int main()
{
    n = read<uint64>();
    x.resize(n);
    to.resize(n);
    ans.resize(n);
    vis.resize(n);
    for (size_t i = 0; i < n; i++) x[i] = read<int32>(), to[i] = i;
    for (size_t i = n - 1; i > 0; i--) x[i] -= x[i - 1];
    m = read<uint64>();
    a.resize(m);
    k = read<uint64>();
    for (auto num : a) num = read<int32>(), swap(to[num], to[num - 1]);
    for (size_t i = 0; i < n; i++) 
        if (!vis[i]) {
            vector<int32> s;
            for (int j = i; !vis[j]; j = to[j]) s.push_back(j), vis[j] = true;
            for (size_t j = 0; j < s.size(); j++) ans[s[j]] = x[s[(j + k) % s.size()]];
        }
    // ans[0] = x[0];
    // ans[n - 1] = x[n - 1];
    int64 tot = 0;
    for (auto answer : ans) write(tot += answer, 10);
    return 0;
}