// 解き直し.
// https://img.atcoder.jp/cf17-final/editorial.pdf
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using P = pair<LL, LL>;
#define pb push_back
#define a first
#define b second
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
const LL INF = 2020202020;
const int MAX = 5050;
LL dp[MAX][MAX];

int main(){
    
    // 1. 入力情報.
    int N;
    scanf("%d", &N);
    vector<P> v;
    LL h, p;
    v.pb({0, 0});
    rep(i, N){
        scanf("%lld %lld", &h, &p);
        v.pb({h, p});
    }
    rep(i, MAX) rep(j, MAX) dp[i][j] = INF;
    
    // 2. h + p を 小さい順に, sort.
    // ex.
    // 6
    // 1 6
    // 2 5
    // 3 4
    // 4 3
    // 5 2
    // 6 1
    // 
    // -> 以下のようにsortする必要があるはず.
    // h=0 p=0
    // h=6 p=1
    // h=5 p=2
    // h=4 p=3
    // h=3 p=4
    // h=2 p=5
    // h=1 p=6
    // -> この場合, 3人(sort後 の 1番目, 2番目, 3番目, もしくは, sort前 の 6番目, 5番目, 4番目)が座布団を積める.
    sort(v.begin(), v.end(), [](const P &x, const P &y){
        if(x.a + x.b < y.a + y.b)                    return true;
        else if(x.a + x.b == y.a + y.b && x.b < y.b) return true;
        else                                         return false;
    });
    // for(auto &p : v) printf("h=%lld p=%lld\n", p.a, p.b);
    
    // 3. dp更新.
    dp[1][1] = v[1].b;
    repx(i, 2, N + 1){
        repx(j, 1, i + 1){
            if(dp[i - 1][j - 1] > v[i].a) dp[i][j] = dp[i - 1][j];
            else                          dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1] + v[i].b);
        }
    }
    // rep(i, N + 1){
    //     rep(j, N + 1){
    //         printf("%lld ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    
    // 4. 出力.
    int ans = 0;
    rep(i, N + 1) if(dp[N][i] != INF) ans++;
    printf("%d\n", ans);
    return 0;
    
}