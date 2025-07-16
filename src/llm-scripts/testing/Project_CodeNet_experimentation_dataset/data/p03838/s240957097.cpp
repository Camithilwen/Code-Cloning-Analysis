#include <bits/stdc++.h>
using namespace std;

#define Gene template< class
#define Rics printer& operator,
Gene c> struct rge{c b, e;};
Gene c> rge<c> range(c i, c j){ return {i, j};}
struct printer{
    ~printer(){cerr<<endl;}
    Gene c >Rics(c x){ cerr<<boolalpha<<x; return *this;}
    Rics(string x){cerr<<x;return *this;}
    Gene c, class d >Rics(pair<c, d> x){ return *this,"(",x.first,", ",x.second,")";}
    Gene ... d, Gene ...> class c >Rics(c<d...> x){ return *this, range(begin(x), end(x));}
    Gene c >Rics(rge<c> x){
        *this,"["; for(auto it = x.b; it != x.e; ++it)
            *this,(it==x.b?"":", "),*it; return *this,"]";}
};
#define debug() cerr<<"LINE "<<__LINE__<<" >> ", printer()
#define dbg(x) "[",#x,": ",(x),"] "
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r) {
    return uniform_int_distribution<int>(l, r) (rng);
}


int main() {
//    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long x, y;
    cin >> x >> y;
    long long ans = 1e18;
    for(int mask = 0; mask < 4; mask++) {
        long long cur = x;
        long long moves = 0;
        for(int k = 0; k < 2; k++) {
            if((mask >> k) & 1) {
                cur = -cur;
                moves++;
            }
            if(k == 0) {
                if(cur < y) ans = min(ans, moves + abs(y - cur));
                if(cur < -y) moves += (-y-cur), cur = -y;
            }
            if(k == 1) {
                if(cur == y) {
                    ans = min(ans, moves);
                }
            }
        }
    }
    cout << ans << endl;
}



