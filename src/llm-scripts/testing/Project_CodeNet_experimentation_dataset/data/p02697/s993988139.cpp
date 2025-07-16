#include <bits/stdc++.h>

using namespace std;
#define rep(x, n)          for (int x = 0; x < n; x++)
#define REP(x, a, b)       for (int x = a; x <= b; x++)
#define all(container)     (container).begin(), container.end()
#define rall(container)    (container).begin(), container.end()
#define sz(container)      (int) (container).size()

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#ifdef LOCAL_DEFINE
    #include "DEBUG.hpp"
#else
    #define debug(...) 0
#endif
template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

int main(void) {
    int n,m;
    scanf("%d%d",&n,&m);
    if(m&1){
        int end=2*m+1;
        REP(i,m+1,3*m/2+1)
            printf("%d %d\n",i,end-i+m+1);
        end=m;
        REP(i,1,m/2)
            printf("%d %d\n",i,end-i+1);
    }else{
        int end=2*m+1;
        REP(i,m+2,3*m/2+1)
            printf("%d %d\n",i,end-i+m+2);
        end=m+1;
        REP(i,1,m/2)
            printf("%d %d\n",i,end-i+1);
    }
    return 0;
}