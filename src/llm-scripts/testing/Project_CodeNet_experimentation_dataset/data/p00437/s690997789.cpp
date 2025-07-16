#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <functional>

using namespace std;

#define fst first
#define scd second
#define PB push_back
#define MP make_pair
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define omajinai ios::sync_with_stdio(false);cin.tie(0)
#define rep(i,x) for(int i=0;i<(int)(x);++i)
#define rep1(i,x) for(int i=1;i<=(int)(x);++i)

using ll=long long;
using ld=long double;
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int, int>;
using vpii=vector<pii>;

template<class T,class U>ostream&operator<<(ostream&os,const pair<T,U>p){os<<"("<<p.fst<<", "<<p.scd<<")";return os;}
template<class T>ostream&operator<<(ostream&os,const vector<T>v){rep(i,v.size()){if(i)os<<", ";os<<v[i];}return os;}
template<typename T>T&max(T&a,T&b){if(a>=b)return a;return b;}
template<typename T>T&min(T&a,T&b){if(a < b)return a;return b;}
template<typename T>bool chmax(T&a,T b){if(a < b){a=b;return true;}return false;}
template<typename T>bool chmin(T&a,T b){if(a > b){a=b;return true;}return false;}
int in(){int a;scanf("%d",&a);return a;}
ll lin(){ll a;scanf("%lld",&a);return a;}

constexpr int inf = 1e9;
constexpr ll linf = 3e18;
constexpr double eps = 1e-9;

int ans[301];
int item[1010][3], R[1010];

int main()
{
    while (true) {
        int a = in(), b = in(), c = in();

        if (a == 0) return 0;

        fill_n(ans, a+b+c+1, 2);

        int N = in();

        rep(i, N) {
            rep(j, 3) item[i][j] = in() - 1;
            R[i] = in();

            if (R[i]) {
                rep(j, 3) ans[item[i][j]] = 1;
            }
        }

        rep(i, N) {
            int cnt = 0;
            rep(j, 3) cnt += ans[item[i][j]] == 1;

            if (cnt == 2) {
                rep(j, 3) if (ans[item[i][j]] != 1) ans[item[i][j]] = 0;
            }
        }

        rep(i, a+b+c) printf("%d\n", ans[i]);
    }
}