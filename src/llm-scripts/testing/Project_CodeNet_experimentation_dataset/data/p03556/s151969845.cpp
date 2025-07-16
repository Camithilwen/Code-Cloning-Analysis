/* 実行時間1s制限の場合10^6 1,000,000 : 余裕をもって間に合う10^7
  10,000,000 : おそらく間に合う10^8 100,000,000 : 非常にシンプルな処理
  でないと厳しい
 */
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#include <bits/stdc++.h>
#define M_PI 3.14159265358979323846
using namespace std;

typedef long long ll; // long longはデータモデル(LLP64, LP64, ...)によらず64bit.
ll gcd(ll a, ll b) {return b ? gcd(b, a%b) : a;}  // Greatest Common Divisor ユークリッドの互除法（aが長辺）
vector<pair<ll,int>> factorize(ll n) {            // a,bの公約数 = GCD(a, b)の約数
    vector<pair<ll,int>> res;
    for (ll i = 2; i*i <= n; i++) { // √nまで探せばよい
        if (n%i) continue;
        res.emplace_back(i, 0);     // 割り切れたら
        while (n%i == 0) {
            n /= i;
            res.back().second++;
        }
    }
    if (n != 1) res.emplace_back(n, 1); // この時点で1でなかったら、残りは素数.
    return res;
}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}         // Least Commont Multiple オーバーフローしないように先に割る
ll ceil(ll a, ll b) {return (a+b-1)/b;}

const ll INF = LONG_MAX;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(int argc, char* argv[])
{
#ifdef LOCAL
    // 以降 cin の入力元が 'xxx.txt' になる
    // std::ifstream in(argv[1]);
    //std::cin.rdbuf(in.rdbuf());
    //std::ifstream in(string(argv[0]) + ".txt");
    std::ifstream in("in.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    int n;
    cin >> n;
    int tmp = sqrt(n);
//    cout << tmp << endl;
    ll ans = 0;
    for (int i = tmp; ; tmp++) {
        ll a = tmp * tmp;
        if (a > n) break;
        ans = a;
    }

    cout << ans;


    return 0;
}

/*
  - 1e9 : 10^9
  - container一般
    - 合計
      accumulate(a.begin(), a.end(), 0LL)  0LLはオーバーフロー用
  - vector
    vector<int> A(N, 0); // 0で初期化(省略可)
    vector<vector<int>> vec(n_rows, vector<int>(n_cols, value));  // 2次元配列初期化
    - loop
      for  (int i = 0; i < A.size(); i++) {}
      for  (int elem : A) {}
    - sort
      std::sort(v.begin(), v.end());  // 昇順
      std::sort(v.begin(), v.end(), std::greater<int>()); //降順
      - vector<vector<int>> cnt(h, vector<int>(w))
    - sort(struct)
        struct st_t {
            string name;
            int p;
            bool operator<(const st_t& another) const {
                if (name == another.name)
                {
                    return p > another.p;
                }
                return name < another.name;
            }
        };
        vector<st_t> st(n);
        sort(st.begin(), st.end());
  - pair
    - pairのソートの定義 : firstが優先的に比較。同じだったらsecond。
    - pair<pair<string,int>,int> p[110];
      std::sort(p,p+a);
        こうすると、first.first -> first.second -> secondの順にソートされる
    - sort
      - sort(a.begin(), cb.end(), greater<pair<int, int>>());
  - map
    - for (auto x : map) {}  // x.first:key  x.second:value.
  - priority_queue<int> q;
    - q.top()に最大値が入っている
  - string
    - loop
      for (char& c : s) {}
 */

