#include <cstdio>
#include <iostream>
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
inline char nc() {
    return getchar();
    static char buf[100000], *l = buf, *r = buf;
    return l==r&&(r=(l=buf)+fread(buf,1,100000,stdin),l==r)?EOF:*l++;
}
template<class T> void read(T &x) {
    x = 0; int f = 1, ch = nc();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=nc();}
    while(ch>='0'&&ch<='9'){x=x*10-'0'+ch;ch=nc();}
    x *= f;
}
typedef long long LL;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 50;
int n;
char s[maxn];
int a[maxn];
int solve() {
    n <<= 1;
    for(int i = 1; i <= n; ++i) {
        a[i] = s[i] == 'B';
    }
    for(int i = n; i >= 1; --i) {
        a[i] ^= a[i - 1];
    }
    a[0] = 1;
    for(int i = 1; i <= n; ++i) {
        a[i] ^= a[i - 1] ^ 1;
    }
    int an = 1, cnt = 0;
    for(int i = 1; i <= n; ++i) {
        if(a[i]) ++cnt;
        else {
            if(cnt == 0) return 0;
            an = (LL)an * cnt % mod;
            --cnt;
        }
    }
    if(cnt) return 0;
    n >>= 1;
    for(int i = 1; i <= n; ++i) {
        an = (LL)an * i % mod;
    }
    return an;
}
int main() {
    read(n);
    scanf("%s", s + 1);
    printf("%d\n", solve());
    return 0;
}
